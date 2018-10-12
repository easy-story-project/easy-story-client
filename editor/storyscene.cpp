#include "storyscene.h"

#include <QGraphicsSceneMouseEvent>
#include <QDebug>

StoryScene::StoryScene(QObject* parent) : QGraphicsScene(parent)
{

}

void StoryScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() == Qt::MouseButton::RightButton) {
        QPointF pos = mouseEvent->pos();
        qInfo() << "Press " << "x:" << pos.x() << " y:" << pos.y() << " " << time(nullptr);
    }

    QGraphicsScene::mousePressEvent(mouseEvent);
}

void StoryScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QPointF pos = mouseEvent->pos();
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void StoryScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
