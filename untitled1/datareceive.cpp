#include "datareceive.h"
#include "NrClientSDK.h"

int __stdcall event_callback(int evt, char * devIp, LNRCLIENTSDK_CARD card)
{

    switch(evt)
    {
    case EVENT_CONNECT_OK:
        printf("\r\nreader %s connect.", devIp);
        break;

    case EVENT_DISCONNECT:
        printf("\r\nreader %s disconnect.", devIp);
        break;

    case EVENT_CARD_READ:
        printf("\r\nreader %s read card : %02d %07d %04d %01d", devIp, card->slot, card->cardNo, card->distance, card->isLowPower);
        unsigned long s = card->slot;
        unsigned long c = card->cardNo;
        unsigned long il = card->isLowPower;
        int d = card->distance;

       if(li.LocateElemCS(c,s)==-1)
        {
           if(li.LocateElemC(c)==-1)
           {
              li.Insert(num,s,c,il,d);
           }
           else
           {
               int num1 = (li.LocateElemC(c)+1);
               li.Insert(num1,s,c,il,d);
           }
            num++;
            qDebug("num count   %d\n",num);
        }
        else
        {
            li.Change(c,s,d);
        }
        li.update();
        break;
    }

    return 0;
}

dataReceive::dataReceive()
{
    QObject::connect( &li, SIGNAL(signal()), this, SLOT(mySlot()) );
    qDebug("success2");

}


int dataReceive::init(QString &ip)
{
    char version[] = "1.01.180201";
    std::string s = ip.toStdString();
    qDebug("find count  :%s",s);
    char b[13] ;
    strcpy(b,s.c_str());
    NrClientSDK_Init(version,(NrClientSDK_Event_CallBack)event_callback);
    qDebug("find count  :%d",NrClientSDK_NewReader(b));//1.01.180201
    //delete version;
    return NrClientSDK_NewReader(b);
}

void dataReceive::mySlot(){
    emit update();
}
