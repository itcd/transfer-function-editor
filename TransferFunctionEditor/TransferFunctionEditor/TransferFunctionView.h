#pragma once

#ifndef TransferFunctionView_H
#define TransferFunctionView_H

#include <iostream>
#include <QResizeEvent>
#include <QMenu>
#include <QSharedPointer>
#include <glm/glm.hpp>
#include "graphwidget.h"
#include "node.h"
#include "ControlPoint.h"
#include "ControlEdge.h"
#include "TransferFunctionScene.h"

//class ControlPoint;
//class ControlEdge;

//! [0];
class TransferFunctionView : public GraphWidget
{
    Q_OBJECT

public:
    TransferFunctionView(QWidget *parent = 0) : GraphWidget(parent)
	{
		auto size = this->size();
		auto tfScene = static_cast<QGraphicsScene*>(new TransferFunctionScene(this));
		this->setScene(tfScene);
		std::cout << "TransferFunctionView size " << size.width() << " " << size.height() << "\t";
		scene()->setSceneRect(0, 0, size.width(), size.height());
		QRectF rect = this->sceneRect();
		std::cout << "sceneRect " << rect.left() << " " << rect.top()<<" "<<rect.width()<<" "<<rect.height() << std::endl;
		scene()->clear();
	}

	void setTransferFunction(int numIntensities, std::vector<glm::vec4> colors, std::vector<float> intensities)
	{
		this->numIntensities = numIntensities;
		this->colors = colors;
		this->intensities = intensities;
	}

	void getTransferFunction(int &numIntensities, std::vector<glm::vec4> &colors, std::vector<float> &intensities)
	{
		numIntensities = this->numIntensities;
		colors = this->colors;
		intensities = this->intensities;
	}

	void drawTransferFunction()
	{
		auto size = this->size();
		scene()->clear();
		ControlPoint *node0 = NULL;
		for (int i=0; i<numIntensities; i++)
		{
			auto c = colors[i];
			auto node1 = new ControlPoint(this, i, QColor(int(c.r * 255), int(c.g * 255), int(c.b * 255)));
			scene()->addItem(node1);
			node1->setPos(intensities[i] * size.width(), (1 - c.a) * size.height());
			if (i>=1)
			{
				scene()->addItem(new ControlEdge(static_cast<Node*>(node0), static_cast<Node*>(node1)));
			}
			node0 = node1;
		}
	}

	virtual void removeControlPoint(int index)
	{
		std::cout << "removeControlPoint size before " << numIntensities << " after";
		colors.erase(colors.begin() + index);
		intensities.erase(intensities.begin() + index);
		numIntensities = intensities.size();
		drawTransferFunction();
		std::cout << numIntensities << std::endl;
	}

	virtual void moveControlPoint(int index, double intensity, double opacity)
	{
		intensity = intensity < 0 ? 0 : intensity;
		intensity = intensity > 1 ? 1 : intensity;
		opacity = opacity < 0 ? 0 : opacity;
		opacity = opacity > 1 ? 1 : opacity;
		intensities[index] = intensity;
		colors[index].a = opacity;
		for (int i = 0; i < intensities.size(); i++)
		{
			if (i < index && intensities[index] < intensities[i])
			{
				intensities[i] = intensities[index];
			}
			if (i > index && intensities[index] > intensities[i])
			{
				intensities[i] = intensities[index];
			}
		}
		drawTransferFunction();
	}

