#include "management.h"

Management::Management(QWidget *parent) : QWidget(parent)
{
    this->resize(450,138);
//    this->setWindowIcon(QIcon(":/rom_back.png"));
    this->setWindowTitle("Management");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/management_back.png").scaled(this->size())));
    this->setPalette(palette);

    text1 = new QLabel(this);
    text1->setText("Applications:");
    text1->setGeometry(30,2,90,20);

    text2_1 = new QLabel(this);
    text2_1->setText("Calendar");
    text2_1->setGeometry(75,30,90,20);
    text2_1->hide();

    text2_2 = new QLabel(this);
    text2_2->setText("102MB");
    text2_2->setGeometry(180,30,90,20);
    text2_2->hide();

    text3_1 = new QLabel(this);
    text3_1->setText("Map");
    text3_1->setGeometry(75,50,90,20);
    text3_1->hide();

    text3_2 = new QLabel(this);
    text3_2->setText("205MB");
    text3_2->setGeometry(180,50,90,20);
    text3_2->hide();

    text4_1 = new QLabel(this);
    text4_1->setText("Snake");
    text4_1->setGeometry(75,70,90,20);
    text4_1->hide();

    text4_2 = new QLabel(this);
    text4_2->setText("153.6MB");
    text4_2->setGeometry(180,70,90,20);
    text4_2->hide();

    text9_1 = new QLabel(this);
    text9_1->setText("Chinese Chess");
    text9_1->setGeometry(75,50,90,20);
    text9_1->hide();

    text9_2 = new QLabel(this);
    text9_2->setText("368.64MB");
    text9_2->setGeometry(180,50,90,20);
    text9_2->hide();

    text8_1 = new QLabel(this);
    text8_1->setText("Fish");
    text8_1->setGeometry(75,90,90,20);
    text8_1->hide();

    text8_2 = new QLabel(this);
    text8_2->setText("430.08MB");
    text8_2->setGeometry(180,90,90,20);
    text8_2->hide();

 //System Memory
    text7_1 = new QLabel(this);
    text7_1->setText("File System");
    text7_1->setGeometry(275,50,90,20);

    text7_2 = new QLabel(this);
    text7_2->setText("26MB");
    text7_2->setGeometry(380,50,90,20);

    text5 = new QLabel(this);
    text5->setText("System Memory:");
    text5->setGeometry(240,2,130,20);

    text6_1 = new QLabel(this);
    text6_1->setText("Monitor");
    text6_1->setGeometry(275,30,90,20);

    text6_2 = new QLabel(this);
    text6_2->setText("18MB");
    text6_2->setGeometry(380,30,90,20);
}
