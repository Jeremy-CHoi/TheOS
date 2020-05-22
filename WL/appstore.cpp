#include "appstore.h"

Appstore::Appstore(QWidget *parent) : QWidget(parent)
{
    this->resize(700,454);
//    this->setWindowIcon(QIcon(":/Icon.png"));
    this->setWindowTitle("Appstore");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/store_back.png").scaled(this->size())));
    this->setPalette(palette);

    User = new QPushButton(this);
    User->setIcon(QIcon(":/User_logo.png"));
    User->setIconSize(QSize(45,45));
    User->setGeometry(QRect(25,370,45,45));
    User->setFlat(true);

    user_name = new QLabel(this);
    user_name->setText("Kaikai");
    user_name->setGeometry(QRect(75,383,100,25));

    Downloaded_Apps = new QLabel(this);
    Downloaded_Apps->setText("Downloaded Apps:");
    Downloaded_Apps->setGeometry(QRect(200,10,150,25));
    Downloaded_Apps->hide();

    Game_btn = new QPushButton(this);
    Game_btn->setIcon(QIcon(":/Game2.png"));
    Game_btn->setIconSize(QSize(195,45));
    Game_btn->setGeometry(QRect(-8,50,195,45));
    Game_btn->setFlat(true);

    Life_btn = new QPushButton(this);
    Life_btn->setIcon(QIcon(":/Life.png"));
    Life_btn->setIconSize(QSize(192,40));
    Life_btn->setGeometry(QRect(-5,100,192,40));
    Life_btn->setFlat(true);

    search = new QPlainTextEdit(this);
    search->setGeometry(QRect(10,10,140,25));

    search_btn = new QPushButton(this);
    search_btn->setIcon(QIcon(":/search_btn.png"));
    search_btn->setIconSize(QSize(16,16));
    search_btn->setGeometry(QRect(155,12,16,16));
    search_btn->setFlat(true);

    App_calendar = new QPushButton(this);
    App_calendar->setIcon(QIcon(":/App_calendar.png"));
    App_calendar->setIconSize(QSize(248,66));
    App_calendar->setGeometry(QRect(220,30,248,66));
    App_calendar->setFlat(true);
    App_calendar->hide();

    calendar_status = new QPushButton(this);
    calendar_status->setIcon(QIcon(":/ok.png"));
    calendar_status->setIconSize(QSize(50,23));
    calendar_status->setGeometry(QRect(520,45,50,23));
    calendar_status->setFlat(true);
    calendar_status->hide();

    App_map = new QPushButton(this);
    App_map->setIcon(QIcon(":/App_map.png"));
    App_map->setIconSize(QSize(240,64));
    App_map->setGeometry(QRect(220,136,240,64));
    App_map->setFlat(true);
    App_map->hide();

    map_status = new QPushButton(this);
    map_status->setIcon(QIcon(":/download.png"));
    map_status->setIconSize(QSize(50,25));
    map_status->setGeometry(QRect(520,151,50,25));
    map_status->setFlat(true);
    map_status->hide();

    App_snake = new QPushButton(this);
    App_snake->setIcon(QIcon(":/App_snake.png"));
    App_snake->setIconSize(QSize(221,73));
    App_snake->setGeometry(QRect(213,20,221,73));
    App_snake->setFlat(true);
//    App_snake->hide();

    snake_status = new QPushButton(this);
    snake_status->setIcon(QIcon(":/ok.png"));
    snake_status->setIconSize(QSize(50,25));
    snake_status->setGeometry(QRect(520,30,50,25));
    snake_status->setFlat(true);
//    snake_status->hide();

    App_chess = new QPushButton(this);
    App_chess->setIcon(QIcon(":/App_chess.png"));
    App_chess->setIconSize(QSize(224,62));
    App_chess->setGeometry(QRect(220,130,224,62));
    App_chess->setFlat(true);
//    App_chess->hide();

    chess_status = new QPushButton(this);
    chess_status->setIcon(QIcon(":/download.png"));
    chess_status->setIconSize(QSize(50,25));
    chess_status->setGeometry(QRect(520,140,50,25));
    chess_status->setFlat(true);
//    chess_status->hide();

    App_fish = new QPushButton(this);
    App_fish->setIcon(QIcon(":/App_fish.png"));
    App_fish->setIconSize(QSize(233,68));
    App_fish->setGeometry(QRect(220,230,233,68));
    App_fish->setFlat(true);
//    App_fish->hide();

    fish_status = new QPushButton(this);
    fish_status->setIcon(QIcon(":/download.png"));
    fish_status->setIconSize(QSize(50,25));
    fish_status->setGeometry(QRect(520,250,50,25));
    fish_status->setFlat(true);
//    fish_status->hide();

    map_bar = new QProgressBar(this);
    map_bar->setGeometry(QRect(520,135,100,25));
    map_bar->setOrientation(Qt::Horizontal);
    map_bar->setMinimum(0);
    map_bar->setMaximum(0);//RAM value kb
    map_bar->setValue(0);
    map_bar->hide();
//    double dProgress = (map_bar->value() - map_bar->minimum()) * 100.0
//                    / (map_bar->maximum() - map_bar->minimum());
//    map_bar->setFormat(QString::fromLocal8Bit("%1%").arg(QString::number(dProgress, 'f', 1)));
//    map_bar->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    cal_bar = new QProgressBar(this);
    cal_bar->setGeometry(QRect(520,40,100,25));
    cal_bar->setOrientation(Qt::Horizontal);
    cal_bar->setMinimum(0);
    cal_bar->setMaximum(6000);//RAM value kb
    cal_bar->setValue(0);
    cal_bar->hide();

    snake_bar = new QProgressBar(this);
    snake_bar->setGeometry(QRect(520,30,100,25));
    snake_bar->setOrientation(Qt::Horizontal);
    snake_bar->setMinimum(0);
    snake_bar->setMaximum(6000);//RAM value kb
    snake_bar->setValue(0);
    snake_bar->hide();

    chess_bar = new QProgressBar(this);
    chess_bar->setGeometry(QRect(520,145,100,25));
    chess_bar->setOrientation(Qt::Horizontal);
    chess_bar->setMinimum(0);
    chess_bar->setMaximum(6000);//RAM value kb
    chess_bar->setValue(0);
    chess_bar->hide();

    fish_bar = new QProgressBar(this);
    fish_bar->setGeometry(QRect(520,250,100,25));
    fish_bar->setOrientation(Qt::Horizontal);
    fish_bar->setMinimum(0);
    fish_bar->setMaximum(0);
//    fish_bar->setValue(0);
    fish_bar->hide();

    app_status_arr = new int[5];
    app_status_arr[0] = 1;
    app_status_arr[2] = 1;
    app_status_arr[1] = 0;
    app_status_arr[3] = 0;
    app_status_arr[4] = 0;

    cal_uninstall = new QPushButton(this);
    cal_uninstall->setIcon(QIcon(":/uninstall.png"));
    cal_uninstall->setIconSize(QSize(46,23));
    cal_uninstall->setGeometry(QRect(520,45,46,23));
    cal_uninstall->setFlat(true);
    cal_uninstall->hide();

    map_uninstall = new QPushButton(this);
    map_uninstall->setIcon(QIcon(":/uninstall.png"));
    map_uninstall->setIconSize(QSize(46,23));
    map_uninstall->setGeometry(QRect(520,45,46,23));
    map_uninstall->setFlat(true);
    map_uninstall->hide();

    snake_uninstall = new QPushButton(this);
    snake_uninstall->setIcon(QIcon(":/uninstall.png"));
    snake_uninstall->setIconSize(QSize(46,23));
    snake_uninstall->setGeometry(QRect(520,45,46,23));
    snake_uninstall->setFlat(true);
    snake_uninstall->hide();

    chess_uninstall = new QPushButton(this);
    chess_uninstall->setIcon(QIcon(":/uninstall.png"));
    chess_uninstall->setIconSize(QSize(46,23));
    chess_uninstall->setGeometry(QRect(520,45,46,23));
    chess_uninstall->setFlat(true);
    chess_uninstall->hide();

    fish_uninstall = new QPushButton(this);
    fish_uninstall->setIcon(QIcon(":/uninstall.png"));
    fish_uninstall->setIconSize(QSize(46,23));
    fish_uninstall->setGeometry(QRect(520,45,46,23));
    fish_uninstall->setFlat(true);
    fish_uninstall->hide();


    connect(Game_btn,SIGNAL(clicked()),this,SLOT(Game_click()));
    connect(Life_btn,SIGNAL(clicked()),this,SLOT(Life_click()));
    connect(User,SIGNAL(clicked()),this,SLOT(User_click()));
//    connect(map_bar,SIGNAL(valueChanged(value)),this,SLOT(reset()));
    connect(map_status,SIGNAL(clicked()),this,SLOT(Map_status_click()));
    connect(map_status,SIGNAL(clicked()),this,SLOT(Map_status_click2()));
    connect(App_calendar,SIGNAL(clicked()),this,SLOT(Calendar_click()));
    connect(App_map,SIGNAL(clicked()),this,SLOT(Map_click()));
    connect(App_snake,SIGNAL(clicked()),this,SLOT(Snake_click()));
    connect(chess_status,SIGNAL(clicked()),this,SLOT(Chess_status_click()));
    connect(chess_status,SIGNAL(clicked()),this,SLOT(Chess_status_click2()));
    connect(fish_status,SIGNAL(clicked()),this,SLOT(Fish_status_click()));
    connect(fish_status,SIGNAL(clicked()),this,SLOT(Fish_status_click2()));
    connect(calendar_status,SIGNAL(clicked()),this,SLOT(Cal_status_click()));
    connect(calendar_status,SIGNAL(clicked()),this,SLOT(Cal_status_click2()));
    connect(snake_status,SIGNAL(clicked()),this,SLOT(Snake_status_click()));
    connect(snake_status,SIGNAL(clicked()),this,SLOT(Snake_status_click2()));
    connect(search_btn,SIGNAL(clicked()),this,SLOT(search_btn_click()));
    connect(cal_uninstall,SIGNAL(clicked()),this,SLOT(cal_delete()));
    connect(cal_uninstall,SIGNAL(clicked()),this,SLOT(User_click()));
    connect(map_uninstall,SIGNAL(clicked()),this,SLOT(map_delete()));
    connect(map_uninstall,SIGNAL(clicked()),this,SLOT(User_click()));
    connect(snake_uninstall,SIGNAL(clicked()),this,SLOT(snake_delete()));
    connect(snake_uninstall,SIGNAL(clicked()),this,SLOT(User_click()));
    connect(chess_uninstall,SIGNAL(clicked()),this,SLOT(chess_delete()));
    connect(chess_uninstall,SIGNAL(clicked()),this,SLOT(User_click()));
    connect(fish_uninstall,SIGNAL(clicked()),this,SLOT(fish_delete()));
    connect(fish_uninstall,SIGNAL(clicked()),this,SLOT(User_click()));
}

