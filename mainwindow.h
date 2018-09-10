#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "editor/storyview.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void resizeEvent(QResizeEvent *event) override;

private:
    void setupEditor();

private slots:
    void on_btnCreateStory_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;

};

#endif // MAINWINDOW_H
