#include "register.h"
#include "ui_register.h"
#include "user.h"
#include "database.h"
#include <QMessageBox>
#include <QDebug>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui -> comboBox -> addItem("Male");
    ui -> comboBox -> addItem("Female");
}

Register::~Register()
{
    delete ui;
}

void Register::setNamePwd(QString &value1, QString &value2)
{
    name_ = value1;
    pwd_ = value2;
}

void Register::on_buttonBox_accepted()
{
    // get the registering information
    QString name = ui -> lineEdit -> text();
    QString pwd = ui -> lineEdit_2 -> text();
    QString sex = ui -> comboBox -> currentText();
    QString birthday = ui -> dateEdit -> text();

    if (!(name.isEmpty() || pwd.isEmpty()))
    {
        User user(name, pwd, sex, birthday);
        Database *db = Database::getInstance();
        if (!db -> find(name))
        {
            if (db -> insert(user))
            {
                QMessageBox::information(this, "Tips", "Register Successfully!", QMessageBox::Ok);
                emit send(name, pwd);

//                //test
//                if (db->find(name)) {
//                    qDebug() << "Find the name!" << endl;
//                }
//                else
//                {
//                    qDebug() << "Can not find the name!" << endl;
//                }

            }
            else
            {
                 QMessageBox::information(this, "Tips", "Register Failed!", QMessageBox::Ok);
            }
        }
        else
        {
            QMessageBox::information(this, "Warning", "User Name has existed!", QMessageBox::Ok);
        }

    }
    this -> close();

}

void Register::on_buttonBox_rejected()
{
    this -> close();
}
