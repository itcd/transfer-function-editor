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
	//virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent * event)
	//{
	//	QGraphicsScene::contextMenuEvent(event);
	//	//std::cout << "pos " << event->pos().x() << " " << event->pos().y() << std::endl;
	//	//std::cout << "screenPos " << event->screenPos().x() << " " << event->screenPos().y() << std::endl;
	//	//auto view = static_cast<QGraphicsView*>(this->parent());
	//	//auto p = view->mapFromGlobal(event->screenPos());
	//	//std::cout << "mapFromGlobal " << p.x() << " " << p.y() << std::endl;
	//	//auto p2 = view->transform().map(p);
	//	//std::cout << "transform().map " << p2.x() << " " << p2.y() << std::endl;
	//	if (!event->isAccepted())
	//	{
	//		QMenu menu;
	//		QAction *addAction = menu.addAction("Add control point");
	//		QAction *selectedAction = menu.exec(event->screenPos());
	//		event->accept();
	//	}
	//}

	virtual void mousePressEvent(QGraphicsSceneMouseEvent * event)
	{
		std::cout << "TransferFunctionScene::mousePressEvent" << std::endl;
		QGraphicsScene::mousePressEvent(event);
		if (!event->isAccepted() && event->button() == Qt::MouseButton::LeftButton)
		{
			{
				auto p = event->screenPos();
				std::cout << "QGraphicsSceneMouseEvent screenPos " << p.x() << "," << p.y() << std::endl;
			}
			{
				auto p = event->scenePos();
				std::cout << "scenePos " << p.x() << "," << p.y() << "\t";
			}
			{
				auto p = event->pos();
				std::cout << "pos " << p.x() << "," << p.y() << std::endl;
			}
			auto graph = static_cast<GraphWidget*>(this->parent());
			auto size = graph->sceneRect();
			auto pos = event->scenePos();
			std::cout << "scene size " << size.width() << " " << size.height() << "\t";
			std::cout << "scenePos " << pos.x() << " " << pos.y() << std::endl;
			auto intensity = pos.x() / size.width();
			auto opacity = 1 - pos.y() / size.height();
			std::cout << "intensity=" << intensity << " opacity=" << opacity << std::endl;
			graph->addControlPoint(intensity, opacity);
			event->accept();
		}
	}
};

#endif // TransferFunctionScene_H
