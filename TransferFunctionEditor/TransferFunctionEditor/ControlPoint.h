#pragma once

#ifndef ControlPoint_H
#define ControlPoint_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QColor>
#include <QMenu>
#include <Qt>
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
	ControlPoint(GraphWidget *graphWidget, int index, QColor &color = QColor(Qt::yellow)) : Node(static_cast<GraphWidget*>(graphWidget)), graph(graphWidget)
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
		if (event->button() == Qt::MouseButton::RightButton)
		{
			std::cout << "mousePressEvent RightButton" << std::endl;
			graph->removeControlPoint(index);
		}
	}

	virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent * event)
	{
		QGraphicsItem::contextMenuEvent(event);
		//std::cout << "pos " << event->pos().x() << " " << event->pos().y() << std::endl;
		//std::cout << "screenPos " << event->screenPos().x() << " " << event->screenPos().y() << std::endl;
		//QMenu menu;
		//QAction *removeAction = menu.addAction("Remove");
		//QAction *markAction = menu.addAction("Mark");
		//QAction *selectedAction = menu.exec(event->screenPos());
	}

private:
	GraphWidget *graph;
	QColor color;
	int index;
};

#endif // ControlPoint_H
