//
// Created by song on 4/12/15.
//
#include <iostream>
#include "MAL.h"
#include "Node.h"
#ifndef MLIST_LINKLIST_H
#define MLIST_LINKLIST_H
template <class T>
class LinkList:public MAL
{
private:
    Node<T>*head,*rear,*currentptr;
    int position,size;
    Node<T>*getnode(T data);
    void freenode(Node<T>*P);
public:
    T lmin,lmax;
    int len();
    int curposition();
    ~LinkList();
    LinkList();
    LinkList(LinkList<T> &list );
    Node<T>*getrear();
    Node<T>*getfront();
    void reset(int n);
    void insertat(T data);
    void deleteat(void);
    void create(int n);
    void display();
    void change(int num,T data);
    void insertrear(T data);
    Node<T>* retpS(int a);
    int searchS(T data);
    T  &operator[](int a);
    void maxmin(int i,int j,T &min,T&max);
};


template <class T>
Node<T>* LinkList<T>::getfront()
{
    return head;
}

template <class T>
Node<T>* LinkList<T>::getrear()
{
    return rear;
}


template <class T>
LinkList<T>::LinkList()
{
    head=NULL;
    rear=NULL;
    position=0;
    size=0;
    currentptr=NULL;
    lmax=0;
    lmin=0;
}

template <class T>
int LinkList<T>::len()
{
    return size;
}

template <class T>
int LinkList<T>::curposition()
{
    return position;
}

template <class T>
Node<T>* LinkList<T>::getnode(T data)
{
    Node<T>* p=new Node<T>;
    p->next=NULL;
    p->data=data;
    size+=1;
    return p;
}

template <class T>
void LinkList<T>::freenode(Node<T> *P)
{
    delete P;
    size-=1;
}

template <class T>
void LinkList<T>::insertrear(T data)
{
    Node<T>*p= getnode(data);

    if(head==NULL)
    {
        head=rear=currentptr=p;
        size=1;
        position=0;
    }
    else
    {
        rear->next=p;
        rear=p;
        currentptr=p;
        position=size-1;
    }
}

template <class T>
void LinkList<T>::create(int n)
{
    if(n==0)
    {
        return ;
    }
    else
    {
        Node<T> *p = new Node<T>;
        head =rear=currentptr= p;
        size=1;
        position=0;
        for (int i = 1; i < n; i++)
        {
            Node<T> *rp = new Node<T>;
            rear->next=rp;
            rear=rp;
            currentptr=rear;
            size+=1;
            position+=1;
        }
    }
}

template <class T>
void LinkList<T>::reset(int n)
{
    currentptr=head;
    for (int i = 0; i < n ; i++)
    {
            currentptr = currentptr->next;
    }
    position = n;
}

template <class T>
void LinkList<T>::deleteat(void)
{
    if(currentptr==head)
    {
        Node<T>* p=head;
        head=p->next;
        freenode(p);//需delete p 吗？
    }
    else
    {
        reset(position-1);
        Node<T>*p=currentptr;
        p->next=p->next->next;
        freenode(currentptr->next);
    }
}

template <class T>
void LinkList<T>::insertat(T data)
{
    if(currentptr==head)
    {
        Node<T>*p=getnode(data);
        p->next=head;
        head=p;
    }
    else
    {
        reset(position-1);
        Node<T>*p=getnode(data);
        p->next=currentptr->next;
        currentptr->next=p;
    }
}

template <class T>
void LinkList<T>::display()
{
    std::cout<<"the position is: "<<position<<std::endl;
    std::cout<<"the count is: "<<size<<std::endl;
    Node<T>*p=head;
    for(int i=0;i<size;i++)
    {
        std::cout<<p->data<<"  ";
        p=p->next;
    }
    std::cout<<std::endl;
}

template <class T>
Node<T>* LinkList<T>::retpS(int a)
{
    reset(a);
    return currentptr;
}


template <class T>
int LinkList<T>::searchS(T data)
{
    Node<T>*p=head;
    for(int i=0;i<size;i++)
    {
        if(p->data==data)
        {
            return i;
        }
        p=p->next;
    }
    return -1;
}

template <class T>
LinkList<T>::~LinkList()
{
    Node<T>* prevPtr=head;
    currentptr=head;
    while (currentptr!=NULL)
    {
        prevPtr=currentptr;
        currentptr=currentptr->next;
        freenode(prevPtr);
    }
    currentptr=NULL;
    head=NULL;
}

template <class T>
void  LinkList<T>::change(int num, T data)
{
    reset(num);
    currentptr->data=data;
}

template <class T>
T & LinkList<T>::operator[](int a)
{
    reset(a);
    return currentptr->data;
}

template <class T>
void LinkList<T>::maxmin(int i, int j, T &min, T &max)
{
    T min1,max1;
    if(i==j)
    {
        reset(i);
        min=max=currentptr->data;
    }
    else if(i+1==j)
    {
        reset(i);
        if(currentptr->data > currentptr->next->data)
        {
            max=currentptr->data;
            min=currentptr->next->data;
        }
        else
        {
            min=currentptr->data;
            max=currentptr->next->data;
        }
    }
    else
    {
        maxmin(i,i+j/2,min,max);
        maxmin(i+j/2+1,j,min1,max1);
        if(min>min1)
        {
            min=min1;
        }
        if(max<max1)
        {
            max=max1;
        }
    }
}




#endif //MLIST_LINKLIST_H
