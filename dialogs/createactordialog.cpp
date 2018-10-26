#include "createactordialog.h"
#include "ui_createactordialog.h"
#include "model/chinesenamebuilder.h"


CreateActorDialog::CreateActorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateActorDialog)
{
    ui->setupUi(this);
}

CreateActorDialog::~CreateActorDialog()
{
    delete ui;
}

void CreateActorDialog::on_btnRandomName_clicked()
{
    bool isMan = ui->cbMan->isChecked();
    ChineseNameBuilder builder(isMan);
    QString name = builder.build();
    ui->editName->setText(name);
}

void CreateActorDialog::on_pushButton_clicked()
{
    Actor* actor = new Actor();
    actor->name = ui->editName->text();
    actor->boy = ui->cbMan->isChecked();
    actor->lead = ui->cbLead->isChecked();

    hide();
    emit createdActor(actor);
    delete this;


}
