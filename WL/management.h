#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <QWidget>
#include <QIcon>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>
#include <QPainter>
#include <QImage>
#include <QTimer>
#include <QTime>
#include <ctime>
#include <QButtonGroup>
#include <QKeyEvent>
#include <QStyle>
#include <QLabel>
#include <QString>

class Management : public QWidget
{
    Q_OBJECT
public:
    explicit Management(QWidget *parent = nullptr);
    QLabel *text1;
    QLabel *text2_1;
    QLabel *text2_2;
    QLabel *text3_1;
    QLabel *text3_2;
    QLabel *text4_1;
    QLabel *text4_2;
    QLabel *text5;
    QLabel *text6_1;
    QLabel *text6_2;
    QLabel *text7_1;
    QLabel *text7_2;
    QLabel *text8_1;
    QLabel *text8_2;
    QLabel *text9_1;
    QLabel *text9_2;

private:

signals:

public slots:
};

#endif // MANAGEMENT_H
