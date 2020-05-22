#ifndef MAP_H
#define MAP_H

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

class Map : public QWidget
{
    Q_OBJECT
public:
    explicit Map(QWidget *parent = nullptr);
    QPushButton *map;
signals:

public slots:
};

#endif // MAP_H
