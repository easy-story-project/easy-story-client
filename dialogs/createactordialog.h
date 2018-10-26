#ifndef CREATEACTORDIALOG_H
#define CREATEACTORDIALOG_H

#include "model/actor.h"

#include <QDialog>

namespace Ui {
class CreateActorDialog;
}

class CreateActorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateActorDialog(QWidget *parent = nullptr);
    ~CreateActorDialog();

signals:
    void createdActor(Actor* actor);

private slots:
    void on_btnRandomName_clicked();

    void on_pushButton_clicked();

private:
    Ui::CreateActorDialog *ui;
};

#endif // CREATEACTORDIALOG_H
