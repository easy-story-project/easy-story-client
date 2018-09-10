#ifndef STORYNODE_H
#define STORYNODE_H

#include <QGraphicsItem>
#include <QGraphicsView>



class StoryNode : public QGraphicsItem
{
public:
    StoryNode(QGraphicsView* parent);

public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QGraphicsView* parentView;
};

#endif // STORYNODE_H
