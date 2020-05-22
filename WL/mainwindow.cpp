#include "mainwindow.h"
#include "ram.h"
#include "rom.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(760,470);
//    this->setWindowIcon(QIcon(":/Icon.png"));
    this->setWindowTitle("Monitor Demo");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/background.png").scaled(this->size())));
    this->setPalette(palette);

    ROM_btn = new QPushButton(this);
    ROM_btn->setIcon(QIcon(":/rom.png"));
    ROM_btn->setIconSize(QSize(65,29));
    ROM_btn->setGeometry(QRect(0,0,65,29));
    ROM_btn->setFlat(true);

    RAM_btn = new QPushButton(this);
    RAM_btn->setIcon(QIcon(":/ram.png"));
    RAM_btn->setIconSize(QSize(65,29));
    RAM_btn->setGeometry(QRect(70,0,65,29));
    RAM_btn->setFlat(true);

    store = new QPushButton(this);
    store->setIcon(QIcon(":/Appstore.png"));
    store->setIconSize(QSize(45,45));
    store->setGeometry(QRect(25,50,45,45));
    store->setFlat(true);

    calendar = new QPushButton(this);
    calendar->setIcon(QIcon(":/calendar.png"));
    calendar->setIconSize(QSize(45,45));
    calendar->setGeometry(QRect(25,110,45,45));
    calendar->setFlat(true);

    snake = new QPushButton(this);
    snake->setIcon(QIcon(":/Snake.png"));
    snake->setIconSize(QSize(50,50));
    snake->setGeometry(QRect(23,170,50,50));
    snake->setFlat(true);

    map = new QPushButton(this);
    map->setIcon(QIcon(":/map.png"));
    map->setIconSize(QSize(50,50));
    map->setGeometry(QRect(23,230,50,50));
    map->setFlat(true);
    map->hide();

    chess = new QPushButton(this);
    chess->setIcon(QIcon(":/chess.png"));
    chess->setIconSize(QSize(44,44));
    chess->setGeometry(QRect(23,290,44,44));
    chess->setFlat(true);
    chess->hide();

    fish = new QPushButton(this);
    fish->setIcon(QIcon(":/fishjoy.png"));
    fish->setIconSize(QSize(46,46));
    fish->setGeometry(QRect(23,350,46,46));
    fish->setFlat(true);
    fish->hide();

    cal_place = 0;
    snake_place = 1;
    map_place = -1;
    chess_place = -1;
    fish_place = -1;

    mem_arr = new int[5];
    mem_arr[0] = 1;
    mem_arr[1] = 1;
    mem_arr[2] = 0;
    mem_arr[3] = 0;
    mem_arr[4] = 0;

    ram = new RAM();
    rom = new ROM();

    appstore = new Appstore();
    this->connect(ROM_btn,SIGNAL(clicked()),this,SLOT(ROM_click()));
    this->connect(RAM_btn,SIGNAL(clicked()),this,SLOT(RAM_click()));
    this->connect(store,SIGNAL(clicked()),this,SLOT(store_click()));
    //download
    this->connect(appstore->map_status,SIGNAL(clicked()),this,SLOT(map_download()));
    this->connect(appstore->chess_status,SIGNAL(clicked()),this,SLOT(chess_download()));
    this->connect(appstore->fish_status,SIGNAL(clicked()),this,SLOT(fish_download()));
    this->connect(appstore->calendar_status,SIGNAL(clicked()),this,SLOT(cal_download()));
    this->connect(appstore->snake_status,SIGNAL(clicked()),this,SLOT(snake_download()));
    //Uninstall
    this->connect(appstore->map_uninstall,SIGNAL(clicked()),this,SLOT(map_uninstall()));
    this->connect(appstore->cal_uninstall,SIGNAL(clicked()),this,SLOT(cal_uninstall()));
    this->connect(appstore->snake_uninstall,SIGNAL(clicked()),this,SLOT(snake_uninstall()));
    this->connect(appstore->chess_uninstall,SIGNAL(clicked()),this,SLOT(chess_uninstall()));
    this->connect(appstore->fish_uninstall,SIGNAL(clicked()),this,SLOT(fish_uninstall()));
    //ROM
    this->connect(appstore->fish_status,SIGNAL(clicked()),this,SLOT(app_rom_change()));
    this->connect(appstore->calendar_status,SIGNAL(clicked()),this,SLOT(app_rom_change()));
    this->connect(appstore->map_status,SIGNAL(clicked()),this,SLOT(app_rom_change()));
    this->connect(appstore->snake_status,SIGNAL(clicked()),this,SLOT(app_rom_change()));
    this->connect(appstore->chess_status,SIGNAL(clicked()),this,SLOT(app_rom_change()));

    this->connect(appstore->cal_uninstall,SIGNAL(clicked()),this,SLOT(app_rom_change()));
    this->connect(appstore->map_uninstall,SIGNAL(clicked()),this,SLOT(app_rom_change()));
    this->connect(appstore->fish_uninstall,SIGNAL(clicked()),this,SLOT(app_rom_change()));
    this->connect(appstore->chess_uninstall,SIGNAL(clicked()),this,SLOT(app_rom_change()));
    this->connect(appstore->snake_uninstall,SIGNAL(clicked()),this,SLOT(app_rom_change()));

    //Details
    this->connect(rom->Manage,SIGNAL(clicked()),this,SLOT(set_app_details()));
}

