#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "linklist.h"
#include "calculatepos.h"
#include "datareceive.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    char * version;
    int connectRes ;
    //void calculatePos(int pos1,int pos2, unsigned long disten1,unsigned long disten2,int *x,int *y);
    void changeTable();
    //LinkList li;
    dataReceive *dr;


private slots:
    void on_pushButton_clicked();
public slots:
    void mySlot();


private:
    Ui::Widget *ui;



};


#endif // WIDGET_H
