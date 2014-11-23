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

//! [0]
class TransferFunctionView : public GraphWidget
{
    Q_OBJECT

public:
    TransferFunctionView(QWidget *parent = 0) : GraphWidget(parent)
	{
		auto size = this->size();
		auto tfScene = static_cast<QGraphicsScene*>(new TransferFunctionScene(this));
		this->setScene(tfScene);
		std::cout << "TransferFunctionView" << std::endl;
		std::cout << "QGraphicsView size " << size.width() << " " << size.height() << std::endl;
		scene()->setSceneRect(0, 0, size.width(), size.height());
		QRectF rect = this->sceneRect();
		std::cout << "Scene Rect " << rect.left() << " " << rect.top()<<" "<<rect.width()<<" "<<rect.height() << std::endl;
		scene()->clear();
		std::cout <<"tfScene "<< tfScene << std::endl;
		std::cout <<"scene() "<< scene() << std::endl;
	}

	void setTransferFunction(int numIntensities, std::vector<glm::vec4> colors, std::vector<float> intensities)
	{
		this->numIntensities = numIntensities;
		this->colors = colors;
		this->intensities = intensities;
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
		std::cout << "removeControlPoint" << std::endl;
		colors.erase(colors.begin() + index);
		intensities.erase(intensities.begin() + index);
		numIntensities = intensities.size();
		drawTransferFunction();
	}

protected:
	virtual void resizeEvent(QResizeEvent * event)
	{
		auto size = event->size();
		std::cout << "resizeEvent" << std::endl;
		std::cout << "QGraphicsView size " << size.width() << " " << size.height() << std::endl;
		scene()->setSceneRect(0, 0, size.width(), size.height());
		QRectF rect = this->sceneRect();
		std::cout << "Scene Rect " << rect.left() << " " << rect.top() << " " << rect.width() << " " << rect.height() << std::endl;
		drawTransferFunction();
	}

	virtual void drawBackground(QPainter *painter, const QRectF &rect)
	{
		//Q_UNUSED(rect);

		//// Shadow
		QRectF sceneRect = this->sceneRect();
		//QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
		//QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
		//if (rightShadow.intersects(rect) || rightShadow.contains(rect))
		//	painter->fillRect(rightShadow, Qt::darkGray);
		//if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
		//	painter->fillRect(bottomShadow, Qt::darkGray);

		//// Fill
		//QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
		//gradient.setColorAt(0, Qt::white);
		//gradient.setColorAt(1, Qt::lightGray);
		//painter->fillRect(rect.intersected(sceneRect), gradient);
		//painter->setBrush(Qt::NoBrush);
		painter->drawRect(sceneRect);
		std::cout << "drawBackground sceneRect " << sceneRect.left() << " " << sceneRect.top() << " " << sceneRect.width() << " " << sceneRect.height() << std::endl;
	}

	virtual void timerEvent(QTimerEvent *event){}

private:
	int numIntensities;
	std::vector<glm::vec4> colors;
	std::vector<float> intensities;
};
//! [0]

#endif // TransferFunctionView_H
