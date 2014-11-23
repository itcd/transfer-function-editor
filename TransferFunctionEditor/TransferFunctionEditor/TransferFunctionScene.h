#pragma once

#ifndef TransferFunctionScene_H
#define TransferFunctionScene_H

#include <QMenu>
#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>

class TransferFunctionScene : public QGraphicsScene
{
public:
	TransferFunctionScene(QGraphicsView * parent = 0) : QGraphicsScene(parent)
	{
	}

	TransferFunctionScene(const QRectF & sceneRect, QObject * parent = 0) : QGraphicsScene(sceneRect, parent)
	{}

protected:
	virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent * event)
	{
		std::cout << "pos " << event->pos().x() << " " << event->pos().y() << std::endl;
		std::cout << "screenPos " << event->screenPos().x() << " " << event->screenPos().y() << std::endl;
		auto view = static_cast<QGraphicsView*>(this->parent());
		auto p = view->mapFromGlobal(event->screenPos());
		std::cout << "mapFromGlobal " << p.x() << " " << p.y() << std::endl;
		auto p2 = view->transform().map(p);
		std::cout << "transform().map " << p2.x() << " " << p2.y() << std::endl;
		QGraphicsScene::contextMenuEvent(event);
		if (!event->isAccepted())
		{
			QMenu menu;
			QAction *addAction = menu.addAction("Add control point");
			QAction *selectedAction = menu.exec(event->screenPos());
		}
	}
};

#endif // TransferFunctionScene_H
