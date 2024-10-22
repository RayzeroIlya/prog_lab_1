#pragma once
#include <iostream>
#include "node.h"


struct Stack{
    Node* first;

    Stack() : first(nullptr){}

    void SPUSH(const int& _data) {
        Node* newNode = new Node(_data);
        newNode->next=first;
        first=newNode;
    return;
    }
    int SPOP(){
        if (first == nullptr) throw "Stack is empty";
        Node* fNode=first;
        int temp=fNode->data;
        first=first->next;
        delete fNode;
        return temp;
    }
};