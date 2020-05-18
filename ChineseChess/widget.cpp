#include "widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(748,688);
    this->setWindowTitle("Chinese Chess");

    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/btn/img/bbborad.jpeg")));
    this->setPalette(palette);

    Sum_Time=new QLabel("00:00:00",this);
    Sum_Time->setGeometry(680,195,150,40);

    Sum_btn = new QPushButton(this);
    Sum_btn->setIcon(QIcon(":/btn/img/total.png"));
    Sum_btn->setIconSize(QSize(70,70));
    Sum_btn->setGeometry(600,180,70,70);
    Sum_btn->setFlat(true);

    Timer =new QTimer(this);
    connect(Timer,SIGNAL(timeout()),this,SLOT(Time_Out_Slots()));

    Sum_Duration=0;
    Is_Gameover=true;

    Start_Game=new QPushButton(this);
    Start_Game->setIcon(QIcon(":/btn/img/start.png"));
    Start_Game->setIconSize(QSize(100,100));
    Start_Game->setGeometry(600,400,100,100);
    Start_Game->setFlat(1);

    Exit_Game=new QPushButton(this);
    Exit_Game->setIcon(QIcon(":/btn/img/exit.png"));
    Exit_Game->setIconSize(QSize(100,100));
    Exit_Game->setGeometry(600,470,100,100);
    Exit_Game->setFlat(1);

    connect(Start_Game,SIGNAL(clicked(bool)),this,SLOT(Start_Game_Slots()));
    connect(Exit_Game,SIGNAL(clicked(bool)),this,SLOT(Exit_Game_Slots()));
}

Widget::~Widget()
{
    delete this;
}

void Widget::Init_Array()
{
    memset(Chessman_Coordinate,0,90*sizeof(int));
    //black chessman
    Chessman_Coordinate[4][0]=1;
    Chessman_Coordinate[3][0]=2;
    Chessman_Coordinate[5][0]=2;
    Chessman_Coordinate[2][0]=3;
    Chessman_Coordinate[6][0]=3;
    Chessman_Coordinate[7][0]=4;
    Chessman_Coordinate[1][0]=4;
    Chessman_Coordinate[8][0]=5;
    Chessman_Coordinate[0][0]=5;
    Chessman_Coordinate[1][2]=6;
    Chessman_Coordinate[7][2]=6;
    for(int i=0;i<5;i++)
    {
        Chessman_Coordinate[2*i][3]=7;
    }
    //red chessman
    Chessman_Coordinate[4][9]=-1;
    Chessman_Coordinate[3][9]=-2;
    Chessman_Coordinate[5][9]=-2;
    Chessman_Coordinate[2][9]=-3;
    Chessman_Coordinate[6][9]=-3;
    Chessman_Coordinate[7][9]=-4;
    Chessman_Coordinate[1][9]=-4;
    Chessman_Coordinate[8][9]=-5;
    Chessman_Coordinate[0][9]=-5;
    Chessman_Coordinate[1][7]=-6;
    Chessman_Coordinate[7][7]=-6;
    for(int i=0;i<5;i++)
    {
        Chessman_Coordinate[2*i][6]=-7;
    }


    Init_Move_Array();}

void Widget::Init_Move_Array()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<10;j++)
        {
            To_Move[i][j]=Chessman_Coordinate[i][j];
        }
    }
}
void Widget::mousePressEvent(QMouseEvent *event)
{
    if(10<event->pos().x()&&event->pos().x()<=890&&
            10<event->pos().y()&&event->pos().y()<=990&&!Is_Gameover)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(16+68*i<=event->pos().x()&&event->pos().x()<16+68*(i+1)&&
                        18+68*j<=event->pos().y()&&event->pos().y()<18+68*(j+1))
                {
                    if(To_Move[i][j]==10){
                        Eat_Chessman(Clicked_X,Clicked_Y,Chessman_Coordinate[Clicked_X][Clicked_Y],i,j,Chessman_Coordinate[i][j]);
                    }
                    else  if(Chessman_Coordinate[i][j]==0){//10 stands for available, 0 stands for inavailable.
                        Init_Move_Array();
                        return;
                    }
                    else if(Step_Number%2==1&&Chessman_Coordinate[i][j]<0){
                        Init_Move_Array();
                        To_Move_Chessman(i,j,Chessman_Coordinate[i][j]);
                    }
                    else if(Step_Number%2==0&&Chessman_Coordinate[i][j]>0){
                        Init_Move_Array();
                        To_Move_Chessman(i,j,Chessman_Coordinate[i][j]);

                    }

                    else{
                        Init_Move_Array();
                        return;
                    }
                    Clicked_X=i;
                    Clicked_Y=j;
                    this->repaint();
                }
            }
        }
    }
}

