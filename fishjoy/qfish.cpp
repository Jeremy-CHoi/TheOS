#include "qfish.h"

QFish::QFish(const QString & filename,QGraphicsScene *scene):qpixmapitem(filename,scene)

{
    setPos(-600+qrand()%500,150+qrand()%250);
    resize(100,60);


}

void QFish::advance(int phase)
{
    if (mapToScene(0,0).y()<=-60 || mapToScene(0,0).x() >= 712)
    {
        setPos(-600+qrand()%500,150+qrand()%250);
    }
    int speed = qrand()%8;
    this->setPos(mapToScene(speed,-4+qrand()%6));
}
void QFish::fish_death(){
    setPos(-130,100+qrand()%200);
}
