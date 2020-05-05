#include "gamewidget.h"
#define ROW 15
#define COL 18
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    score = 0;
    level = 1;
    this->setAutoFillBackground(true);
    this->resize(600,340);
    this->setWindowIcon(QIcon(":/Icon.png"));
    this->setWindowTitle("Group48 Snake");

    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/back33.png").scaled(this->size())));
    this->setPalette(palette);

    //按钮区域
    LeftButton = new QPushButton(this);
    LeftButton->setIcon(QIcon(":/left.png"));
    LeftButton->setIconSize(QSize(100,42));
    LeftButton->setGeometry(370,160,120,55);
    LeftButton->setFlat(true);

    RightButton = new QPushButton(this);
    RightButton->setIcon(QIcon(":/right.png"));
    RightButton->setIconSize(QSize(120,55));
    RightButton->setGeometry(480,160,120,55);
    RightButton->setFlat(true);

    UpButton = new QPushButton(this);
    UpButton->setIcon(QIcon(":/up.png"));
    UpButton->setIconSize(QSize(120,55));
    UpButton->setGeometry(425,110,120,55);
    UpButton->setFlat(true);

    DownButton = new QPushButton(this);
    DownButton->setIcon(QIcon(":/down.png"));
    DownButton->setIconSize(QSize(120,55));
    DownButton->setGeometry(425,210,120,55);
    DownButton->setFlat(true);

    StartButton = new QPushButton(this);
    StartButton->setIcon(QIcon(":/start.png"));
    StartButton->setIconSize(QSize(120,55));
    StartButton->setGeometry(QRect(380,265,120,55));
    StartButton->setFlat(true);

    ReturnButton = new QPushButton(this);
    ReturnButton->setIcon(QIcon(":/exit.png"));
    ReturnButton->setIconSize(QSize(120,55));
    ReturnButton->setGeometry(QRect(480,265,120,55));
    ReturnButton->setFlat(true);

    ScoreLabel=new QLabel(this);
    LevelLabel=new QLabel(this);
    ScoreLabel->setText("Score:");
    ScoreLabel->setGeometry(450,0,120,90);
    LevelLabel->setText("Level:");
    LevelLabel->setGeometry(450,30,120,90);

    ScoreLabelNumber=new QLabel(this);
    LevelLabelNumber=new QLabel(this);
    ScoreLabelNumber->setText(QString::number(score)+"分");
    ScoreLabelNumber->setGeometry(500,0,120,90);
    LevelLabelNumber->setText(QString::number(level)+"级");
    LevelLabelNumber->setGeometry(500,30,120,90);

    connect(LeftButton,SIGNAL(clicked()),this,SLOT(left_b_click()));
    connect(RightButton,SIGNAL(clicked()),this,SLOT(right_b_click()));
    connect(UpButton,SIGNAL(clicked()),this,SLOT(up_b_click()));
    connect(DownButton,SIGNAL(clicked()),this,SLOT(down_b_click()));
    connect(StartButton,SIGNAL(clicked()),this,SLOT(start_b_click()));
    connect(ReturnButton,SIGNAL(clicked()),this,SLOT(return_b_click()));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(time_out_slot()));

    qsrand(time(NULL));
    snake[0][0] = qrand()%COL;
    snake[0][1] = qrand()%ROW;
    direct = qrand()%4;

    foodx = qrand()%COL;
    foody = qrand()%ROW;
}


void GameWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    for (int i=0; i<ROW;i++){
        for (int j=0; j<COL; j++){
           painter.drawRect(QRect(20*j+15,20*i+20,20,20));
        }
    }
    //Food
    painter.drawImage(QRectF(foodx*20+15,foody*20+20,20,20),QImage(":/ys2.png"));

    //head
    switch(direct){
    case UP:
        painter.drawImage(QRectF(snake[0][0]*20+15,snake[0][1]*20+20,20,20),QImage(":/up_snake.png"));
        break;
    case DOWN:
        painter.drawImage(QRectF(snake[0][0]*20+15,snake[0][1]*20+20,20,20),QImage(":/down_snake.png"));
        break;
    case LEFT:
        painter.drawImage(QRectF(snake[0][0]*20+15,snake[0][1]*20+20,20,20),QImage(":/left_snake.png"));
        break;
    case RIGHT:
        painter.drawImage(QRectF(snake[0][0]*20+15,snake[0][1]*20+20,20,20),QImage(":/right-snake.png"));
        break;
    default:break;
    }
    //画蛇身
    for(int i=1;i<=food_count;i++){
        painter.drawImage(QRectF(snake[i][0]*20+15,snake[i][1]*20+20,20,20),QImage(":/down.png"));
    }
}

GameWidget::~GameWidget(){

}

//时间到的槽函数
void GameWidget::time_out_slot(){
    if (snake[0][0]==foodx && snake[0][1]==foody){
        foodx = qrand()%COL;
        foody = qrand()%ROW;
        food_count++;
        level = food_count/5 + 1;
        score ++;
        ScoreLabelNumber->setText(QString::number(score)+"分");
        LevelLabelNumber->setText(QString::number(level)+"级");
        timer->start(500-50*level>200? 500-50*level:200);
    }
    memcpy(snake1,snake,sizeof(snake));
    //改变蛇的坐标
    for (int i=food_count;i>0;i--){
        snake[i][0] = snake[i-1][0];
        snake[i][1] = snake[i-1][1];
    }

    switch(direct){
    case UP:
        snake[0][1]--;
        break;
    case DOWN:
        snake[0][1]++;
        break;
    case LEFT:
        snake[0][0]--;
        break;
    case RIGHT:
        snake[0][0]++;
        break;
    default:break;
    }

    if (snake[0][0]<0 || snake[0][0]>COL-1 || snake[0][1]<0 || snake[0][1]>=ROW-1){
        memcpy(snake,snake1,sizeof(snake));
        if(QMessageBox::Yes==QMessageBox::question(this,"Reminder","Game Over",QMessageBox::Yes)){
            this->close();
            delete this;
            timer->stop();
            return;
        }
    }
    //蛇咬身子
    if (food_count>=3){
        for(int i=3;i<food_count;i++){

            if(snake[0][0]==snake[i][0] && snake[0][1]==snake[i][1]){
                memcpy(snake,snake1,sizeof(snake));
                if(QMessageBox::Yes==QMessageBox::question(this,"Reminder","Game Over",QMessageBox::Yes)){
                    this->close();
                    delete this;
                    timer->stop();
                    return;
                }
            }
        }
    }

    this->update();//会重新调用painter event函数

}


void GameWidget::up_b_click(){
    direct = UP;
}

void GameWidget::down_b_click(){
    direct = DOWN;
}
void GameWidget::left_b_click(){
    direct = LEFT;
}
void GameWidget::right_b_click(){
    direct = RIGHT;
}
void GameWidget::start_b_click(){
    timer->start(500);
}
void GameWidget::return_b_click(){
    delete this;
}