void Widget::To_Move_Chessman(int i,int j,int value)
{
    bool Is_Skip=false;
    switch (value) {
    case 1://ma
        if(i<=4&&Chessman_Coordinate[i+1][j]<=0){
        To_Move[i+1][j]=10;}
        if(i>=4&&Chessman_Coordinate[i-1][j]<=0){
            To_Move[i-1][j]=10;}
        if(j<=1&&Chessman_Coordinate[i][j+1]<=0){
            To_Move[i][j+1]=10;}
        if(j>=1&&Chessman_Coordinate[i][j+1]<=0){
            To_Move[i][j-1]=10;}
        break;


    case 2://shi
        if(i>=2&&j-1>=0&&Chessman_Coordinate[i-1][j-1]<=0){
            To_Move[i-1][j-1]=10;}

        if(i<=4&&j-1>=0&&Chessman_Coordinate[i+1][j-1]<=0){
            To_Move[i+1][j-1]=10;}
        if(i>=2&&j+1<=2&&Chessman_Coordinate[i-1][j+1]<=0){
            To_Move[i-1][j+1]=10;}
        if(i<=4&&j+1<=2&&Chessman_Coordinate[i+1][j+1]<=0){
            To_Move[i+1][j+1]=10;}
        break;
    case 3://xiang

        if(i>=2&&j+2<=4&&Chessman_Coordinate[i-2][j+2]<=0){
            To_Move[i-2][j+2]=10;}
        if(i>=2&&j-2>=0&&Chessman_Coordinate[i-2][j-2]<=0){
            To_Move[i-2][j-2]=10;}
        if(i<=6&&j+2<=4&&Chessman_Coordinate[i+2][j+2]<=0){
            To_Move[i+2][j+2]=10;}
        if(i<=6&&j-2>=0&&Chessman_Coordinate[i+2][j-2]<=0){
            To_Move[i+2][j-2]=10;}

        break;
    case 4://jiang

        if(i<=6&&j<=8&&Chessman_Coordinate[i+1][j]==0&&Chessman_Coordinate[i+2][j+1]<=0){
            To_Move[i+2][j+1]=10;}
        if(i>=1&&j<=7&&Chessman_Coordinate[i][j+1]==0&&Chessman_Coordinate[i-1][j+2]<=0){
            To_Move[i-1][j+2]=10;}
        if(i<=7&&j<=7&&Chessman_Coordinate[i][j+1]==0&&Chessman_Coordinate[i+1][j+2]<=0){
            To_Move[i+1][j+2]=10;}
        if(i<=6&&j>=1&&Chessman_Coordinate[i+1][j]==0&&Chessman_Coordinate[i+2][j-1]<=0){
            To_Move[i+2][j-1]=10;}
        if(i>=2&&j>=1&&Chessman_Coordinate[i-1][j]==0&&Chessman_Coordinate[i-2][j-1]<=0){
            To_Move[i-2][j-1]=10;}
        if(i<=7&&j>=2&&Chessman_Coordinate[i][j-1]==0&&Chessman_Coordinate[i+1][j-2]<=0){
            To_Move[i+1][j-2]=10;}
        if(i>=2&&j<=8&&Chessman_Coordinate[i-1][j]==0&&Chessman_Coordinate[i-2][j+1]<=0){
            To_Move[i-2][j+1]=10;}
        if(i>=1&&j>=2&&Chessman_Coordinate[i][j-1]==0&&Chessman_Coordinate[i-1][j-2]<=0){
            To_Move[i-1][j-2]=10;}

        break;

    case 5:
        for(int x=1;x<=8;x++)
        {//ju
            if(i+x<=8&&Chessman_Coordinate[i+x][j]==0){
                To_Move[i+x][j]=10;}
            else  if(i+x<=8&&Chessman_Coordinate[i+x][j]<0)
            {
                To_Move[i+x][j]=10;
                break;
            }
            else  break;
        }
        for(int x=1;x<=8;x++)
        {
            if(i-x>=0&&Chessman_Coordinate[i-x][j]==0){
                To_Move[i-x][j]=10;}
            else  if(i-x>=0&&Chessman_Coordinate[i-x][j]<0)
            {
                To_Move[i-x][j]=10;
                break;
            }
            else  break;
        }
        for(int x=1;x<=9;x++)
        {
            if(j+x<=9&&Chessman_Coordinate[i][j+x]==0){
                To_Move[i][j+x]=10;}
            else  if(j+x<=9&&Chessman_Coordinate[i][j+x]<0)
            {
                To_Move[i][j+x]=10;
                break;
            }
            else  break;
        }
        for(int x=1;x<=9;x++)
        {
            if(j-x>=0&&Chessman_Coordinate[i][j-x]==0){
                To_Move[i][j-x]=10;}
            else  if(j-x>=0&&Chessman_Coordinate[i][j-x]<0)
            {
                To_Move[i][j-x]=10;
                break;
            }
            else  break;
        }

        break;
    case 6://pao
        Is_Skip=false;
        for(int x=1;x<=8;x++)
        {
            if(i+x<=8&&Chessman_Coordinate[i+x][j]==0&&!Is_Skip){
                To_Move[i+x][j]=10;}
            else  if(i+x<=8&&Chessman_Coordinate[i+x][j]!=0&&!Is_Skip)
            {
                Is_Skip=true;
            }
            else if(i+x<=8&&Chessman_Coordinate[i+x][j]<0&&Is_Skip)
            {
                To_Move[i+x][j]=10;
                break;
            }
        }
        Is_Skip=false;
        for(int x=1;x<=8;x++)
        {
            if(i-x>=0&&Chessman_Coordinate[i-x][j]==0&&!Is_Skip){
                To_Move[i-x][j]=10;}
            else  if(i-x>=0&&Chessman_Coordinate[i-x][j]!=0&&!Is_Skip)
            {
                Is_Skip=true;
            }
            else if(i-x>=0&&Chessman_Coordinate[i-x][j]<0&&Is_Skip)
            {
                To_Move[i-x][j]=10;
                break;
            }
        }
        Is_Skip=false;
        for(int x=1;x<=9;x++)
        {
            if(j+x<=9&&Chessman_Coordinate[i][j+x]==0&&!Is_Skip){
                To_Move[i][j+x]=10;}
            else  if(j+x<=9&&Chessman_Coordinate[i][j+x]!=0&&!Is_Skip)
            {
                Is_Skip=true;
            }
            else if(j+x<=9&&Chessman_Coordinate[i][j+x]<0&&Is_Skip)
            {
                To_Move[i][j+x]=10;
                break;
            }
        }
        Is_Skip=false;
        for(int x=1;x<=9;x++)
        {
            if(j-x>=0&&Chessman_Coordinate[i][j-x]==0&&!Is_Skip){
                To_Move[i][j-x]=10;}
            else  if(j-x>=0&&Chessman_Coordinate[i][j-x]!=0&&!Is_Skip)
            {
                Is_Skip=true;
            }
            else if(j-x>=0&&Chessman_Coordinate[i][j-x]<0&&Is_Skip)
            {
                To_Move[i][j-x]=10;
                break;
            }
        }
        break;
    case 7://bin
        if(j<5)
        {
            To_Move[i][j+1]=10;
        }
        else
        {
            if(i>=1&&Chessman_Coordinate[i-1][j]<=0){
                To_Move[i-1][j]=10;}
            if(i<=7&&Chessman_Coordinate[i+1][j]<=0){
                To_Move[i+1][j]=10;}
            if(j<=8&&Chessman_Coordinate[i][j+1]<=0){
                To_Move[i][j+1]=10;}
        }
        break;
    case -1://the nagative value stands for black chessman

        if(i>=4&&Chessman_Coordinate[i-1][j]>=0){
            To_Move[i-1][j]=10;}
        if(i<=4&&Chessman_Coordinate[i+1][j]<=0){
            To_Move[i+1][j]=10;}
        if(j>=1&&Chessman_Coordinate[i][j+1]<=0){
            To_Move[i][j-1]=10;}
        if(i<=4&&Chessman_Coordinate[i+1][j]>=0){
            To_Move[i+1][j]=10;}
        if(j<=1&&Chessman_Coordinate[i][j+1]<=0){
            To_Move[i][j+1]=10;}
        if(i>=4&&Chessman_Coordinate[i-1][j]<=0){
            To_Move[i-1][j]=10;}
        if(j<=8&&Chessman_Coordinate[i][j+1]>=0){
            To_Move[i][j+1]=10;}
        if(j>=8&&Chessman_Coordinate[i][j-1]>=0){
            To_Move[i][j-1]=10;}
        break;
    case -2:
        if(i>=4&&j>=8&&Chessman_Coordinate[i-1][j-1]>=0){
            To_Move[i-1][j-1]=10;}
        if(i<=4&&j<=8&&Chessman_Coordinate[i+1][j+1]>=0){
            To_Move[i+1][j+1]=10;}
        if(i<=4&&j>=8&&Chessman_Coordinate[i+1][j-1]>=0){
            To_Move[i+1][j-1]=10;}
        if(i>=4&&j<=8&&Chessman_Coordinate[i-1][j+1]>=0){
            To_Move[i-1][j+1]=10;}

        break;
    case -3:

        if(i>=2&&j<=7&&Chessman_Coordinate[i-2][j+2]>=0){
            To_Move[i-2][j+2]=10;}
        if(i<=6&&j<=7&&Chessman_Coordinate[i+2][j+2]>=0){
            To_Move[i+2][j+2]=10;}
        if(i<=6&&j>=7&&Chessman_Coordinate[i+2][j-2]>=0){
            To_Move[i+2][j-2]=10;}
        if(i>=2&&j>=7&&Chessman_Coordinate[i-2][j-2]>=0){
            To_Move[i-2][j-2]=10;}

        break;
    case -4:

        if(i>=1&&j>=2&&Chessman_Coordinate[i][j-1]==0&&Chessman_Coordinate[i-1][j-2]>=0){
            To_Move[i-1][j-2]=10;}
        if(i<=6&&j<=8&&Chessman_Coordinate[i+1][j]==0&&Chessman_Coordinate[i+2][j+1]>=0){
            To_Move[i+2][j+1]=10;}
        if(i>=2&&j<=8&&Chessman_Coordinate[i-1][j]==0&&Chessman_Coordinate[i-2][j+1]>=0){
            To_Move[i-2][j+1]=10;}
        if(i<=6&&j>=1&&Chessman_Coordinate[i+1][j]==0&&Chessman_Coordinate[i+2][j-1]>=0){
            To_Move[i+2][j-1]=10;}
        if(i>=1&&j<=7&&Chessman_Coordinate[i][j+1]==0&&Chessman_Coordinate[i-1][j+2]>=0){
            To_Move[i-1][j+2]=10;}
        if(i<=7&&j<=7&&Chessman_Coordinate[i][j+1]==0&&Chessman_Coordinate[i+1][j+2]>=0){
            To_Move[i+1][j+2]=10;}
        if(i<=7&&j>=2&&Chessman_Coordinate[i][j-1]==0&&Chessman_Coordinate[i+1][j-2]>=0){
            To_Move[i+1][j-2]=10;}
        if(i>=2&&j>=1&&Chessman_Coordinate[i-1][j]==0&&Chessman_Coordinate[i-2][j-1]>=0){
            To_Move[i-2][j-1]=10;}

        break;
    case -5:
        for(int x=1;x<=8;x++)
        {
            if(i+x<=8&&Chessman_Coordinate[i+x][j]==0) To_Move[i+x][j]=10;
            else  if(i+x<=8&&Chessman_Coordinate[i+x][j]>0)
            {
                To_Move[i+x][j]=10;
                break;
            }
            else break;
        }
        for(int x=1;x<=8;x++)
        {
            if(i-x>=0&&Chessman_Coordinate[i-x][j]==0){
                To_Move[i-x][j]=10;}
            else  if(i-x>=0&&Chessman_Coordinate[i-x][j]>0)
            {
                To_Move[i-x][j]=10;
                break;
            }
            else break;
        }
        for(int x=1;x<=9;x++)
        {
            if(j+x<=9&&Chessman_Coordinate[i][j+x]==0){
                To_Move[i][j+x]=10;}
            else  if(j+x<=9&&Chessman_Coordinate[i][j+x]>0)
            {
                To_Move[i][j+x]=10;
                break;
            }
            else break;
        }
        for(int x=1;x<=9;x++)
        {
            if(j-x>=0&&Chessman_Coordinate[i][j-x]==0){
                To_Move[i][j-x]=10;}
            else  if(j-x>=0&&Chessman_Coordinate[i][j-x]>0)
            {
                To_Move[i][j-x]=10;
                break;
            }
            else break;
        }
        break;
    case -6:
        Is_Skip=false;
        for(int x=1;x<=8;x++)
        {
            if(i+x<=8&&Chessman_Coordinate[i+x][j]==0&&!Is_Skip){
                To_Move[i+x][j]=10;}
            else  if(i+x<=8&&Chessman_Coordinate[i+x][j]!=0&&!Is_Skip)
            {
                Is_Skip=true;
            }
            else if(i+x<=8&&Chessman_Coordinate[i+x][j]>0&&Is_Skip)
            {
                To_Move[i+x][j]=10;
                break;
            }
        }
        Is_Skip=false;
        for(int x=1;x<=8;x++)
        {
            if(i-x>=0&&Chessman_Coordinate[i-x][j]==0&&!Is_Skip){
                To_Move[i-x][j]=10;}
            else  if(i-x>=0&&Chessman_Coordinate[i-x][j]!=0&&!Is_Skip)
            {
                Is_Skip=true;
            }
            else if(i-x>=0&&Chessman_Coordinate[i-x][j]>0&&Is_Skip)
            {
                To_Move[i-x][j]=10;
                break;
            }
        }
        Is_Skip=false;
        for(int x=1;x<=9;x++)
        {
            if(j+x<=9&&Chessman_Coordinate[i][j+x]==0&&!Is_Skip){
                To_Move[i][j+x]=10;}
            else  if(j+x<=9&&Chessman_Coordinate[i][j+x]!=0&&!Is_Skip)
            {
                Is_Skip=true;
            }
            else if(j+x<=9&&Chessman_Coordinate[i][j+x]>0&&Is_Skip)
            {
                To_Move[i][j+x]=10;
                break;
            }
        }
        Is_Skip=false;
        for(int x=1;x<=9;x++)
        {
            if(j-x>=0&&Chessman_Coordinate[i][j-x]==0&&!Is_Skip){
                To_Move[i][j-x]=10;}
            else  if(j-x>=0&&Chessman_Coordinate[i][j-x]!=0&&!Is_Skip)
            {
                Is_Skip=true;
            }
            else if(j-x>=0&&Chessman_Coordinate[i][j-x]>0&&Is_Skip)
            {
                To_Move[i][j-x]=10;
                break;
            }
        }
        break;
    case -7:
        if(j>4)
        {
            To_Move[i][j-1]=10;
        }
        else
        {
            if(j>=1&&Chessman_Coordinate[i][j-1]>=0){
                To_Move[i][j-1]=10;}
            if(i>=1&&Chessman_Coordinate[i-1][j]>=0){
                To_Move[i-1][j]=10;}
            if(i<=7&&Chessman_Coordinate[i+1][j]>=0){
                To_Move[i+1][j]=10;}

        }
        break;
    default:  break;
    }

}


