#pragma once
#include <iostream>
#include "node.h"
using namespace std;

struct QUEUE{
    Node* first;
    Node* last;
    QUEUE() : first(nullptr),last(nullptr){}
    Node* QPOP() {
        if (first==nullptr) return;
        Node* temp=first;
        first=first->next;
        if(first==nullptr) last=nullptr; 
        return temp ;
    }
    void QPUSH(const int& _data) {
        Node* newNode=new Node(_data);
        if (first == nullptr){
            first=last=newNode;
        }
        last->next=newNode;
        last=newNode;
    }

};