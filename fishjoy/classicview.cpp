#include "classicview.h"

classicview::classicview()
{
    this->resize(612,465);
    this->setWindowTitle("Fishjoy");

    QPalette palette;

    palette.setBrush(QPalette::Background,QBrush(QPixmap("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/back.jpg")));
    this->setPalette(palette);


}
