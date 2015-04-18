#include <iostream>
#include "LinkList.h"
using namespace std;
LinkList<int>list;
int main()
{
   /* int num;
    cout<<"input num： ";
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int a(rand()%100);
        list.insertrear(a);
    }
    list.display();*/
    int num=10;
    //cin>>num;
    list.create(num);
    //list.display();
    for(int i=0;i<num;i++)
    {
        list.change(i,i);
    }
    list.display();
    cout<<list.searchS(3)<<endl;
    list.reset(5);
    list.insertat(100);
    list.display();
    cout<<list[4]<<endl;
    cout<<"test: ";
    list.maxmin(0,list.len(),list.lmin,list.lmax);

    cout<<list.lmin<<"  "<<list.lmax<<endl;
    return 0;
}
