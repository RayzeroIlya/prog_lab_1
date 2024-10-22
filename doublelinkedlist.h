#pragma once
#include <iostream>
using namespace std;

struct DNode{
    int data;
    DNode* next;
    DNode* prev;
    DNode (const int& _data) : data(_data), next(nullptr),prev(nullptr){}
};

struct DLinkedList{
    DNode* head;
    DNode* tail;

    DLinkedList():head(nullptr),tail(nullptr){}

    void DLINSERT(const int& _data){
    DNode* newNode= new DNode(_data);
    if(head==nullptr){
        head=newNode;
        tail=newNode;
        }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;

    }
    void DLPUSH(const int& _data){
    DNode* newNode= new DNode(_data);
    if(head==nullptr){
        head=newNode;
        tail=newNode;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;


    }
    void DLDELHEAD(){
        if (head==nullptr) return;
        DNode* temp=head;
        head=head->next;
        head->prev=nullptr;
        delete temp;
        return;
    }
    void DLDELTAIL(){
        if(head==nullptr) return;
        DNode* temp=tail;
        tail=tail->prev;
        tail->next=nullptr;
        delete temp;
        return;
    }
    void DLDEL(const int& _data){
        if (head==nullptr) return;
        if (head && head->data==_data) {
            DLDELHEAD();
            return;
        } else if (tail && tail->data==_data){
            DLDELTAIL();
            return;
        }
        DNode* one=head;
        DNode* two = head->next;
        while (two && two->data!=_data) { //идем пока two есть и его дата не равна искомой
            one=one->next;
            two=two->next;
        }
        if(!two) {
            cout << "Такого элемента нет"<< endl;
            return;
        }
        one->next=two->next;
        one->next->prev=one;        
        delete two;
        }
    DNode* DLFIND(const int& _data){
        DNode* temp=head;
        while (temp && temp->data!=_data) temp=temp->next;
        return (temp&&temp->data==_data) ? temp : nullptr; //Если нода есть и дата равна искомой

    }
};