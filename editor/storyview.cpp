#include "storyview.h"
#include "storynode.h"
#include "storyscene.h"

#include <QRandomGenerator>
#include <math.h>
#include <QKeyEvent>

StoryView::StoryView(QWidget* parent) : QGraphicsView (parent)
{
    StoryScene* scene = new StoryScene(this);
    scene->setSceneRect(0, 0, 1000, 800);
    setScene(scene);
}

void StoryView::shuffle()
{
}

void StoryView::zoomIn()
{
    scaleView(qreal(1.2));
}

void StoryView::zoomOut()
{
    scaleView(1 / qreal(1.2));
}

void StoryView::createNode()
{
    StoryScene* scene = static_cast<StoryScene*>(this->scene());
    StoryNode* node = new StoryNode(nullptr);

    QList<QGraphicsItem*> items = scene->items();
    if (items.empty()) {
        node->setPos(10, 10);
    } else {
        QGraphicsItem* latest = items.at(0);
        QPointF pos = latest->pos();
        node->setPos(10, pos.y() + 50);
    }

    scene->addItem(node);
}

void StoryView::keyPressEvent(QKeyEvent *event)
{

}

void StoryView::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

}

void StoryView::drawBackground(QPainter *painter, const QRectF &rect)
{
    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
        painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
        painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);

    // Text
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                    sceneRect.width() - 4, sceneRect.height() - 4);
    QString message(tr("Click and drag the nodes around, and zoom with the mouse "
                       "wheel or the '+' and '-' keys"));

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
    painter->setPen(Qt::lightGray);
    painter->drawText(textRect.translated(2, 2), message);
    painter->setPen(Qt::black);
    painter->drawText(textRect, message);
}

#if QT_CONFIG(wheelevent)
//! [5]
void StoryView::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}
//! [5]
#endif

void StoryView::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}
