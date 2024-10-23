#pragma once
#include <iostream>
#include "node.h"

template <typename T>
struct Stack{
    Node<T>* first;

    Stack() : first(nullptr){}

    void SPUSH(const int& _data) {
        Node<T>* newNode = new Node(_data);
        newNode->next=first;
        first=newNode;
    return;
    }
    int SPOP(){
        if (first == nullptr) throw "Stack is empty";
        Node<T>* fNode=first;
        int temp=fNode->data;
        first=first->next;
        delete fNode;
        return temp;
    }
};