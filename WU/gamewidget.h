#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

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


class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~GameWidget();

private:
    QPushButton *LeftButton;
    QPushButton *RightButton;
    QPushButton *UpButton;
    QPushButton *DownButton;
    QPushButton *StartButton;
    QPushButton *ReturnButton;
    int direct;
    int foodx;
    int foody;
    int food_count;
    QTimer *timer;
    int snake[100][2];//100行储存蛇的长度，2列储存蛇的每个节点的x,y坐标
    int snake1[100][2];
    QLabel *ScoreLabel;
    QLabel *LevelLabel;
    QLabel *ScoreLabelNumber;
    QLabel *LevelLabelNumber;
    int score;
    int level;

signals:





public slots:
    void left_b_click();
    void right_b_click();
    void up_b_click();
    void down_b_click();
    void start_b_click();
    void return_b_click();
    void time_out_slot();

};

#endif // GAMEWIDGET_H
