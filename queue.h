#pragma once
#include <iostream>
#include "node.h"
using namespace std;

struct QUEUE{
    Node* first;
    Node* last;
    QUEUE() : first(nullptr),last(nullptr){}
    int QPOP() {
        if (first==nullptr) return NULL;
        Node* fNode=first;
        int temp=fNode->data;
        first=first->next;
        if(first==nullptr) last=nullptr; 
        delete fNode;
        return temp;
    }
    void QPUSH(const int& _data) {
        Node* newNode=new Node(_data);
        if (first == nullptr){
            first=last=newNode;
        }
        last->next=newNode;
        last=newNode;
    }
    int QPEEK(){
        return first->data;
    }
};