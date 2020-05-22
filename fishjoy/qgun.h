#ifndef QGUN_H
#define QGUN_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QtCore>

class qgun:public QGraphicsItem
{
public:
    qgun();
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
private:
    QPixmap pix;
};

#endif // QGUN_H
