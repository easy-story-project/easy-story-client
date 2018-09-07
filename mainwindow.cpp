#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QTextEdit>
#include <QHBoxLayout>

#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    graphicsView = new QGraphicsView(scene);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(graphicsView);

    QWidget *widget = new QWidget();
    widget->setLayout(layout);

    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupEditor()
{
}

void MainWindow::on_actiontest_triggered()
{
    QFont font("Monaco", 14);
    QGraphicsTextItem* item = scene->addText("fuck", font);
    item->setPos(0, 100);
}
