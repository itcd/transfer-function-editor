#pragma once

#ifndef ControlPoint_H
#define ControlPoint_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QColor>
#include <QMenu>
#include "edge.h"
#include "node.h"
#include "graphwidget.h"

class ControlPoint : public Node
{
public:

	ControlPoint(GraphWidget *graphWidget, QColor &color = QColor(Qt::yellow)) : Node(graphWidget), graph(graphWidget)
	{
		this->color = color;
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
	virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent * event)
	{
		std::cout << "pos " << event->pos().x() << " " << event->pos().y() << std::endl;
		std::cout << "screenPos " << event->screenPos().x() << " " << event->screenPos().y() << std::endl;
		QMenu menu;
		QAction *removeAction = menu.addAction("Remove");
		QAction *markAction = menu.addAction("Mark");
		QAction *selectedAction = menu.exec(event->screenPos());
		// ...
	}

private:
	GraphWidget *graph;
	QColor color;
};

#endif // ControlPoint_H
