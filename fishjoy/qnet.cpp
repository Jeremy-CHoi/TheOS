
#include "qnet.h"

QNet::QNet(const QString & filename, QGraphicsScene *scene):qpixmapitem(filename,scene)
{
    this->resize(120,120);

}
void QNet::advance(int phase)
{

    if(this->collidingItems().count()>0){
        QList<QGraphicsItem *>list = this->collidingItems();
        QList<QGraphicsItem *>::Iterator i;
        QFish * fish;
        i = list.begin();

        while(i !=list.end()){
            fish = (QFish*)(*i);
            fish->fish_death();
            i++;
//            score++;
        }
    }
    this->hide();
    delete this;
}