MainWindow::~MainWindow()
{
    delete ROM_btn;
    delete RAM_btn;
}

void MainWindow::RAM_click(){
//    ram = new RAM();
    ram->setAttribute(Qt::WA_DeleteOnClose);
    ram->show();
}

void MainWindow::ROM_click(){
//    rom = new ROM();
    rom->setAttribute(Qt::WA_DeleteOnClose);
    rom->show();
}

void MainWindow::store_click(){
    appstore->setAttribute(Qt::WA_DeleteOnClose);
    appstore->show();
}

void MainWindow::map_download(){
    int place = 10;
    for (int i=0;i<5;i++){
        if (mem_arr[i] == 0){
            place = i;
            mem_arr[i] = 1;
            break;
        }
    }
    if(place == 0){
        map->setGeometry(QRect(23,110,50,50));
        map->show();
    }else if(place == 1){
        map->setGeometry(QRect(23,170,50,50));
        map->show();
    }else if(place == 2){
        map->setGeometry(QRect(23,230,50,50));
        map->show();
    }else if(place == 3){
        map->setGeometry(QRect(23,290,50,50));
        map->show();
    }else if(place == 4){
        map->setGeometry(QRect(23,350,50,50));
        map->show();
    }
    map_place = place;
}

void MainWindow::chess_download(){
    int place = 10;
    for (int i=0;i<5;i++){
        if (mem_arr[i] == 0){
            place = i;
            mem_arr[i] = 1;
            break;
        }
    }
    if(place == 0){
        chess->setGeometry(QRect(23,110,44,44));
        chess->show();
    }else if(place == 1){
        chess->setGeometry(QRect(23,170,44,44));
        chess->show();
    }else if(place == 2){
        chess->setGeometry(QRect(23,230,44,44));
        chess->show();
    }else if(place == 3){
        chess->setGeometry(QRect(23,290,44,44));
        chess->show();
    }else if(place == 4){
        chess->setGeometry(QRect(23,350,44,44));
        chess->show();
    }
    chess_place = place;
}

void MainWindow::fish_download(){
    int place = 10;
    for (int i=0;i<5;i++){
        if (mem_arr[i] == 0){
            place = i;
            mem_arr[i] = 1;
            break;
        }
    }
    if(place == 0){
        fish->setGeometry(QRect(23,110,46,46));
        fish->show();
    }else if(place == 1){
        fish->setGeometry(QRect(23,170,46,46));
        fish->show();
    }else if(place == 2){
        fish->setGeometry(QRect(23,230,46,46));
        fish->show();
    }else if(place == 3){
        fish->setGeometry(QRect(23,290,46,46));
        fish->show();
    }else if(place == 4){
        fish->setGeometry(QRect(23,350,46,46));
        fish->show();
    }
    fish_place = place;
}

