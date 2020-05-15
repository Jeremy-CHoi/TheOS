#include "mainwindow.h"
#include <QMenuBar>                   //菜单栏
#include <QMenu>                      //菜单
#include <QAction>                    //菜单项
#include <QDebug>                     //输出
#include <QToolBar>                   //工具栏
#include <QPushButton>                //按钮
#include <QStatusBar>                 //状态栏
#include <QLabel>                     //标签
#include <QTextEdit>                  //文本编辑区
#include <QDockWidget>                //浮动窗口
#include <QDialog>                    //对话框
#include <QMessageBox>                //标准对话框
#include <QFileDialog>                //文件对话框

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(1000, 708);
    this->setWindowTitle("Main Window");
    this->setStyleSheet("MainWindow{border-image: url(:/images/background.jpg);}");
//    QPalette palette;
//    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/background.jpg").scaled(this->size())));
    //菜单栏
      QMenuBar *mBar = menuBar();
    //菜单-文件
      QMenu *pMenuBarAbout= new QMenu(QStringLiteral("About(&A)"));
      QAction *aActionAccounts = new QAction(QStringLiteral("Accounts"), this);
//     pActionOpen->setIcon(QIcon(":/ReplicationTool/png/open.png"));
      aActionAccounts->setShortcut(Qt::CTRL | Qt::Key_A);
      pMenuBarAbout->addAction(aActionAccounts);
//      QAction *aActionCapacity = new QAction(QStringLiteral("Capacity"), this);
//      aActionCapacity->setShortcut(Qt::CTRL | Qt::Key_C);
//      pMenuBarAbout->addAction(aActionCapacity);
      pMenuBarAbout->addSeparator();
      QAction *aActionCapacity = pMenuBarAbout->addAction("Capacity");
      aActionCapacity->setShortcut(Qt::CTRL | Qt::Key_C);
      connect(aActionCapacity,&QAction::triggered,
              [=]()
      {
           QMessageBox::about(this,"Capacity","ROM & RAM");     //about(父类,标题名，对话框内容）;
      }
              );
//      QAction *aActionStorage = new QAction(QStringLiteral("Storage"), this);
//      aActionStorage->setShortcut(Qt::CTRL | Qt::Key_S);
//      pMenuBarAbout->addAction(aActionStorage);
      QAction *aActionStorage = pMenuBarAbout->addAction("Storage");
      aActionStorage->setShortcut(Qt::CTRL | Qt::Key_S);
      connect(aActionStorage,&QAction::triggered,
              [=]()
      {
           QMessageBox::about(this,"Storage","Image & Text");
      }
              );
      pMenuBarAbout->addSeparator();
//      QAction *aActionWallpaper = new QAction(QStringLiteral("Wallpaper"), this);
//      aActionWallpaper->setShortcut(Qt::CTRL | Qt::Key_W);
//      pMenuBarAbout->addAction(aActionWallpaper);
      QAction *aActionWallpaper = pMenuBarAbout->addAction("Wallpaper");
      connect(aActionWallpaper,&QAction::triggered,
              [=]()
      {
          QString path = QFileDialog::getOpenFileName(
                      this,
                      "open",
                      "../",
                      "souce(*.cpp *.h);;"
                      "Text(*.txt);;"
                      "all(*.*)" );

          qDebug() << path;
      }
              );

      QMenu *pMenuBarLogOut= new QMenu(QStringLiteral("Log Out(&L)"));

      QAction *logout = pMenuBarLogOut->addAction("Log out your account");
      connect(logout,&QAction::triggered,
              [=]()
      {
           QMessageBox::question(this,"question","Are you sure to log out your account?",
                                 QMessageBox::Ok,QMessageBox::Cancel);     //question(父类,标题名，对话框内容）;
      }
              );

      QMenu *pMenuBarShutDown= new QMenu(QStringLiteral("Shut Down(&S)"));
      QAction *shutdown = pMenuBarShutDown->addAction("Shut down the system");
//      connect(shutdown,SIGNAL(clicked()),this,SLOT(exitb()));
      connect(shutdown,&QAction::triggered,
              [=]()
      {
           QMessageBox::question(this,"question","Are you really sure to exit?",
                                 QMessageBox::Yes,QMessageBox::Close);     //question(父类,标题名，对话框内容）;
           exit(0);
      }
              );
      mBar->addMenu(pMenuBarAbout);
      mBar->addMenu(pMenuBarLogOut);
      mBar->addMenu(pMenuBarShutDown);


//         //模态对话框
//           QAction *p1 = pFile->addAction("模态对话框");
//           connect(p1,&QAction::triggered,
//                   [=]()
//           {
//                QDialog dlg;
//                dlg.exec();
//                qDebug() << "模态对话框打开时，无法操作其他";
//           }

//                   );


//           //非模态对话框
//           pFile->addSeparator(); //添加分割线