void Appstore::Game_click(){
    //uninstall button
    cal_uninstall->hide();
    map_uninstall->hide();
    snake_uninstall->hide();
    chess_uninstall->hide();
    fish_uninstall->hide();
    //download app string on user interface
    Downloaded_Apps->hide();
    //Category btn in the left bar
    Game_btn->setIcon(QIcon(":/Game2.png"));
    Life_btn->setIcon(QIcon(":/Life.png"));
    //App and downloading status btn
    App_calendar->hide();
    map_status->hide();
    calendar_status->hide();
    App_map->hide();
    App_chess->setGeometry(QRect(220,130,224,62));
    App_chess->show();
    chess_status->setGeometry(QRect(520,140,50,25));
    chess_status->show();
    App_snake->setGeometry(QRect(213,20,221,73));
    App_snake->show();
    snake_status->setGeometry(QRect(520,30,50,25));
    snake_status->show();
    App_fish->setGeometry(QRect(220,230,233,68));
    App_fish->show();
    fish_status->setGeometry(QRect(520,250,50,25));
    fish_status->show();
}

void Appstore::Life_click(){
    //uninstall button
    cal_uninstall->hide();
    map_uninstall->hide();
    snake_uninstall->hide();
    chess_uninstall->hide();
    fish_uninstall->hide();
    Downloaded_Apps->hide();
    Game_btn->setIcon(QIcon(":/Game.png"));
    Life_btn->setIcon(QIcon(":/Life2.png"));
    App_calendar->setGeometry(QRect(220,30,248,66));
    App_calendar->show();
    calendar_status->setGeometry(QRect(520,45,50,23));
    calendar_status->show();
    App_map->setGeometry(QRect(220,136,248,66));
    App_map->show();
    map_status->setGeometry(QRect(520,151,50,25));
    map_status->show();
    App_chess->hide();
    App_snake->hide();
    snake_status->hide();
    chess_status->hide();
    App_fish->hide();
    fish_status->hide();
}

