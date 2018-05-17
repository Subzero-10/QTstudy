#ifndef LINKLIST_H
#define LINKLIST_H

#include <QObject>

typedef struct node {
    unsigned long  slot;//基站
    unsigned long  cardNo;//卡号
    unsigned long  isLowPower;//电压
    int  distance; //距离
    struct node *next;
}NODE;

class LinkList : public QObject
{
    Q_OBJECT

public:
    LinkList();
    LinkList(LinkList &LL);
    ~LinkList();
    bool clearSqList();
    bool isEmpty() { return head == nullptr; }
    int Length();
    bool GetElem(const int &i, unsigned long *s,unsigned long *c,unsigned long *il,int *d);

    int LocateElemS(const unsigned long &s);
    int LocateElemCS(const unsigned long &c, const unsigned long &s);
    int LocateElemC(const unsigned long &c);
    int LocateElemIl(const unsigned long &il);
    int LocateElemD(const unsigned long &d);

    bool PriorElem(const int &cur_e, int *pre_e);
    bool NextElem(const int &cur_e, int *next_e);

    bool Insert(const int &i, const unsigned long  &s, const unsigned long  &c, const unsigned long  &il, const int &d);
    bool Delete(const int &i, unsigned long *s,unsigned long *c,unsigned long *il,int *d);
    bool Change(const unsigned long &c, const unsigned long &s, const int &d);
    NODE * Reverse();

    void update();

    NODE *head;

signals:
    void signal();

public slots:

};

#endif // LINKLIST_H
