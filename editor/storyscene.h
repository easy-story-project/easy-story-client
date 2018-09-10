#ifndef STORYSCENE_H
#define STORYSCENE_H

#include <QGraphicsScene>


class StoryScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit StoryScene(QObject* parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
};

#endif // STORYSCENE_H
