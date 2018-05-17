#ifndef PAINTLABEL_H
#define PAINTLABEL_H
#include <QLabel>


class PaintLabel : public QLabel
{
    Q_OBJECT
public:
    explicit PaintLabel(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
};

#endif // PAINTLABEL_H
