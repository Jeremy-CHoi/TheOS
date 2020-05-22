#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIcon>
#include <QBrush>
#include <QLabel>

#include <QSize>
#include <QVBoxLayout>

#include <QWidget>
#include <QIcon>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>
#include "classicview.h"
#include "gamewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    QLabel *title;
    QPushButton *start_btn;
    QPushButton *exit_btn;
    QVBoxLayout *vboxlayout;

//    classicview *classic;
    GameWidget game;
public slots:
    void start_btn_click();
    void exit_btn_click();
};
#endif // MAINWINDOW_H
