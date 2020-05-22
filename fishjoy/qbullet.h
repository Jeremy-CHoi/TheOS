#ifndef QBULLET_H
#define QBULLET_H
#include "qpixmapitem.h"
#include <QtGui>
#include "qnet.h"
#include <QGraphicsScene>

class QBullet:public qpixmapitem
{
public:
    QBullet(const QString & filename, QGraphicsScene *scene,qreal angle);
    void advance(int phase);
    void docolliding();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QGraphicsScene *scene;

};

#endif // QBULLET_H
