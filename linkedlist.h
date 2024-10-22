#pragma once
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int _data): data(_data) , next(nullptr){}

};
struct LinkedList{
    Node* head;
    Node* tail;
    LinkedList(): head(nullptr), tail(nullptr){}

    void LINSERT(const int& data){
        if (head == nullptr){
            head->data=data;
            head->next=tail;
            return;
        }
        Node* temp = head;
        head=new Node(data);
        head->next=temp;
        return;
    }

};