void Appstore::User_click(){
    cal_uninstall->hide();
    map_uninstall->hide();
    snake_uninstall->hide();
    chess_uninstall->hide();
    fish_uninstall->hide();
    App_calendar->hide();
    map_status->hide();
    calendar_status->hide();
    App_map->hide();
    App_chess->hide();
    App_snake->hide();
    snake_status->hide();
    chess_status->hide();
    App_fish->hide();
    fish_status->hide();
    Downloaded_Apps->show();
    int place = 1;
    if (app_status_arr[0]==1){
        App_calendar->setGeometry(QRect(220,40,248,66));
        App_calendar->show();
        cal_uninstall->show();
        place++;
    }
    if (app_status_arr[1]==1){
        if(place ==1){
            App_map->setGeometry(QRect(220,40,240,64));
            map_uninstall->setGeometry(QRect(520,45,46,23));
        }else{
            App_map->setGeometry(QRect(220,120,240,64));
            map_uninstall->setGeometry(QRect(520,125,46,23));
        }
        App_map->show();
        map_uninstall->show();
        place++;
    }
    if (app_status_arr[2]==1){
        if(place ==1){
            App_snake->setGeometry(QRect(218,40,221,73));
            snake_uninstall->setGeometry(QRect(520,45,46,23));
        }else if(place ==2){
            App_snake->setGeometry(QRect(218,120,221,73));
            snake_uninstall->setGeometry(QRect(520,125,46,23));
        }else{
            App_snake->setGeometry(QRect(218,200,221,73));
            snake_uninstall->setGeometry(QRect(520,205,46,23));
        }
        App_snake->show();
        snake_uninstall->show();
        place++;
    }
    if (app_status_arr[3]==1){
        if(place ==1){
            App_chess->setGeometry(QRect(223,40,224,62));
            chess_uninstall->setGeometry(QRect(520,45,46,23));
        }else if(place ==2){
            App_chess->setGeometry(QRect(223,120,224,62));
            chess_uninstall->setGeometry(QRect(520,125,46,23));
        }else if(place ==3){
            App_chess->setGeometry(QRect(223,200,224,62));
            chess_uninstall->setGeometry(QRect(520,205,46,23));
        }else{
            App_chess->setGeometry(QRect(223,290,224,62));
            chess_uninstall->setGeometry(QRect(520,295,46,23));
        }
        App_chess->show();
        chess_uninstall->show();
        place++;
    }
    if (app_status_arr[4]==1){
        if(place ==1){
            App_fish->setGeometry(QRect(220,40,233,68));
            fish_uninstall->setGeometry(QRect(520,45,46,23));
        }else if(place ==2){
            App_fish->setGeometry(QRect(222,120,233,68));
            fish_uninstall->setGeometry(QRect(520,125,46,23));
        }else if(place ==3){
            App_fish->setGeometry(QRect(222,200,233,68));
            fish_uninstall->setGeometry(QRect(520,205,46,23));
        }else if(place ==4){
            App_fish->setGeometry(QRect(222,290,233,68));
            fish_uninstall->setGeometry(QRect(520,295,46,23));
        }else{
            App_fish->setGeometry(QRect(222,360,233,68));
            fish_uninstall->setGeometry(QRect(520,365,46,23));
        }
        App_fish->show();
        fish_uninstall->show();
    }
}

