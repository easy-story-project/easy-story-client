#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "define.h"
#include "databases/database.h"

#include <QLabel>
#include <QTextEdit>
#include <QHBoxLayout>

#include <QGraphicsTextItem>
#include <qevent.h>
#include <QtDebug>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QDateTime>
#include <QDir>
#include <QSettings>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    createStoryDlg(new CreateStoryDialog()),
    createActorDlg(new CreateActorDialog()),
    story(nullptr),
    setting(nullptr)
{
    ui->setupUi(this);
    createActions();
    setupEditor();
    loadSetting();
    createStory();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupEditor()
{
    connect(ui->editor, &QPlainTextEdit::textChanged, this, &MainWindow::textChanged);
    connect(createStoryDlg, &CreateStoryDialog::sendName, this, &MainWindow::receiveStoryName);
    connect(createActorDlg, &CreateActorDialog::createdActor, this, &MainWindow::createdActor);
    connect(Database::get(), &Database::signalDBInitBegin, this, &MainWindow::slotDBInitBegin);
    connect(Database::get(), &Database::signalDBInitDone, this, &MainWindow::slotDBInitDone);
}

void MainWindow::createActions()
{
    const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/res/images/createActor.png"));
    QAction *actCreateActor = new QAction(newIcon, tr("&创建角色"), this);
    actCreateActor->setShortcuts(QKeySequence::New);
    actCreateActor->setStatusTip(tr("Create new actor"));
    connect(actCreateActor, &QAction::triggered, this, &MainWindow::createActor);
    ui->mainToolBar->addAction(actCreateActor);

    ui->mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

void MainWindow::loadSetting()
{
    settingPath = QDir::currentPath() + "/setting.ini";
    QFile file(settingPath);

    if (!file.exists()) {
        file.open(QIODevice::ReadWrite);
        file.close();
    }

    setting = new QSettings(settingPath, QSettings::IniFormat);
}

void MainWindow::createStory()
{
    if (setting->contains(BASE_PROJECT_UUID)) {
        QString name = setting->value(BASE_PROJECT_NAME).toString();
        QString uuid = setting->value(BASE_PROJECT_UUID).toString();
        story = Story::load(uuid, name);

//        for (Actor* actor : story->actors) {
//        }
    } else {
        createStoryDlg->show();
    }
}

void MainWindow::receiveStoryName(QString name)
{
    story = Story::create(name);
    setting->setValue(BASE_PROJECT_NAME, story->getName());
    setting->setValue(BASE_PROJECT_UUID, story->getUUID());
}

void MainWindow::createActor()
{
    createActorDlg->show();
}

void MainWindow::slotDBInitBegin()
{

}

void MainWindow::slotDBInitDone(QString table)
{
    setting->setValue(SQL_SETUP + table, true);
}

void MainWindow::createdActor(Actor *actor)
{
    story->addActor(actor);
    story->save();
}

void MainWindow::textChanged()
{
    QTextDocument* doc = ui->editor->document();
    QString html = doc->toPlainText();
    int count = grabChineseCount(html);
    ui->labelCount->setText(QString().sprintf("%d Word", count));
}


int MainWindow::grabChineseCount(QString str) {
    str = str.replace('\n', "");
    str = str.trimmed();
    QRegExp rx = QRegExp("[\\x4e00-\\x9fa5]+");

    int count = 0;
    int lo = 0;
    int hi = str.count() - 1;

    while (lo <= hi) {
        QString startStr = str.at(lo++);
        QString endStr = str.at(hi--);

        if (startStr.contains(rx)) count++;
        if (endStr.contains(rx)) count++;
    }

    return count;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QSize size = event->size();
    ui->gridLayoutWidget->setGeometry(QRect(QPoint(), size));
}
