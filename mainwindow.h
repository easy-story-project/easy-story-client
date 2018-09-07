#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupEditor();

private:
    Ui::MainWindow *ui;
    QGraphicsView* graphicsView;
    QGraphicsScene* scene;
};

#endif // MAINWINDOW_H
