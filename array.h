#pragma once
#include <iostream>
using namespace std;


struct Array{
    int* arr;
    int size;


    void MINSERT (const int& index, const int& value){
                if (index < 0 || index > size) {
            cout << "Неверный индекс." << endl;
            return;
        }
      arr[index]=value;

    }
    void MPUSH(const int& value) {
      int*  newArr=new int[size+1];
      for (int i =0;i<size;i++) newArr[i]=arr[i];
      newArr[size]=value;
      delete[] arr;
      arr=newArr;
      size++;
    }

    int AT(const int& index){
        if (index < 0 || index>size){
            cout << "Неверный индекс." << endl;
            return -1;
        }
        return arr[index];

    }

    void MDELETEAT (const int& index) {
        if (index < 0 || index>size){
            cout << "Неверный индекс." << endl;
            return;
        }
        int* newArr=new int[size-1];
        for (int i =0;i<index;i++) {
            newArr[i]=arr[i];
        }
        for (int i = index+1;i<size;i++){
            newArr[i-1]=arr[i];
        }
        delete[] arr;
        arr=newArr;
        size--;
    }
    int SIZE() {
        return size;
    }
};