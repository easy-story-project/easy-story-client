#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QTextEdit>
#include <QHBoxLayout>

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
