#ifndef CREATESTORYDIALOG_H
#define CREATESTORYDIALOG_H

#include <QDialog>

namespace Ui {
class CreateStoryDialog;
}

class CreateStoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateStoryDialog(QWidget *parent = nullptr);
    ~CreateStoryDialog();

Q_SIGNALS:
    void sendName(QString name);

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::CreateStoryDialog *ui;
};

#endif // CREATESTORYDIALOG_H
