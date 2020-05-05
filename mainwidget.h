#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QIcon>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>
#include "gamewidget.h"

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();
private:
    QPushButton *startButton;
    QPushButton *exitButton;
    GameWidget *gamewidget;

public slots:
    void startbutton_click();
    void exitbutton_click();

};
#endif // MAINWIDGET_H