//           QAction *p2 = pFile->addAction("非模态对话框");
//           connect(p2,&QAction::triggered,
//                   [=]()
//           {
//               QDialog *dlg = new QDialog(this);
//               dlg->setAttribute(Qt::WA_DeleteOnClose);     //防止内存泄漏，此函数的作用为关闭对话框时自动释放
//               dlg->show();
//               qDebug() << "非模态对话框打开时，可以操作其他";
//           }

//                   );


//           //关于对话框
//           pMenuBarAbout->addSeparator(); //添加分割线

//           QAction *p3 = pMenuBarAbout->addAction("关于对话框");
//           connect(p3,&QAction::triggered,
//                   [=]()
//           {
//                QMessageBox::about(this,"about","ROM:");     //about(父类,标题名，对话框内容）;
//           }

//                   );


//           //问题对话框
//           pMenuBarAbout->addSeparator(); //添加分割线

//           QAction *p4 = pMenuBarAbout->addAction("问题对话框");
//           connect(p4,&QAction::triggered,
//                   [=]()
//           {
//                QMessageBox::question(this,"question","Are you sure to exit?",QMessageBox::Ok,QMessageBox::Cancel);     //question(父类,标题名，对话框内容）;
//           }

//                   );

//           //文件对话框
//           pMenuBarAbout->addSeparator(); //添加分割线

//           QAction *p5 = pMenuBarAbout->addAction("文件对话框");
//           connect(p5,&QAction::triggered,
//                   [=]()
//           {
//               QString path = QFileDialog::getOpenFileName(
//                           this,
//                           "open",
//                           "../",
//                           "souce(*.cpp *.h);;"
//                           "Text(*.txt);;"
//                           "all(*.*)" );

//               qDebug() << path;
//           }
//                   );


    //工具栏  菜单项的快捷方式
           QToolBar *toolBar = addToolBar("toolBar");
           //工具栏添加快捷键

           toolBar->addAction(aActionAccounts);
           toolBar->addSeparator();
           toolBar->addAction(aActionCapacity);
           toolBar->addSeparator();
           toolBar->addAction(aActionWallpaper);
            //添加小控件ce
           QPushButton *b = new QPushButton(this);
           b->setText("Calender");
           toolBar->addWidget(b);
           connect(b,&QPushButton::clicked,this,&MainWindow::MySlot);

    //状态栏
//           QStatusBar *sBar = statusBar();
//           QLabel *MyLabel = new QLabel(this);
//           MyLabel->setText("第一种添加方式 ");
//           sBar->addWidget(MyLabel);
//           // addwidget从左往右添加
//           sBar->addWidget(new QLabel("addwidget从左往右添加",this));
//           sBar->addPermanentWidget(new QLabel("addPermanentWidget从右往左添加",this));

           QStatusBar *pStatusBar = statusBar();

           QLabel *pWelCome = new QLabel(QStringLiteral("   Come on let's fall in love......"));
           pStatusBar->addWidget(pWelCome);

           QProgressBar * pProgressBar = new QProgressBar();
           pProgressBar->setRange(0,100);
           pProgressBar->setValue(20);
           pProgressBar->setMaximumWidth(200);
           pStatusBar->addPermanentWidget(pProgressBar);
           pTimeLabel = new QLabel();
           pStatusBar->addPermanentWidget(pTimeLabel);

           QTimer *pTimer = new QTimer(this);
           pTimer->start(1000);
           connect(pTimer, SIGNAL(timeout()),this,SLOT(updata_time()));

//           //更新时间的槽函数中的代码
//           QDateTime currentTime = QDateTime::currentDateTime();
//           QString timeStr = currentTime.toString(QStringLiteral("yyyy年MM月dd日 hh:mm:ss"));

//           pTimeLabel->setText(timeStr);

    //文本编辑区
//           QTextEdit *MyQTE = new QTextEdit(this);
//           setCentralWidget(MyQTE);
    //浮动窗口
//           QDockWidget *dock = new QDockWidget(this);
//           addDockWidget(Qt::RightDockWidgetArea,dock);
//           //给浮动窗口添加文本编辑区
//           QTextEdit *MyDockQTE = new QTextEdit(this);
//           dock->setWidget(MyDockQTE);

           App1 = new QPushButton(this);
           App1->setIcon(QIcon(":/images/Gluttonous Snake.jpg"));
           App1->setIconSize(QSize(100,100));
           App1->setGeometry(QRect(850,80,100,100));
           App1->setFlat(true);

}

void MainWindow::MySlot(){
    qDebug() << "succeed!";
}

void MainWindow::updata_time()
{
    QDateTime cur_time = QDateTime::currentDateTime();
    QString timestr = cur_time.toString("MM/dd/yyyy hh:mm:ss");
    pTimeLabel -> setText(timestr);
}

void MainWindow::exitb(){
    if (QMessageBox::Yes == QMessageBox::question(this,"Reminder","Are you really sure to exit?",QMessageBox::Yes,QMessageBox::Close)){
        delete this;
        exit(0);
    }
}
MainWindow::~MainWindow()
{

}
