#ifndef CALENDAR_H
#define CALENDAR_H

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

class Calendar : public QWidget
{
    Q_OBJECT
public:
    explicit Calendar(QWidget *parent = nullptr);
    QPushButton *cal;
signals:

public slots:
};

#endif // CALENDAR_H
