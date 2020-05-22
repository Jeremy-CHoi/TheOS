#ifndef SNAKE_H
#define SNAKE_H

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
#include <QPlainTextEdit>
#include <QProgressBar>
#include <QThread>

class Snake : public QWidget
{
    Q_OBJECT
public:
    explicit Snake(QWidget *parent = nullptr);
    QPushButton *snake;
signals:


public slots:
};

#endif // SNAKE_H
