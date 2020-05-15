#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

    void setNamePwd(QString &value1, QString &value2);

signals:
    void send(QString name, QString pwd);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Register *ui;
    QString name_;
    QString pwd_;
};

#endif // REGISTER_H
