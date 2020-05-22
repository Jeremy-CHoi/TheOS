#include "rom.h"

ROM::ROM(QWidget *parent) : QWidget(parent)
{
    this->resize(450,138);
//    this->setWindowIcon(QIcon(":/rom_back.png"));
    this->setWindowTitle("Memory");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/rom_back.png").scaled(this->size())));
    this->setPalette(palette);


    label1 = new QLabel(this);
    label1->setText("6GB");
    label1->setGeometry(30,82,30,20);

    label2 = new QLabel(this);
    label2->setText("Flash");
    label2->setGeometry(27,96,40,20);

    label3 = new QLabel(this);
    label3->setText("GB available (totally 6GB)");
    label3->setGeometry(120,40,180,20);

    memory = new QLabel(this);
    memory->setText("3.82");
    memory->setGeometry(90,40,30,20);

    blue = new QPushButton(this);
    blue->setIcon(QIcon(":/blue.png"));
    blue->setIconSize(QSize(82,18));
    blue->setGeometry(QRect(130,71,82,18));
    blue->setFlat(true);

    blue2 = new QPushButton(this);
    blue2->setIcon(QIcon(":/blue.png"));
    blue2->setIconSize(QSize(82,18));
    blue2->setGeometry(QRect(146,71,82,18));
    blue2->setFlat(true);
//    blue2->hide();

    system = new QPushButton(this);
    system->setIcon(QIcon(":/system.png"));
    system->setIconSize(QSize(32,12));
    system->setGeometry(QRect(96,74,32,12));
    system->setFlat(true);

    App = new QPushButton(this);
    App->setIcon(QIcon(":/App.png"));
    App->setIconSize(QSize(26,12));
    App->setGeometry(QRect(140,74,26,12));
    App->setFlat(true);


    QString str=QString::fromLocal8Bit("0.87GB");
    system->setToolTip(str);

    app_memory = 1.62;
    QString str2=QString("%1GB").arg(app_memory);
    App->setToolTip(str2);

    Manage = new QPushButton(this);
    Manage->setText("Details");
    Manage->setGeometry(330,35,90,30);

    Available = new QPushButton(this);
    Available->setText("Available");
    Available->setGeometry(300,65,90,30);
    Available->setFlat(true);

    QString str3=QString("%1GB").arg(6.0 - 0.87 - app_memory);
    Available->setToolTip(str3);

//    store = new Appstore();

    mem_rom_arr = new double[5];
    mem_rom_arr[0] = 0.1;
    mem_rom_arr[1] = 0.20;
    mem_rom_arr[3] = 0.15;
    mem_rom_arr[4] = 0.36;
    mem_rom_arr[5] = 0.42;

    app_mem_arr = new int[5];
    app_mem_arr[0] = 1;
    app_mem_arr[1] = 0;
    app_mem_arr[2] = 1;
    app_mem_arr[3] = 0;
    app_mem_arr[4] = 0;

    connect(Manage,SIGNAL(clicked()),this,SLOT(manage_click()));
    connect(Manage,SIGNAL(clicked()),this,SLOT(manage_click2()));

}

void ROM::manage_click(){
    new_page = new Management();
    new_page->setAttribute(Qt::WA_DeleteOnClose);
    new_page->show();
}

void ROM::manage_click2(){
    int place = 0;
    if (app_mem_arr[0] ==1){
        place++;
        new_page->text2_1->setGeometry(75,30,90,20);
        new_page->text2_2->setGeometry(180,30,90,20);
        new_page->text2_1->show();
        new_page->text2_2->show();
    }else{
        new_page->text2_1->hide();
        new_page->text2_2->hide();
    }
    if (app_mem_arr[1] ==1){
        place++;
        if (place == 1){
            new_page->text3_1->setGeometry(75,30,90,20);
            new_page->text3_2->setGeometry(180,30,90,20);
        }else{
            new_page->text3_1->setGeometry(75,50,90,20);
            new_page->text3_2->setGeometry(180,50,90,20);
        }
        new_page->text3_1->show();
        new_page->text3_2->show();
    }else{
        new_page->text3_1->hide();
        new_page->text3_2->hide();
    }
    if (app_mem_arr[2] == 1){
        place++;
        if (place == 1){
            new_page->text4_1->setGeometry(75,30,90,20);
            new_page->text4_2->setGeometry(180,30,90,20);
        }else if(place == 2){
            new_page->text4_1->setGeometry(75,50,90,20);
            new_page->text4_2->setGeometry(180,50,90,20);
        }else{
            new_page->text4_1->setGeometry(75,70,90,20);
            new_page->text4_2->setGeometry(180,70,90,20);
        }
        new_page->text4_1->show();
        new_page->text4_2->show();
    }else{
        new_page->text4_1->hide();
        new_page->text4_2->hide();
    }
    if (app_mem_arr[3] == 1){
        place++;
        if (place == 1){
            new_page->text9_1->setGeometry(75,30,90,20);
            new_page->text9_2->setGeometry(180,30,90,20);
        }else if(place == 2){
            new_page->text9_1->setGeometry(75,50,90,20);
            new_page->text9_2->setGeometry(180,50,90,20);
        }else if(place == 3){
            new_page->text9_1->setGeometry(75,70,90,20);
            new_page->text9_2->setGeometry(180,70,90,20);
        }else{
            new_page->text9_1->setGeometry(75,90,90,20);
            new_page->text9_2->setGeometry(180,90,90,20);
        }
        new_page->text9_1->show();
        new_page->text9_2->show();
    }else{
        new_page->text9_1->hide();
        new_page->text9_2->hide();
    }
    if (app_mem_arr[4] == 1){
        place++;
        if (place == 1){
            new_page->text8_1->setGeometry(75,30,90,20);
            new_page->text8_2->setGeometry(180,30,90,20);
        }else if(place == 2){
            new_page->text8_1->setGeometry(75,50,90,20);
            new_page->text8_2->setGeometry(180,50,90,20);
        }else if(place == 3){
            new_page->text8_1->setGeometry(75,70,90,20);
            new_page->text8_2->setGeometry(180,70,90,20);
        }else if (place == 4){
            new_page->text8_1->setGeometry(75,90,90,20);
            new_page->text8_2->setGeometry(180,90,90,20);
        }else{
            new_page->text8_1->setGeometry(75,110,90,20);
            new_page->text8_2->setGeometry(180,110,90,20);
        }
        new_page->text8_1->show();
        new_page->text8_2->show();
    }else{
        new_page->text8_1->hide();
        new_page->text8_2->hide();
    }
}

std::string ROM::double_to_string(double i){
    using namespace std;
    string str;
    stringstream ss;
    ss<<i;
    ss>>str;
    return str;
}







