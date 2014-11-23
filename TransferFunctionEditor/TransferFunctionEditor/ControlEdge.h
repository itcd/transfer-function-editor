#pragma once

#ifndef ControlEdge_H
#define ControlEdge_H

#include <math.h>
#include <QPainter>
#include <QGraphicsItem>

#include "edge.h"
#include "node.h"

class ControlEdge : public Edge
{
public:

	ControlEdge(Node *sourceNode, Node *destNode) : Edge(sourceNode, destNode)
	{
	}

	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
	{
		if (!source || !dest)
			return;

		QLineF line(sourcePoint, destPoint);
		if (qFuzzyCompare(line.length(), qreal(0.)))
			return;

		// Draw the line itself
		painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
		painter->drawLine(line);
	}
};

#endif // ControlEdge_H
