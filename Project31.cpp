#include <iostream>
#include "FwdList.h"
using namespace std;

int main()
{
    FwdList<int> list;

    for(size_t i = 0; i < 5; i++) {
        list.addHead(rand()%10);
    }
    list.print();
    
    /*cout << endl;
    for(size_t i = 0; i < 10; i++) {
        list.removeHead();
        list.print();
    }
        list.removeHead();*/
    for (size_t i = 0; i < 5; i++) {
        list.removeTail();
        list.print();
    }
    list.print();
}