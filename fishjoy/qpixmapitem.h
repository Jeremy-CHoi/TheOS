#ifndef QPIXMAPITEM_H
#define QPIXMAPITEM_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>


class qpixmapitem:public QGraphicsItem

{
public:
    qpixmapitem(const QString & filename,QGraphicsScene *scene);
    virtual QRectF boundingRect () const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void resize(int x,int y);
    QPixmap pixmap;
private:

};

#endif // QPIXMAPITEM_H
