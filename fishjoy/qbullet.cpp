
#include "qbullet.h"


QBullet::QBullet(const QString & filename, QGraphicsScene *scene,qreal angle):qpixmapitem(filename,scene)
{
    resize(20,20);
    this->scene = scene;

}
void QBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(0,0,pixmap);
    if (this->collidingItems().count()>0) {
            docolliding();
        }
}

void QBullet::advance(int phase)
{
    if(mapToScene(0,0).x()<=0 || mapToScene(0,0).x()>=800||mapToScene(0,0).y()<=0){
        delete this;
    }

    else {
        this->setPos(mapToScene(0,-10));
    }

}

void QBullet::docolliding(){
    QNet * net = new QNet("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/net.png",this->scene);
    net->setPos(mapToScene(0,-50));

    delete this;
}