void MainWindow::cal_download(){
    int place = 10;
    for (int i=0;i<5;i++){
        if (mem_arr[i] == 0){
            place = i;
            mem_arr[i] = 1;
            break;
        }
    }
    if(place == 0){
        calendar->setGeometry(QRect(23,110,45,45));
        calendar->show();
    }else if(place == 1){
        calendar->setGeometry(QRect(23,170,45,45));
        calendar->show();
    }else if(place == 2){
        calendar->setGeometry(QRect(23,230,45,45));
        calendar->show();
    }else if(place == 3){
        calendar->setGeometry(QRect(23,290,45,45));
        calendar->show();
    }else if(place == 4){
        calendar->setGeometry(QRect(23,350,45,45));
        calendar->show();
    }
    cal_place = place;
}

void MainWindow::snake_download(){
    int place = 10;
    for (int i=0;i<5;i++){
        if (mem_arr[i] == 0){
            place = i;
            mem_arr[i] = 1;
            break;
        }
    }
    if(place == 0){
        snake->setGeometry(QRect(23,110,50,50));
        snake->show();
    }else if(place == 1){
        snake->setGeometry(QRect(23,170,50,50));
        snake->show();
    }else if(place == 2){
        snake->setGeometry(QRect(23,230,50,50));
        snake->show();
    }else if(place == 3){
        snake->setGeometry(QRect(23,290,50,50));
        snake->show();
    }else if(place == 4){
        snake->setGeometry(QRect(23,350,50,50));
        snake->show();
    }
    snake_place = place;
}

void MainWindow::map_uninstall(){
    map->hide();
    mem_arr[map_place] = 0;
}

void MainWindow::cal_uninstall(){
    calendar->hide();
    mem_arr[cal_place] = 0;
}

void MainWindow::snake_uninstall(){
    snake->hide();
    mem_arr[snake_place] = 0;
}

void MainWindow::chess_uninstall(){
    chess->hide();
    mem_arr[chess_place] = 0;
}
void MainWindow::fish_uninstall(){
    fish->hide();
    mem_arr[fish_place] = 0;
}

int MainWindow::progress_len(){
    //the number of 1 in app_status_arr
    int num = 0;
    for (int i = 0; i<5; i++){
        if (appstore->app_status_arr[i] == 1){
            num++;
        }
    }
    return num;
}

void MainWindow::app_rom_change(){
    int num = progress_len();
    if (num == 0){
        rom->blue2->hide();
    }else if (num == 1){
        rom->blue2->setGeometry(QRect(138,71,82,18));
    }else if (num == 2){
        rom->blue2->setGeometry(QRect(146,71,82,18));
    }else if (num ==3){
        rom->blue2->setGeometry(QRect(154,71,82,18));
    }else if (num ==4){
        rom->blue2->setGeometry(QRect(162,71,82,18));
    }else{
        rom->blue2->setGeometry(QRect(170,71,82,18));
    }
    rom->app_memory = app_ROM();
    rom->App->setToolTip(QString("%1GB").arg(rom->app_memory));
    rom->Available->setToolTip(QString("%1GB").arg(6.0 - 0.87 - rom->app_memory));
}

void MainWindow::set_app_details(){
    for (int i=0; i<5; i++){
        rom->app_mem_arr[i] = appstore->app_status_arr[i];
    }
}

double MainWindow::app_ROM(){
    double base = 1.62;
    for(int i=0; i<5;i++){
        if (appstore->app_status_arr[i] == 1){
            base = base + rom->mem_rom_arr[i];
        }
    }
    return base;
}
