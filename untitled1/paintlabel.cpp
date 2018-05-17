#include "paintlabel.h"
#include <QtMath>
#include <QPainter>
#include <QWidget>
#include <QtWidgets/qframe.h>


PaintLabel::PaintLabel(QWidget *parent):QLabel(parent)
{

}
void PaintLabel::paintEvent(QPaintEvent *event)
{
   /*
    * 绘制多边形 本例中直接写的六边形
    * int   count  多边形的边数
    * float radius 多边形半径
    */
   int count = 6;
   int radius = 100;

   /*
    * 注意：
    * 在使用QPainter绘图之前，必须先指定绘图设备。
    * 下方指定的是在本窗口中绘制。
    * 如果没有指定绘图设备，则在之后的绘图中将无效。
    * 指定绘图设备的方法还可以使用begin() end()组合。
    * QPainter在同一时刻，只能在一个设备上绘制，如果将其切换至另一个设备，将是无效的。
    */
   QPainter painter(this);

   //设置为抗锯齿,并且设置画笔颜色为浅灰
   painter.setRenderHint(QPainter::Antialiasing);
   painter.setPen(Qt::lightGray);

   /*
    * 绘图设备的坐标原点(0,0)在左上角，水平向右增长，垂直向下增长。
    * 首先先平移坐标原点，让原点在绘图设备的中心
    */
   painter.translate(width()/2., height()/2.);

   //开始绘制多边形，并为每个区块上色
   for (int i = 0; i < count; ++i)
   {
       //设中心点到边的垂线与半径的夹角为degree=(360/count)/2即：
       float degree = 180./count;

       //先将坐标进行旋转，然后再绘制
       painter.rotate(2 * degree);

       //设边长的一半为wid,则wid = radius*sin(degree)
       //原点到边的距离为hei，则hei = radius*cos(degree)
       //在程序中三角函数都是以弧度为基准，所以要先将角度转化成弧度。
       //头文件要包含QtMath
       float radian = qDegreesToRadians(degree);
       float wid    = radius * qSin(radian);
       float hei    = radius * qCos(radian);

       //绘制该三角区块
       QPainterPath path;
       path.lineTo(-wid, -hei);
       path.lineTo(wid, -hei);
       path.lineTo(0, 0);
       painter.drawPath(path);

       //随机生成一个颜色，作为该区块的颜色，并上色
       QColor color(qrand()%255, qrand()%255, qrand()%255, 150);
       painter.fillPath(path, color);
       QLabel::paintEvent(event);
   }
}
