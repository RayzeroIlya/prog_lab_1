#include <iostream>
using namespace std;
#include "array.h"


int main(){
    Array myArray;
    myArray.size=2;
    myArray.arr=new int[myArray.size];
    myArray.MINSERT(0,9);
    myArray.MINSERT(1,15);
    for (int i=0;i<myArray.size;i++) cout << myArray.arr[i] << " ";
    myArray.MPUSH(27);
    cout <<endl;
        for (int i=0;i<myArray.size;i++) cout << myArray.arr[i] << " ";
    cout <<endl;
    cout << myArray.AT(1) << endl;

    myArray.MDELETEAT(1);
    for (int i=0;i<myArray.size;i++) cout <<myArray.arr[i] << " ";
    cout << endl;
    cout << myArray.SIZE();
}