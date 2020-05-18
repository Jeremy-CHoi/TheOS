#ifndef WIDGET_H
#define WIDGET_H

#include<QWidget>
#include<QPaintEvent>
#include<QPainter>
#include<QPalette>
#include<QMouseEvent>
#include<QLabel>
#include<QTimer>
#include<string>
#include<QPushButton>
#include<QMessageBox>

class Widget : public QWidget
{
    Q_OBJECT
private:
    int Chessman_Coordinate[9][10];
    int To_Move[9][10];
    int Clicked_X;
    int Clicked_Y;
    int Step_Number;
    int Sum_Duration;

    bool Is_Gameover;
    QLabel *Sum_Time;

    QTimer *Timer;

    QPushButton *Start_Game;
    QPushButton *Exit_Game;
    QPushButton *Sum_btn;
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void Init_Array();
    void Init_Move_Array();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void To_Move_Chessman(int i, int j, int value);
    void Eat_Chessman(int Eat_x, int Eat_y, int Eat_value, int Eaten_x, int Eaten_y, int Eaten_value);

    void Is_Win();
public slots:
    void Time_Out_Slots();
    void Start_Game_Slots();
    void Exit_Game_Slots();
};

#endif // WIDGET_H
