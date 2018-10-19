#ifndef CREATEACTORDIALOG_H
#define CREATEACTORDIALOG_H

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

private:
    Ui::CreateActorDialog *ui;
};

#endif // CREATEACTORDIALOG_H
