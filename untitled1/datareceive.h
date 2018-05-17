#ifndef DATARECEIVE_H
#define DATARECEIVE_H
#include "NrClientSDK.h"
#include "linklist.h"
#include <QObject>

class dataReceive : public QObject
{
    Q_OBJECT

public:
    dataReceive();
    int init(QString &ip);
    //char *version;
    //int connectRes ;

private:

signals:
    void update();

public slots:
    void mySlot();
};
extern LinkList li;
extern int num;
#endif // DATARECEIVE_H