	virtual void addControlPoint(double intensity, double opacity)
	{
		intensity = intensity < 0 ? 0 : intensity;
		intensity = intensity > 1 ? 1 : intensity;
		opacity = opacity < 0 ? 0 : opacity;
		opacity = opacity > 1 ? 1 : opacity;
		auto size = intensities.size();
		int i = 0;
		while (i < size && intensities[i] < intensity)
		{
			i++;
		}
		if (i == 0)
		{
			intensities.insert(intensities.begin(), intensity);
			auto c = glm::vec4(colors[0].r, colors[0].g, colors[0].b, opacity);
			colors.insert(colors.begin(), c);
		} 
		else
		{
			if (i >= size)
			{
				if (i > size)
				{
					std::cout << "Error: index out of range. i=" << i << " size=" << size << std::endl;
				}
				intensities.push_back(intensity);
				auto c = glm::vec4(colors[size - 1].r, colors[size - 1].g, colors[size - 1].b, opacity);
				colors.push_back(c);
			}
			else
			{
				auto c0 = colors[i - 1];
				auto c1 = colors[i];
				auto intensity0 = intensities[i - 1];
				auto intensity1 = intensities[i];
				auto fraction = (intensity - intensity0) / (intensity1 - intensity0);
				auto r = c0.r + (c1.r - c0.r) * fraction;
				auto g = c0.g + (c1.g - c0.g) * fraction;
				auto b = c0.b + (c1.b - c0.b) * fraction;
				auto c = glm::vec4(r, g, b, opacity);
				intensities.insert(intensities.begin() + i, intensity);
				colors.insert(colors.begin() + i, c);
			}
		}
		numIntensities = intensities.size();
		drawTransferFunction();
	}

	virtual void setSelectedIndex(int index)
	{
		this->selectedIndex = index;
	}

	virtual void optimizeForIntensity(int index)
	{
		// optimize for selected intensity
	}

	virtual void changeControlPointColor(int index, QColor color)
	{
		glm::vec4 c(color.red() / 255.f, color.green() / 255.f, color.blue() / 255.f, colors[index].a);
		colors[index] = c;
		drawTransferFunction();
	}

	int getSelectedIndex()
	{
		return selectedIndex;
	}

	void distributeVertically()
	{
		auto size = colors.size();
		double min = 1, max = 0;
		for (int i = 0; i < size; i++)
		{
			if (colors[i].a < min)
			{
				min = colors[i].a;
			}
			if (colors[i].a > max)
			{
				max = colors[i].a;
			}
		}
		double range = max - min;
		double interval = range / (size - 1);
		for (int i = 0; i < size; i++)
		{
			colors[i].a = min + i * interval;
		}
		drawTransferFunction();
	}

	void distrubuteHorizontally()
	{
		auto size = intensities.size();
		double range = intensities[size - 1] - intensities[0];
		double interval = range / (size - 1);
		for (int i = 0; i < size; i++)
		{
			intensities[i] = intensities[0] + i * interval;
		}
		drawTransferFunction();
	}

	void makeRamp()
	{
		auto size = colors.size();
		for (int i = 0; i < size; i++)
		{
			colors[i].a = intensities[i];
		}
		drawTransferFunction();
	}

	void makeLevel()
	{
		auto size = colors.size();
		double interval = 1.0 / size;
		for (int i = 0; i < size; i++)
		{
			colors[i].a = interval;
		}
		drawTransferFunction();
	}

protected:
	virtual void resizeEvent(QResizeEvent * event)
	{
		auto size = event->size();
		std::cout << "TransferFunctionView::resizeEvent size " << size.width() << " " << size.height() << "\t";
		scene()->setSceneRect(0, 0, size.width(), size.height());
		QRectF rect = this->sceneRect();
		std::cout << "sceneRect " << rect.left() << " " << rect.top() << " " << rect.width() << " " << rect.height() << std::endl;
		drawTransferFunction();
	}

	virtual void drawBackground(QPainter *painter, const QRectF &rect)
	{
		QRectF sceneRect = this->sceneRect();
		painter->drawRect(sceneRect);
	}

	virtual void timerEvent(QTimerEvent *event){}

protected:
	int numIntensities;
	std::vector<glm::vec4> colors;
	std::vector<float> intensities;
	int selectedIndex;
};
//! [0]

#endif // TransferFunctionView_H
