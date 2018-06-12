#include "widget.h"
#include "ui_widget.h"
#include "calculatepos.h"
#include <QtMath>
#include <QPainter>
#include "datareceive.h"

LinkList li;
int num = 0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("动态物体定位与跟踪系统");
    dataReceive *dr = new dataReceive;
    QObject::connect( dr, SIGNAL(update()), this, SLOT(mySlot()) );

}
Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_clicked()
{
    QString pos1 = ui->lineEdit_2->text();
    QString pos2 = ui->lineEdit_3->text();
    bool ok;
    if(pos1.toInt(&ok,10)>=0&&pos1.toInt(&ok,10)<=500)
    {
        ui->label_5->setGeometry(620+pos1.toInt(&ok,10),160,31,16);
        qDebug("数值合理");
    }
    else
    {
        ui->label_5->setGeometry(620+0,160,31,16);
        qDebug("数值越界");
        ui->label_8->setText("天线位置数值越界");
    }
    if(pos2.toInt(&ok,10)>=0&&pos2.toInt(&ok,10)<=500)
    {
        ui->label_4->setGeometry(620+pos2.toInt(&ok,10),160,31,16);
        qDebug("数值合理");
    }
    else
    {
        ui->label_4->setGeometry(620+0,160,31,16);
        qDebug("数值越界");
        ui->label_8->setText("天线位置数值越界");
    }

    QString ip;
    ip = ui->lineEdit->text();
    std::string s = ip.toStdString();
    char b[13] ;
    strcpy(b,s.c_str());
    //connectRes =NrClientSDK_NewReader(b);
    connectRes = dr->init(ip);
    qDebug("c");

    if(connectRes == 0)
    {
        ui->label_2->setText("连接成功");
        qDebug("IP地址正确");
        //changeTable();

    }
    else
        {
        ui->label_2->setText("连接失败");
        qDebug("IP地址错误");
        }

}

void Widget::changeTable()
{
    int datalen;
    unsigned long ss,cc,ii;
    int dd;
    QString ds;

    //LinkList li = dr.getList();
    datalen = li.Length();
    ds = QString::number(li.Length(),10);

    ui->label_2->setText(ds);

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(datalen);
    ui->tableWidget->setShowGrid(true);
    QStringList headerLabels;
    headerLabels << "卡号" << "基站"<< "距离"<< "欠压"<< "在线时间";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    if(datalen != 0)
    {
    for(datalen;datalen >= 0; datalen--)
    {
        li.GetElem(datalen,&ss,&cc,&ii,&dd);
        ui->tableWidget->setItem(datalen,0,new QTableWidgetItem(QString::number(cc,10)));
        ui->tableWidget->setItem(datalen,1,new QTableWidgetItem(QString::number(ss,10)));
        ui->tableWidget->setItem(datalen,2,new QTableWidgetItem(QString::number(dd,10)));
        ui->tableWidget->setItem(datalen,3,new QTableWidgetItem(QString::number(ii,10)));
    }
    //ui->tableWidget->sortByColumn(0,Qt::AscendingOrder);
    }

    datalen = li.Length();
    unsigned long ss1,cc1,ii1;
    unsigned long ss2,cc2,ii2;
    int dd1,dd2;
    double x,y;
    calculatePos cp;
    QFont ft;
    ft.setPointSize(12);
    ui->label_38->setFont(ft);
    ui->label_39->setFont(ft);
    ui->label_58->setFont(ft);
    //painter.translate(-width()/2., -height()/2.);
   // painter.setPen(Qt::red);
    if(datalen != 0)
    {
    for(int i = 0;i < datalen; i=i+2)
    {
        li.GetElem(i,&ss1,&cc1,&ii1,&dd1);
        int i1= i+1;
        li.GetElem(i1,&ss2,&cc2,&ii2,&dd2);
        /*if(dd1>600)
            dd1 = dd1/3;
        else if(dd1>400)
            dd1 = dd1/2;
        if(dd2>600)
            dd2 = dd2/3;
        else if(dd2>400)
            dd1 = dd2/2;*/

        if(ss1 == 33)
            cp.calculate(ui->label_5->x(),ui->label_4->x(),dd1,dd2,&x,&y);
        else
            cp.calculate(ui->label_4->x(),ui->label_5->x(),dd1,dd2,&x,&y);
        if(cc1 == 1801338)
            ui->label_38->setGeometry(620+x,160+y,31,16);
        if(cc1 == 1801339)
            ui->label_39->setGeometry(620+x,160+y,31,16);
        if(cc1 == 1801358)
            ui->label_58->setGeometry(620+x,160+y,31,16);

        //painter.drawText(x+620, y+160, "i m here");
    }
    }

}


void Widget::mySlot()
{
    changeTable();
}
