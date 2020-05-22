#include "qgun.h"

qgun::qgun()
{
    pix.load("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/cannon.png");
    pix = pix.scaled(50,50);
}

QRectF qgun::boundingRect() const {
    return QRectF(0,0,pix.width(),pix.height());
}
void qgun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,pix);
}

