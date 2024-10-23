#pragma once
#include <iostream>
#include "node.h"
using namespace std;
template <typename T>
struct QUEUE{
    Node<T>* first;
    Node<T>* last;
    QUEUE() : first(nullptr),last(nullptr){}
    int QPOP() {
        if (first==nullptr) throw "Queue is empty";
        Node<T>* fNode=first;
        int temp=fNode->data;
        first=first->next;
        if(first==nullptr) last=nullptr; 
        delete fNode;
        return temp;
        //return fNode; //удалять после вывода когда понадобился.
    }
    void QPUSH(const int& _data) {
        Node<T>* newNode=new Node(_data);
        if (first == nullptr){
            first=last=newNode;
        }
        last->next=newNode;
        last=newNode;
    }
    T QPEEK(){
        return first->data;
    }
};