#include "calendar.h"

Calendar::Calendar(QWidget *parent) : QWidget(parent)
{
    this->resize(450,300);
//    this->setWindowIcon(QIcon(":/rom_back.png"));
    this->setWindowTitle("Calendar");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/management_back.png").scaled(this->size())));
    this->setPalette(palette);

    cal = new QPushButton(this);
    cal->setIcon(QIcon(":/calendar_back.png"));
    cal->setIconSize(QSize(375,216));
    cal->setGeometry(QRect(40,40,375,216));
    cal->setFlat(true);
//    App_map->hide();
}