void Widget::Is_Win()
{
    Is_Gameover = true;
    int Boss_Is_Meet[4]={0,0,0,0};
    for(int i=1;i<2;i++)
    {
        for(int i=3;i<=5;i++)
        {
            for(int j=0;j<=2;j++)
            {
                if(Chessman_Coordinate[i][j]==1)
                {
                    Is_Gameover=false;
                    Boss_Is_Meet[0]=i;
                    Boss_Is_Meet[1]=j;
                }
            }
        }
        if(Is_Gameover) break;

        Is_Gameover=true;
        for(int i=3;i<=5;i++)
        {
            for(int j=7;j<=9;j++)
            {
                if(Chessman_Coordinate[i][j]==-1)
                {
                    Is_Gameover=false;
                    Boss_Is_Meet[2]=i;
                    Boss_Is_Meet[3]=j;
                }
            }
        }
        if(Is_Gameover) break;

        if(Boss_Is_Meet[0]==Boss_Is_Meet[2])
        {
            Is_Gameover=true;
            for(int i=Boss_Is_Meet[1]+1;i<Boss_Is_Meet[3];i++)
            {
                if(Chessman_Coordinate[Boss_Is_Meet[0]][i]!=0)
                {
                    Is_Gameover=false;
                    break;
                }
            }
            if(Is_Gameover==true)
            {
                Step_Number++;
            }
        }
    }
    if(Is_Gameover==true)
    {
        QString Winer=(Step_Number%2==0? "RED":"BLACK");
        Timer->stop();
        Step_Number=0;
        QMessageBox::information(this,"RESULT：",Winer+" is the WINNER!!",QMessageBox::Yes);
    }
}

