#include "createstorydialog.h"
#include "ui_createstorydialog.h"

CreateStoryDialog::CreateStoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateStoryDialog)
{
    ui->setupUi(this);
}

CreateStoryDialog::~CreateStoryDialog()
{
    delete ui;
}

void CreateStoryDialog::on_okButton_clicked()
{
    emit sendName(ui->storyName->text());
    hide();
}

void CreateStoryDialog::on_cancelButton_clicked()
{
    exit(0);
}
