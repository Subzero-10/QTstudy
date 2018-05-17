#include "linklist.h"

LinkList::LinkList()
{
    head = nullptr;
    qDebug("success");
}
//析构函数
LinkList::~LinkList()//和清空一样
{
    NODE *p = head;
    while (head)
    {
        p = head;
        head = head->next;
        delete(p);
    }
}
bool LinkList::clearSqList()//清空函数，和析构一样
{
    NODE *p = head;
    while (head)
    {
        p = head;
        head = head->next;
        delete(p);
    }
    return true;
}
//获取链表长度
int LinkList::Length()
{
    NODE *p = head;
    int len = 0;
    while (p != nullptr)
    {
        len++;
        p = p->next;
    }
    return len;
}
bool LinkList::GetElem(const int &i, unsigned long *s, unsigned long*c, unsigned long*il, int *d)//*e是返回的元素
{
    NODE *p = head;
    int j = 0;
    while (p&&j < i)
    {
        p = p->next;
        j++;
    }
    if (p == nullptr) return false;
    *s = p->slot;
    *c = p->cardNo;
    *il = p->isLowPower;
    *d = p->distance;
    return true;
}

int LinkList::LocateElemS(const unsigned long &s)
{
    int i = 0;
    int ii = -1;
    int ic = 0;
    NODE *p = head;
    while (p != nullptr)
    {
        if (p->slot == s)
        {
            if(ic == 0)
            {
            ii =ii+i+1;
            ic++;
            }
            else
            {
              ii = ii+i*10 ;
            }
        }
        p = p->next;
        i++;
    }
    //std::cout << "表中不存在指定元素" << std::endl;
    return ii;
}
int LinkList::LocateElemC(const unsigned long &c)
{
    int i = 0;
    NODE *p = head;
    while (p != nullptr)
    {
        if (p->cardNo == c)
        {
            //qDebug("find count %02d  %07d  %d\n",s,c,i);
            return i;
        }
        else
            p = p->next;
        i++;
    }
    //std::cout << "表中不存在指定元素" << std::endl;

    return -1;
}
int LinkList::LocateElemCS(const unsigned long &c, const unsigned long &s)
{
    int i = 0;
    NODE *p = head;
    while (p != nullptr)
    {
        if (p->cardNo == c&& p->slot == s)
        {
            //qDebug("find count %02d  %07d  %d\n",s,c,i);
            return i;
        }
        else
            p = p->next;
        i++;
    }
    //std::cout << "表中不存在指定元素" << std::endl;

    return -1;
}
int LinkList::LocateElemIl(const unsigned long &il)
{
    int i = 0;
    int ii = -1;
    int ic = 0;
    NODE *p = head;
    while (p != nullptr)
    {
        if (p->isLowPower == il)
        {
            if(ic == 0)
            {
            ii =ii+i+1;
            ic++;
            }
            else
            {
              ii = ii+i*10 ;
            }
        }
        p = p->next;
        i++;
    }
    //std::cout << "表中不存在指定元素" << std::endl;
    return ii;
}
int LinkList::LocateElemD(const unsigned long &d)
{
    int i = 0;
    NODE *p = head;
    while (p != nullptr)
    {
        if (p->distance == d)
            return i;
        else p = p->next;
        i++;
    }
    //std::cout << "表中不存在指定元素" << std::endl;
    return -1;
}

bool LinkList::PriorElem(const int &cur_e, int *pre_e)
{
    NODE *p = head;
    if (p->cardNo == cur_e) return false;//是头结点，不存在上一个元素
    while (p->next != nullptr)
    {
        if (p->next->cardNo == cur_e)
        {
            *pre_e = p->cardNo;
            return true;
        }
        else
            p = p->next;
    }
    return false;//遍历完不存在或者只有一个头结点

}
bool LinkList::NextElem(const int &cur_e, int *next_e)
{
    NODE *p = head;
    if (head == nullptr || head->next == nullptr) return false;
    while (p->next != nullptr)
    {
        if (p->cardNo == cur_e)
        {
            *next_e = p->next->cardNo;
            return true;
        }
        else
            p = p->next;
    }
    return false;
}

bool LinkList::Insert(const int &i, const unsigned long &s, const unsigned long &c, const unsigned long &il, const int &d)
{
    NODE *p = head,*n;
    int j = 0;
    if (i == 0)
    {
        n = (NODE *)new NODE[1];
        n->slot = s;
        n->cardNo = c;
        n->isLowPower = il;
        n->distance = d;
        n->next = p;
        head = n;
        return true;
    }
    while (p&&j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == nullptr)
        return false;//到队尾了
    n= (NODE *)new NODE[1];
    n->slot = s;
    n->cardNo = c;
    n->isLowPower = il;
    n->distance = d;
    n->next = p->next;
    p->next = n;
    return true;
}
bool LinkList::Delete(const int &i, unsigned long *s, unsigned long*c, unsigned long*il, int *d)
{
    NODE *p = head, *n;
    if (p == nullptr) return false;
    int j = 0;
    if (i == 0)
    {
        head = head->next;
        *s = p->slot;
        *c = p->cardNo;
        *il = p->isLowPower;
        *d = p->distance;
        delete p;
        p = nullptr;
        return true;
    }
    while (p&&j < i - 1)
    {
        j++;
        p = p->next;
    }
    if (p == nullptr)
        return false;
    n = p->next;
    p->next = p->next->next;
    *s = p->slot;
    *c = p->cardNo;
    *il = p->isLowPower;
    *d = p->distance;
    delete n;
    n = nullptr;
    return true;
}

bool LinkList::Change(const unsigned long &c, const unsigned long &s, const int &d)
{
    int i = 0;

    NODE *p = head;
    while (p != nullptr)
    {
        if (p->cardNo == c&& p->slot == s)
        {
            p->distance = d;
            //qDebug("find count %02d  %07d  %d\n",s,c,i);
            return i;
        }
        else
            p = p->next;
        i++;
    }
    //std::cout << "表中不存在指定元素" << std::endl;
    //            qDebug("find count %d  %07d \n",ii,c);
    return i;
}

NODE* LinkList::Reverse()
{
    if (head == nullptr || head->next == nullptr) return head;
    NODE *p = head,*q=head->next,*r;
    head->next = nullptr;
    while (q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head = p;
    return head;
}

void LinkList::update()
{
    //qDebug("success123");
    emit signal();
}



