#include "qpixmapitem.h"

qpixmapitem::qpixmapitem(const QString & filename,QGraphicsScene * scene)

{
    pixmap.load(filename);
    scene->addItem(this);



}
QRectF qpixmapitem::boundingRect () const{
        return QRectF(0,0,pixmap.width(),pixmap.height());
}
void qpixmapitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
        painter->drawPixmap(0,0,pixmap);
}
void qpixmapitem::resize(int x, int y)
{
    pixmap = pixmap.scaled(x,y);
}

