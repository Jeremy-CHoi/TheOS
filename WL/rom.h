#ifndef ROM_H
#define ROM_H
#include <QWidget>
#include <QIcon>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>
#include <QPainter>
#include <QImage>
#include <QTimer>
#include <QTime>
#include <ctime>
#include <QButtonGroup>
#include <QKeyEvent>
#include <QStyle>
#include <QLabel>
#include <QString>
#include "management.h"
#include "appstore.h"
#include "string.h"
#include <iostream>
#include <sstream>

class ROM : public QWidget
{
    Q_OBJECT
public:
    explicit ROM(QWidget *parent = nullptr);
    std::string double_to_string(double i);
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *memory;
    QPushButton *blue;
    QPushButton *blue2;
    /*position 0-Calendar 1-Map 2-Snake 3-Chess 4-Fish*/
    double *mem_rom_arr;
    int *app_mem_arr;
    QPushButton *Manage;
    double app_memory;
    QPushButton *system;
    QPushButton *App;
    Management *new_page;
    QPushButton *Available;
    Appstore *store;

private:




signals:


public slots:
    void manage_click();
    void manage_click2();
};

#endif // ROM_H
