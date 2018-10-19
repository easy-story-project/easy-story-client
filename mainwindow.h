#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "editor/storyview.h"
#include "dialogs/createstorydialog.h"
#include "dialogs/createactordialog.h"
#include "model/story.h"

#include <QMainWindow>
#include <QSettings>

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
    void loadSetting();
    void createStory();
    int grabChineseCount(QString str);

    void createActions();

private slots:
    void textChanged();
    void receiveStoryName(QString name);
    void createActor();

private:
    Ui::MainWindow *ui;
    QString settingPath;
    CreateStoryDialog* createStoryDlg;
    CreateActorDialog* createActorDlg;
    Story* story;

    QSettings* pSetting;
};

#endif // MAINWINDOW_H
