#ifndef STORYVIEW_H
#define STORYVIEW_H

#include <QGraphicsView>


class StoryView : public QGraphicsView
{
    Q_OBJECT

public:
    StoryView(QWidget* parent = nullptr);

public slots:
    void shuffle();
    void zoomIn();
    void zoomOut();

public:
    void createNode();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *event) override;
#endif
    void drawBackground(QPainter *painter, const QRectF &rect) override;

protected:
    void scaleView(qreal scaleFactor);
};

#endif // STORYVIEW_H