void Appstore::Map_status_click(){
    map_status->hide();
    map_bar->show();
}

void Appstore::Map_status_click2(){
    dietime = QTime::currentTime().addSecs(2);
    while(QTime::currentTime() < dietime){
    }
    map_bar->hide();
    map_status->setIcon(QIcon(":/ok.png"));
    map_status->show();
    app_status_arr[1] = 1;
}

void Appstore::Calendar_click(){
    cal = new Calendar();
    cal->setAttribute(Qt::WA_DeleteOnClose);
    cal->show();
}

void Appstore::Map_click(){
    map = new Map();
    map->setAttribute(Qt::WA_DeleteOnClose);
    map->show();
}

void Appstore::Snake_click(){
    snake = new Snake();
    snake->setAttribute(Qt::WA_DeleteOnClose);
    snake->show();
}

void Appstore::Chess_status_click(){
    chess_status->hide();
    chess_bar->show();
    app_status_arr[3] = 1;
}

void Appstore::Chess_status_click2(){
    dietime = QTime::currentTime().addSecs(2);
    while(QTime::currentTime() < dietime){
    }
    chess_bar->hide();
    chess_status->setIcon(QIcon(":/ok.png"));
    chess_status->show();
}

void Appstore::Snake_status_click(){
    snake_status->hide();
    snake_bar->show();
    app_status_arr[2] = 1;
}

