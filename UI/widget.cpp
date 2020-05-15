#include "widget.h"
#include "database.h"
#include "mainwindow.h"
#include "register.h"
#include <QMessageBox>
#include <QSplashScreen>
#include <QPixmap>
#include <QElapsedTimer>
#include <QMovie>
#include <Windows.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->showFrom();
    this->retranslateUi();

    QObject::connect(pushButton,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    QObject::connect(pushButton_2,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_2_clicked()));

}

Widget::~Widget()
{

}
//呈现窗体部件
void Widget::showFrom()
{
    if (this->objectName().isEmpty())
        this->setObjectName(QStringLiteral("MainWindow"));
    this->setWindowModality(Qt::NonModal);
    this->resize(535, 357);
    this->setContextMenuPolicy(Qt::ActionsContextMenu);
    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    verticalSpacer = new QSpacerItem(20, 55, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

    verticalSpacer_3 = new QSpacerItem(20, 55, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_3, 1, 2, 1, 1);

    horizontalSpacer_3 = new QSpacerItem(98, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer_3, 2, 0, 1, 1);

    horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(6);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    label = new QLabel(this);
    label->setObjectName(QStringLiteral("label"));

    horizontalLayout->addWidget(label);

    lineEdit = new QLineEdit(this);
    lineEdit->setObjectName(QStringLiteral("lineEdit"));

    horizontalLayout->addWidget(lineEdit);


    verticalLayout->addLayout(horizontalLayout);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setSpacing(6);
    horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
    label_2 = new QLabel(this);
    label_2->setObjectName(QStringLiteral("label_2"));

    horizontalLayout_2->addWidget(label_2);

    lineEdit_2 = new QLineEdit(this);
    lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
    lineEdit_2->setEchoMode(QLineEdit::Normal);

    horizontalLayout_2->addWidget(lineEdit_2);


    verticalLayout->addLayout(horizontalLayout_2);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setSpacing(6);
    horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
    pushButton = new QPushButton(this);
    pushButton->setObjectName(QStringLiteral("pushButton"));

    horizontalLayout_3->addWidget(pushButton);

    pushButton_2 = new QPushButton(this);
    pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

    horizontalLayout_3->addWidget(pushButton_2);


    verticalLayout->addLayout(horizontalLayout_3);


    gridLayout->addLayout(verticalLayout, 2, 2, 1, 1);

    horizontalSpacer_2 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

    horizontalSpacer_4 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer_4, 2, 4, 1, 1);

    verticalSpacer_2 = new QSpacerItem(20, 55, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_2, 3, 2, 1, 1);

    verticalSpacer_4 = new QSpacerItem(20, 55, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout->addItem(verticalSpacer_4, 4, 2, 1, 1);


    QWidget::setTabOrder(lineEdit, lineEdit_2);
    QWidget::setTabOrder(lineEdit_2, pushButton);
    QWidget::setTabOrder(pushButton, pushButton_2);

    //retranslateUi(MainWindow);

    //QMetaObject::connectSlotsByName(MainWindow);
}
void Widget::retranslateUi()
{
    this->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
    label->setText(QApplication::translate("MainWindow", "\350\264\246\345\217\267;", Q_NULLPTR));
    label_2->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201;", Q_NULLPTR));
    pushButton->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
    pushButton_2->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210", Q_NULLPTR));
    lineEdit_2->setEchoMode(QLineEdit::Password);
}


//void Widget::on_pushButton_2_clicked()
//{
//    this->close();
//}

//登录功能
void Widget::on_pushButton_clicked()
{
//    QString zh=lineEdit->text();
//    QString mm=lineEdit_2->text();
//    if(zh==mm)
//    {
//        qDebug()<<"登陆成功"<<endl;
//    }
//    else
//    {
//        qDebug()<<"登陆失败"<<endl;
//    }

    // get the name and password inputted by user
    QString name = lineEdit -> text();
    QString pwd = lineEdit_2 -> text();

    if (!(name.isEmpty() || pwd.isEmpty()))
    {
        Database *db = Database::getInstance();
//        bool existUser = db -> find(name);
//        if (existUser)
        if (db -> find(name))
        {
//            bool passed = db -> judge(name, pwd);
//            if (passed)
            if (db -> judge(name, pwd))
            {
                MainWindow *m = new MainWindow();

                // makes Qt delete this widget when the widget has accepted the close event
                m -> setAttribute(Qt::WA_DeleteOnClose);


                QPixmap pixmap(":/images/splash.gif");
                QSplashScreen splash(pixmap);
                QLabel splashLabel(&splash);
                QMovie splashGif(":/images/splash.gif");
                splashLabel.setMovie(&splashGif);
                splashGif.start();
                splash.show();
                splash.setCursor(Qt::BlankCursor);
                for (int i = 0; i < 15000; i += splashGif.speed())
                {
                    QCoreApplication::processEvents();
                    Sleep(splashGif.speed() / 5);
                }


//                QPixmap pixmap(":/images/background.jpg"); //需要换开机动画图片
//                QSplashScreen *splash = new QSplashScreen(pixmap);
//                this -> close();
//                splash -> show();

//                QElapsedTimer timer;
//                Qt::Alignment topRight = Qt::AlignHCenter | Qt::AlignBottom;
//                timer.start();
//                while (timer.elapsed() <= 1) {
//                    splash -> showMessage(QObject::tr("Starting the main interface..."), topRight, Qt::black);
//                }
//                while (timer.elapsed() <= 2.5) {
//                    splash -> showMessage(QObject::tr("Loading..."), topRight, Qt::black);
//                }
//                while (timer.elapsed() <= 4) {
//                    splash -> showMessage(QObject::tr("Welcome xxx..."), topRight, Qt::black);
//                }

//                splash -> finish(m);
//                delete splash;


                // goal: translate the username to mainwindow/splashscreen
//                connect(this, SIGNAL(sendUserName(QString)), );
//                emit sendUserName(name);


                m -> show();
            }
            else
            {
                // wrong user name or wrong password
                QMessageBox::information(this, "Warning", "Login Failed! Name or Password Error!", QMessageBox::Ok);
            }
        }
        else
        {
            QMessageBox::information(this, "Warning", "Login Failed! Please Register First!", QMessageBox::Ok);
        }
    }
}


//注册功能
void Widget::on_pushButton_2_clicked()
{
    Register rgt;
    connect(&rgt, SIGNAL(send(QString, QString)), this, SLOT(receive(QString, QString)));
    rgt.exec();
}

void Widget::receive(QString name, QString pwd)
{
    lineEdit -> setText(name);
    lineEdit_2 -> setText(pwd);
}


