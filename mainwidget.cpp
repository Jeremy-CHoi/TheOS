#include "mainwidget.h"

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{

    this->resize(600,340);
    this->setWindowIcon(QIcon(":/Icon.png"));
    this->setWindowTitle("Group48 Snake");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/back.png").scaled(this->size())));
    this->setPalette(palette);

    startButton = new QPushButton(this);
    startButton->setIcon(QIcon(":/start.png"));
    startButton->setIconSize(QSize(120,55));
    startButton->setGeometry(QRect(130,220,120,55));
    startButton->setFlat(true);

    exitButton = new QPushButton(this);
    exitButton->setIcon(QIcon(":/exit.png"));
    exitButton->setIconSize(QSize(110,50));
    exitButton->setGeometry(QRect(130,270,110,50));
    exitButton->setFlat(true);

    this->connect(startButton,SIGNAL(clicked()),this,SLOT(startbutton_click()));
    this->connect(exitButton,SIGNAL(clicked()),this,SLOT(exitbutton_click()));
}

mainWidget::~mainWidget()
{
    delete startButton;
    delete exitButton;
}

void mainWidget::startbutton_click(){
//    this->hide();
    gamewidget = new GameWidget(this);
    gamewidget->show();
}
void mainWidget::exitbutton_click(){
    if (QMessageBox::Yes == QMessageBox::question(this,"Reminder","Are you sure to exit?",QMessageBox::Yes,QMessageBox::No)){
        delete this;
        exit(0);
    }
}
