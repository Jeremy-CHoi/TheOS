#include "ram.h"

RAM::RAM(QWidget *parent) : QWidget(parent)
{
    this->resize(380,200);
//    this->setWindowIcon(QIcon(":/Icon.png"));
    this->setWindowTitle("RAM Monitor");
    QPalette palette;
//    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/background.png").scaled(this->size())));
    this->setPalette(palette);

    RAM_label = new QLabel(this);
    RAM_label->setText("RAM Usage");
    RAM_label->resize(120,30);
    RAM_label->setStyleSheet("font-size:14px");
    RAM_label->setGeometry(QRect(20,10,160,30));

    RAM_bar = new QProgressBar(this);
    RAM_bar->setGeometry(QRect(130,10,200,30));
    RAM_bar->setOrientation(Qt::Horizontal);
    RAM_bar->setMinimum(0);
    RAM_bar->setMaximum(6000);//RAM value kb
    RAM_bar->setValue(2589);
    double progress = (RAM_bar->value() - RAM_bar->minimum()) * 100.0 / (RAM_bar->maximum() - RAM_bar->minimum());

    RAM_per = new QLabel(this);
    RAM_per->setText(QString::fromLocal8Bit("present occupied RAM is: %1%").arg(QString::number(progress,'f',1)));
    RAM_per->setGeometry(QRect(140,20,200,30));
    RAM_per->setStyleSheet("font-size:8px");

    CPU_label = new QLabel(this);
    CPU_label->setText("CPU Usage");
    CPU_label->resize(120,30);
    CPU_label->setStyleSheet("font-size:14px");
    CPU_label->setGeometry(QRect(20,40,160,30));

    CPU_bar = new QProgressBar(this);
    CPU_bar->setGeometry(QRect(130,40,200,30));
    CPU_bar->setOrientation(Qt::Horizontal);
    CPU_bar->setMinimum(0);
    CPU_bar->setMaximum(100);
    CPU_bar->setValue(8);
    double progress2 = (CPU_bar->value() - CPU_bar->minimum()) * 100.0 / (CPU_bar->maximum() - CPU_bar->minimum());

    CPU_per = new QLabel(this);
    CPU_per->setText(QString::fromLocal8Bit("present occupied CPU is: %1%").arg(QString::number(progress2,'f',1)));
    CPU_per->setGeometry(QRect(140,50,200,30));
    CPU_per->setStyleSheet("font-size:8px");

    calendar_btn = new QPushButton(this);
    calendar_btn->setIcon(QIcon(":/1.png"));
    calendar_btn->setIconSize(QSize(20,20));
    calendar_btn->setGeometry(QRect(30,100,20,20));
    calendar_btn->setFlat(true);

    calendar_label = new QLabel(this);
    calendar_label->setText("Calendar");
    calendar_label->setStyleSheet("font-size:12px");
    calendar_label->setGeometry(QRect(60,100,120,30));

    chess_btn = new QPushButton(this);
    chess_btn->setIcon(QIcon(":/chess.jpeg"));
    chess_btn->setIconSize(QSize(20,20));
    chess_btn->setGeometry(QRect(200,100,20,20));
    chess_btn->setFlat(true);

    chess_label = new QLabel(this);
    chess_label->setText("Chess");
    chess_label->setStyleSheet("font-size:12px");
    chess_label->setGeometry(QRect(230,100,120,30));

    fishjoy_btn = new QPushButton(this);
    fishjoy_btn->setIcon(QIcon(":/fishjoy.jpg"));
    fishjoy_btn->setIconSize(QSize(20,20));
    fishjoy_btn->setGeometry((QRect(30,150,20,20)));
    fishjoy_btn->setFlat(true);

    fishjoy_label = new QLabel(this);
    fishjoy_label->setText("Fishjoy");
    fishjoy_label->setStyleSheet("font-size:12px");
    fishjoy_label->setGeometry(QRect(60,150,120,30));

    dead_btn = new QPushButton(this);
    dead_btn->setIcon(QIcon(":/dead.jpg"));
    dead_btn->setIconSize(QSize(20,20));
    dead_btn->setGeometry(QRect(200,150,20,20));
    dead_btn->setFlat(true);

    snake_label = new QLabel(this);
    snake_label->setText("Snake");
    snake_label->setStyleSheet("font_size:12px");
    snake_label->setGeometry(QRect(230,150,120,30));

    data1 = new QLabel(this);
    data1->setText("15%");
    data1->setStyleSheet("font-size:12px");
    data1->setGeometry(QRect(130,100,120,30));
    data2 = new QLabel(this);
    data2->setText("23%");
    data2->setStyleSheet("font-size:12px");
    data2->setGeometry(QRect(290,100,120,30));
    data3 = new QLabel(this);
    data3->setText(" - ");
    data3->setStyleSheet("font-size:12px");
    data3->setGeometry(QRect(130,150,120,30));
    data4 = new QLabel(this);
    data4->setText(" - ");
    data4->setStyleSheet("font-size:12px");
    data4->setGeometry(QRect(290,150,120,30));
}
