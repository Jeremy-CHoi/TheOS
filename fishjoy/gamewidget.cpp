
#include "mainwindow.h"
#include "gamewidget.h"

GameWidget::GameWidget()
{
    this->resize(612,465);
    this->setWindowTitle("Fishjoy");

    this->setAutoFillBackground(true);

    this->setBackgroundBrush(QBrush(QPixmap("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/back.jpg")));


    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,this->width(),this->height());

    this->setScene(scene);
    this->setMouseTracking(true);

//    this->score_label = new QLabel(this);
//    this->score_label->setNum(score)




    gun = new qgun();
    gun->setPos(this->width()/2-25,this->height()-50);
    scene->addItem(gun);

    fish1 = new QFish("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/fish.png",scene);


    fish2 = new QFish("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/fish.png",scene);



    fish3 = new QFish("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/fish.png",scene);

    fish4 = new QFish("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/fish.png",scene);


    fish5 = new QFish("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/fish.png",scene);
    fish6 = new QFish("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/fish.png",scene);
    fish7 = new QFish("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/fish.png",scene);
    fish8 = new QFish("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/fish.png",scene);
    fish9 = new QFish("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/fish.png",scene);
    fish10 = new QFish("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/fish.png",scene);
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    timer->start(100);


}
void GameWidget::resizeEvent(QResizeEvent *event)
{
    this->setBackgroundBrush(QBrush(QPixmap("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/back.jpg").scaled(event->size())));
}
//void GameWidget::return_btn_click()
//{

//    if (QMessageBox::Yes == QMessageBox::question(this,"Reminder","Are you sure to exit?",QMessageBox::Yes,QMessageBox::No)){
//        delete this;
//        exit(0);}

//}

void GameWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p;

    p = event->pos();

    QLine line(this->width()/2,this->height(),p.x(),p.y());
    QLineF linef(line);
    gun->setRotation(-(linef.angle())+90);
}
void GameWidget::mousePressEvent(QMouseEvent *event)
{
    QPoint p = event->pos();

    QLineF linef(this->width()/2,this->height(),p.x(),p.y());

    QBullet *bullet = new QBullet("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/bullett.png",scene,linef.angle());
    bullet->setPos(scene->width()/2-10,scene->height()-110);
    bullet->setRotation(-linef.angle()+90);
}