void Widget::Eat_Chessman(int Eat_x, int Eat_y, int Eat_value, int Eaten_x, int Eaten_y, int Eaten_value)
{
    Step_Number++;
    if(Eaten_value==0)
    {
        Chessman_Coordinate[Eat_x][Eat_y]=0;
        Chessman_Coordinate[Eaten_x][Eaten_y]=Eat_value;
    }
    else  //(Eaten_value!=0)
    {
        Chessman_Coordinate[Eat_x][Eat_y]=0;
        Chessman_Coordinate[Eaten_x][Eaten_y]=Eat_value;
    }
    Init_Move_Array();
    Is_Win();
}
void Widget::Start_Game_Slots()
{


    Start_Game->setIcon(QIcon(":/btn/img/restart.png"));

    Clicked_X=0;
    Clicked_Y=0;

    Step_Number=0;
    Sum_Duration=0;

    Is_Gameover=false;

    Start_Game->setGeometry(600,400,120,120);
    Start_Game->setIconSize(QSize(120,120));

    Init_Array();
    this->repaint();
    Timer->start(1000);
}

void Widget::Exit_Game_Slots(){

    if(QMessageBox::Yes==QMessageBox::question(this,"warning：","Do you want to leave?",QMessageBox::No|QMessageBox::Yes))
    {
        exit(0);
    }
}
void Widget::Time_Out_Slots()
{
    Sum_Duration++;

    QString sum_time=QString("%1").arg(Sum_Duration/3600%60, 2, 10,QChar('0'))
            +":"+QString("%2").arg(Sum_Duration/60%60, 2, 10, QChar('0'))
            +":"+QString("%3").arg(Sum_Duration%60, 2, 10, QChar('0'));

    Sum_Time->setText(sum_time);
}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<10;j++)
        {
            switch (Chessman_Coordinate[i][j])
            {//paint the chessman
            case 1:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/jiang_black.png"));  break;
            case 2:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/shi_black.png"));  break;
            case 3:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/xiang_black.png"));  break;
            case 4:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/ma_black.png"));  break;
            case 5:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/ju_black.png"));  break;
            case 6:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/pao_black.png"));  break;
            case 7:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/bin_black.png"));  break;
            case -1:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/shuai_red.png"));  break;
            case -2:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/shi_red.png"));  break;
            case -3:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/xiang_red.png"));  break;
            case -4:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/ma_red.png"));  break;
            case -5:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/ju_red.png"));  break;
            case -6:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/pao_red.png"));  break;
            case -7:painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/bin_red.png"));  break;
            default:       break;
            }
            if(To_Move[i][j]==10)
            {
                painter.drawImage(QRect(15+68*i,18+68*j,40,40),QImage(":/chessman/img/to_move.png"));
            }
        }
    }
    painter.drawImage(QRect(15+68*Clicked_X,18+68*Clicked_Y,40,40),QImage(":/chessman/img/selected.png"));
}

