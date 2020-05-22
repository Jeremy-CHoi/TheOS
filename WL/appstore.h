#ifndef APPSTORE_H
#define APPSTORE_H

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
#include <QPlainTextEdit>
#include <QProgressBar>
#include <QThread>
#include "calendar.h"
#include "map.h"
#include "snake.h"

class Appstore : public QWidget
{
    Q_OBJECT
    friend class MainWindow;
public:
    explicit Appstore(QWidget *parent = nullptr);
    QPushButton *map_status;
    QPushButton *calendar_status;
    QPushButton *snake_status;
    QPushButton *chess_status;
    QPushButton *fish_status;
    /*position 0-Calendar 1-Map 2-Snake 3-Chess 4-Fish*/
    int *app_status_arr;
    QPushButton *cal_uninstall;
    QPushButton *map_uninstall;
    QPushButton *snake_uninstall;
    QPushButton *chess_uninstall;
    QPushButton *fish_uninstall;
private:
    QPushButton *User;
    QLabel *user_name;
    QPushButton *Game_btn;
    QPushButton *Life_btn;
    QPushButton *search_btn;
    QPlainTextEdit *search;
    QPushButton *App_calendar;
    QPushButton *App_map;
    QPushButton *App_snake;
    QPushButton *App_chess;
    QPushButton *App_fish;
    QProgressBar *cal_bar;
    QProgressBar *map_bar;
    QProgressBar *snake_bar;
    QProgressBar *chess_bar;
    QProgressBar *fish_bar;
    QTime dietime;
    QLabel *Downloaded_Apps;


//    QTime starttime;
    Calendar *cal;
    Map *map;
    Snake *snake;

signals:

public slots:
    void Game_click();
    void Life_click();
    void User_click();
    void Map_status_click();
    void Map_status_click2();
    void Chess_status_click();
    void Chess_status_click2();
    void Fish_status_click();
    void Fish_status_click2();
    void Cal_status_click();
    void Cal_status_click2();
    void Snake_status_click();
    void Snake_status_click2();
    void Calendar_click();
    void Map_click();
    void Snake_click();
    void search_btn_click();
    void cal_delete();
    void map_delete();
    void snake_delete();
    void chess_delete();
    void fish_delete();
};

#endif // APPSTORE_H
