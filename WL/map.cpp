#include "map.h"

Map::Map(QWidget *parent) : QWidget(parent)
{
    this->resize(450,550);
//    this->setWindowIcon(QIcon(":/rom_back.png"));
    this->setWindowTitle("Calendar");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/management_back.png").scaled(this->size())));
    this->setPalette(palette);

    map = new QPushButton(this);
    map->setIcon(QIcon(":/map_back.png"));
    map->setIconSize(QSize(247,450));
    map->setGeometry(QRect(70,40,247,450));
    map->setFlat(true);
//    App_map->hide();
}