void Appstore::Snake_status_click2(){
    dietime = QTime::currentTime().addSecs(2);
    while(QTime::currentTime() < dietime){
    }
    snake_bar->hide();
    snake_status->setIcon(QIcon(":/ok.png"));
    snake_status->show();
}

void Appstore::Cal_status_click(){
    calendar_status->hide();
    cal_bar->show();
    app_status_arr[0] = 1;
}

void Appstore::Cal_status_click2(){
    dietime = QTime::currentTime().addSecs(2);
    while(QTime::currentTime() < dietime){
    }
    cal_bar->hide();
    calendar_status->setIcon(QIcon(":/ok.png"));
    calendar_status->show();
}

void Appstore::Fish_status_click(){
    fish_status->hide();
    fish_bar->show();
    app_status_arr[4] = 1;
}

void Appstore::Fish_status_click2(){
    dietime = QTime::currentTime().addSecs(2);
    while(QTime::currentTime() < dietime){
    }
    fish_bar->hide();
    fish_status->setIcon(QIcon(":/ok.png"));
    fish_status->show();
}

void Appstore::search_btn_click(){
    App_calendar->hide();
    map_status->hide();
    calendar_status->hide();
    App_map->hide();
    App_chess->hide();
    App_snake->hide();
    snake_status->hide();
    chess_status->hide();
    App_fish->hide();
    fish_status->hide();
    if (search->toPlainText() == "Snake"){
        App_snake->setGeometry(QRect(213,20,221,73));
        App_snake->show();
        snake_status->setGeometry(QRect(520,30,50,25));
        snake_status->show();
    }else if(search->toPlainText() == "Chinese Chess"){
        App_chess->setGeometry(QRect(220,20,224,62));
        App_chess->show();
        chess_status->setGeometry(QRect(520,30,50,25));
        chess_status->show();
    }else if(search->toPlainText() == "fishjoy"){
        App_fish->setGeometry(QRect(220,20,233,68));
        App_fish->show();
        fish_status->setGeometry(QRect(520,30,50,25));
        fish_status->show();
    }else if(search->toPlainText() == "Calendar"){
        App_calendar->setGeometry(QRect(220,30,248,66));
        App_calendar->show();
        calendar_status->setGeometry(QRect(520,45,50,23));
        calendar_status->show();
    }else if(search->toPlainText() == "Map"){
        App_map->setGeometry(QRect(220,30,248,66));
        App_map->show();
        map_status->setGeometry(QRect(520,45,50,25));
        map_status->show();
    }
}

void Appstore::cal_delete(){
    calendar_status->setIcon(QIcon(":/download.png"));
    app_status_arr[0]=0;
}

void Appstore::map_delete(){
    map_status->setIcon(QIcon(":/download.png"));
    app_status_arr[1]=0;
}

void Appstore::snake_delete(){
    snake_status->setIcon(QIcon(":/download.png"));
    app_status_arr[2]=0;
}

void Appstore::chess_delete(){
    chess_status->setIcon(QIcon(":/download.png"));
    app_status_arr[3]=0;
}

void Appstore::fish_delete(){
    fish_status->setIcon(QIcon(":/download.png"));
    app_status_arr[4]=0;
}
