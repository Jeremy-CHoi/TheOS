#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QIcon>
#include <QGraphicsView>
#include <QResizeEvent>
#include "qgun.h"
#include "qfish.h"
#include <QTimer>
#include <QPoint>
#include <QLine>
#include <QLineF>
#include "qbullet.h"
#include <QLabel>


class GameWidget : public QGraphicsView
{
public:
     GameWidget();
     void resizeEvent(QResizeEvent *event);
     void mouseMoveEvent(QMouseEvent *event);

     void mousePressEvent(QMouseEvent *event);
private:

    QGraphicsScene *scene;

    qgun *gun;
    QFish *fish1;
    QFish *fish2;
    QFish *fish3;
    QFish *fish4;
    QFish *fish5;
    QFish *fish6;
    QFish *fish7;
    QFish *fish8;
    QFish *fish9;
    QFish *fish10;
    QTimer *timer;
//    QLabel *score_label;



signals:

};

#endif // GAMEWIDGET_H
