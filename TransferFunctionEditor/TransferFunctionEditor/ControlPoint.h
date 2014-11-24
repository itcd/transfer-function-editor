#pragma once

#ifndef ControlPoint_H
#define ControlPoint_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QColor>
#include <QMenu>
#include <QPoint>
#include <iostream>
#include "edge.h"
#include "node.h"
#include "graphwidget.h"

//class TransferFunctionView;
//typedef void(TransferFunctionView::*myfunc)(int);

class ControlPoint : public Node
{
	//Q_OBJECT
public:
	ControlPoint(GraphWidget *graphWidget, int index, QColor &color = QColor(Qt::yellow)) : Node(static_cast<GraphWidget*>(graphWidget))
	{
		this->color = color;
		this->index = index;
	}

	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
	{
		painter->setPen(Qt::NoPen);
		painter->setBrush(Qt::darkGray);
		painter->drawEllipse(-7, -7, 20, 20);

		QRadialGradient gradient(-3, -3, 10);
		if (option->state & QStyle::State_Sunken) {
			gradient.setCenter(3, 3);
			gradient.setFocalPoint(3, 3);
			gradient.setColorAt(1, QColor(color).light(120));
			gradient.setColorAt(0, QColor(color.darker()).light(120));
		}
		else {
			gradient.setColorAt(0, color);
			gradient.setColorAt(1, color.darker());
		}
		painter->setBrush(gradient);

		painter->setPen(QPen(Qt::black, 0));
		painter->drawEllipse(-10, -10, 20, 20);
	}

protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent * event)
	{
		std::cout << "ControlPoint::mousePressEvent" << std::endl;
		Node::mousePressEvent(event);
		if (event->button() == Qt::MouseButton::RightButton)
		{
			{
				auto p = event->screenPos();
				std::cout << "QGraphicsSceneMouseEvent screenPos " << p.x() << "," << p.y() << "\t";
			}
			{
				auto p = event->scenePos();
				std::cout << "scenePos " << p.x() << "," << p.y() << "\t";
			}
			{
				auto p = event->pos();
				std::cout << "pos " << p.x() << "," << p.y() << std::endl;
			}
			{
				auto p = this->scenePos();
				std::cout << "QGraphicsItem scenePos " << p.x() << "," << p.y() << "\t";
			}
			{
				auto p = this->pos();
				std::cout << "pos " << p.x() << "," << p.y() << std::endl;
			}
			graph->removeControlPoint(index);
			event->accept();
		}
	}

	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
	{
		Node::mouseReleaseEvent(event);
		if (!event->isAccepted() && event->button() == Qt::MouseButton::LeftButton)
		{
			auto size = graph->sceneRect();
			auto pos = event->scenePos();
			auto intensity = pos.x() / size.width();
			auto opacity = 1 - pos.y() / size.height();
			graph->moveControlPoint(index, intensity, opacity);
			event->accept();
		}
	}

	//virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent * event)
	//{
	//	QGraphicsItem::contextMenuEvent(event);
	//	//std::cout << "pos " << event->pos().x() << " " << event->pos().y() << std::endl;
	//	//std::cout << "screenPos " << event->screenPos().x() << " " << event->screenPos().y() << std::endl;
	//	QMenu menu;
	//	QAction *removeAction = menu.addAction("Remove");
	//	QAction *changeAction = menu.addAction("Change color");
	//	QAction *optimizeAction = menu.addAction("Optimize for intensity");
	//	QAction *selectedAction = menu.exec(event->screenPos());
	//	event->accept();
	//}

protected:
	//GraphWidget *graph;
	QColor color;
	int index;
};

#endif // ControlPoint_H
