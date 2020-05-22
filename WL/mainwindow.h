#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
#include "ram.h"
#include "rom.h"
#include "appstore.h"
#include "map.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
    int *mem_arr;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Appstore *appstore;

private:
    int cal_place;
    int map_place;
    int snake_place;
    int chess_place;
    int fish_place;
    QPushButton *ROM_btn;
    QPushButton *RAM_btn;
    ROM *rom;
    RAM *ram;
    QPushButton *store;
    QPushButton *calendar;
    QPushButton *snake;
    QPushButton *chess;
    QPushButton *fish;
    QPushButton *map;
    int progress_len();
    double app_ROM();

public slots:
    void ROM_click();
    void RAM_click();
    void store_click();
    //App download
    void map_download();
    void chess_download();
    void fish_download();
    void cal_download();
    void snake_download();
    //App uninstall
    void map_uninstall();
    void cal_uninstall();
    void snake_uninstall();
    void chess_uninstall();
    void fish_uninstall();
    //for ROM connection
    void app_rom_change();
    //for details connection
    void set_app_details();

};
#endif // MAINWINDOW_H
