
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    this->resize(612,465);
    this->setWindowTitle("Fishjoy");

    QPalette palette;

    palette.setBrush(QPalette::Background,QBrush(QPixmap("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/back.jpg")));
    this->setPalette(palette);

    this->title = new QLabel(this);
    this->title->setPixmap(QPixmap("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/title.png"));
    this->title->resize(500,300);
    this->title->setGeometry(50,50,500,300);

    this->start_btn = new QPushButton(this);
    this->start_btn->setIcon(QIcon("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/start.png"));
    this->start_btn->setIconSize(QSize(100,60));
    this->start_btn->setGeometry(200,320,100,60);
    this->start_btn->setFlat(true);

    this->exit_btn = new QPushButton(this);
    this->exit_btn->setIcon(QIcon("/Users/DemiChen/Library/Mobile Documents/com~apple~CloudDocs/fishjoy/exit.png"));
    this->exit_btn->setIconSize(QSize(100,60));
    this->exit_btn->setGeometry(320,320,100,60);
    this->exit_btn->setFlat(true);

    this->connect(start_btn,SIGNAL(clicked()),this,SLOT(start_btn_click()));
    this->connect(exit_btn,SIGNAL(clicked()),this,SLOT(exit_btn_click()));

}
MainWindow::~MainWindow()
{
    delete start_btn;
    delete exit_btn;

}
void MainWindow::start_btn_click()
{
    this->hide();
    game.show();

}
void MainWindow::exit_btn_click(){
    if (QMessageBox::Yes == QMessageBox::question(this,"Reminder","Are you sure to exit?",QMessageBox::Yes,QMessageBox::No)){
        delete this;
        exit(0);
    }
}


