#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QApplication>
#include <QDebug>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void showFrom();
    void retranslateUi();

       QGridLayout *gridLayout;
       QSpacerItem *verticalSpacer;
       QSpacerItem *verticalSpacer_3;
       QSpacerItem *horizontalSpacer_3;
       QSpacerItem *horizontalSpacer;
       QVBoxLayout *verticalLayout;
       QHBoxLayout *horizontalLayout;
       QLabel *label;
       QLineEdit *lineEdit;
       QHBoxLayout *horizontalLayout_2;
       QLabel *label_2;
       QLineEdit *lineEdit_2;
       QHBoxLayout *horizontalLayout_3;
       QPushButton *pushButton;
       QPushButton *pushButton_2;
       QSpacerItem *horizontalSpacer_2;
       QSpacerItem *horizontalSpacer_4;
       QSpacerItem *verticalSpacer_2;
       QSpacerItem *verticalSpacer_4;

signals:
       void sendUserName(QString name);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void receive(QString name, QString pwd);
};

#endif // WIDGET_H

