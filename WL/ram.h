#ifndef RAM_H
#define RAM_H

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
#include <QPainter>
#include <QProgressBar>


class RAM : public QWidget
{
    Q_OBJECT
public:
    explicit RAM(QWidget *parent = nullptr);
private:
    QLabel *RAM_label;
    QLabel *CPU_label;
    QLabel *RAM_per;
    QLabel *CPU_per;

    QLabel *calendar_label;
    QLabel *fishjoy_label;
    QLabel *chess_label;
    QLabel *snake_label;

    QLabel *data1;
    QLabel *data2;
    QLabel *data3;
    QLabel *data4;

    QProgressBar *RAM_bar;
    QProgressBar *CPU_bar;

    QPushButton *calendar_btn;
    QPushButton *chess_btn;
    QPushButton *fishjoy_btn;
    QPushButton *dead_btn;

signals:

public slots:
};

#endif // RAM_H
