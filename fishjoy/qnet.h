#ifndef QNET_H
#define QNET_H
#include "qpixmapitem.h"
#include "qfish.h"


class QNet:public qpixmapitem
{
public:
    QNet(const QString &filename,QGraphicsScene *scene);
    void advance(int phase);
//    int score;
};

#endif // QNET_H
