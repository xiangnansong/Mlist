//
// Created by song on 4/12/15.
//

#ifndef MLIST_MAL_H
#define MLIST_MAL_H
class MAL{
    virtual int len()=0;
    virtual void display()=0;
    virtual int curposition()=0;
    virtual void create(int n)=0;
};
#endif //MLIST_MAL_H
