#include "createactordialog.h"
#include "ui_createactordialog.h"

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
