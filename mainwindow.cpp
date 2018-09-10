#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QTextEdit>
#include <QHBoxLayout>

#include <QGraphicsTextItem>
#include <qevent.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QSize size = event->size();
    ui->graphicsView->setGeometry(0, 0, size.width(), size.height());
}

void MainWindow::setupEditor()
{

}

void MainWindow::on_btnCreateStory_clicked()
{
    ui->graphicsView->createNode();
}
