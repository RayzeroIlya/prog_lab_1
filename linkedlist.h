#pragma once
#include <iostream>
#include "node.h"
using namespace std;
template <typename T>
struct LinkedList{
    Node<T>* head;
    Node<T>* tail;
    LinkedList(): head(nullptr){}

    void LINSERT(const int& data){
        Node<T>* newNode = new Node(data);
        if (head == nullptr){
            head = newNode;
            tail= newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    
        return;
    }
    void LPUSH(const int& _data) {
        Node<T>* newNode = new Node(_data);
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
            Node<T> *temp=head;
            head=temp->next;
            delete temp;
    }
    void LDELTAIL(){
        if (head==nullptr) return;
        if(head==tail){
            LDELHEAD();
            return;
        }
        Node<T>* temp=head;
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
    Node<T>* one=head;
    Node<T>* two = head->next;
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
    Node<T>* LFIND(const int& _data){
        Node<T>* temp=head;
        while (temp && temp->data!=_data) temp=temp->next;
        return (temp&&temp->data==_data) ? temp : nullptr; //Если нода есть и дата равна искомой

    }
};
