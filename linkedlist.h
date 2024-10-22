#pragma once
#include <iostream>
#include "node.h"
using namespace std;

struct LinkedList{
    Node* head;
    Node* tail;
    LinkedList(): head(nullptr){}

    void LINSERT(const int& data){
        Node* newNode = new Node(data);
        if (head == nullptr){
            head = newNode;
            tail= newNode;
            return;
        }
        Node* temp=head;
        head=newNode;
        head->next=temp;
        return;
    }
    void LPUSH(const int& _data) {
        Node* newNode = new Node(_data);
                if (head == nullptr){
            head = newNode;
            tail= newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
        return;
    }
    void LDELHEAD(){
            if (head == nullptr) return;
            Node *temp=head;
            head=temp->next;
            delete temp;
    }
    void LDELTAIL(){
        if (head==nullptr) return;
        if(head==tail){
            LDELHEAD();
            return;
        }
        Node* temp=head;
        while (temp->next!=tail) temp=temp->next;
        temp->next=nullptr;
        delete tail;
        tail=temp;
    }
    void LDEL(const int& _data){
        if (head==nullptr) return;
        if(head==tail && head->data==_data){
            LDELHEAD();
            return;
        }else if (tail->data==_data){
            LDELTAIL();
            return;
        }
    Node* one=head;
    Node* two = head->next;
    while (two && two->data!=_data) { //идем пока two есть и его дата не равна искомой
        one=one->next;
        two=two->next;
    }
    if(!two) {
        cout << "Такого элемента нет"<< endl;
        return;
    }
    one->next=two->next;
    delete two;
    }
    Node* LFIND(const int& _data){
        Node* temp=head;
        while (temp && temp->data!=_data) temp=temp->next;
        return (temp&&temp->data==_data) ? temp : nullptr; //Если нода есть и дата равна искомой

    }
};
