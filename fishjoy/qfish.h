#ifndef QFISH_H
#define QFISH_H
#include "qpixmapitem.h"
#include <QtGui>
#include <QGraphicsScene>



class QFish:public qpixmapitem
{
public:
    QFish(const QString & filename,QGraphicsScene *scene);
    void advance(int phase);
    void fish_death();
};

#endif // QFISH_H
