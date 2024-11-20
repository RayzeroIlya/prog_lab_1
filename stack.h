#pragma once
#include <iostream>
#include "node.h"

template <typename T>
struct Stack{
    Node<T>* first;

    Stack() : first(nullptr){}

    void SPUSH(const T& _data) {
        Node<T>* newNode = new Node(_data);
        newNode->next=first;
        first=newNode;
        return;
    }
    T SPOP(){
        if (first == nullptr) throw runtime_error("Stack is empty");
        Node<T>* fNode=first;
        T temp=fNode->data;
        first=first->next;
        delete fNode;
        return temp;
    }
    Stack<T>* SGET(const string& file_name, const string& con_name){
        ifstream fin(file_name,ios_base::in);
        string row;
        Stack<T>* stack= new Stack<T>();
        while (getline(fin,row)){
            stringstream ss(row);
            string val;
            getline(ss,val,' ');
            if (val==con_name){
                while(getline(ss,val,' ')){
                    stack->SPUSH(val);
                }
                fin.close();
                stack->reverse();
                return stack;
            }
        }
        fin.close();
        throw runtime_error("Stack doesnt exist"); 
    }
    void SOUT (const string& file_name, const string& con_name){
        cout<< "here"<<endl;
        ifstream fin(file_name);
        ofstream fout(file_name+".tmp", ios_base::app);
        string row;
        while (getline(fin,row)){
            string name;
            stringstream ss(row);
            getline(ss,name,' ');
            if (name==con_name) continue;
            fout << row <<endl;
        }
        fout << con_name << " ";
       while(true){
        try{fout << SPOP() << " ";}
        catch(exception& ex){
        fout << endl;
        remove(file_name.c_str());
        rename((file_name+".tmp").c_str(), file_name.c_str());
        return;
        }
       }
       reverse();
    }
    Stack<T>* SINIT(const string& file_name, const string& con_name ){
        Stack<T>* stack=new Stack<T>();
        return stack;
    }


    void reverse() { 
        if (first == nullptr || first->next == nullptr) return;
 
        Node<T>* prev = nullptr; 
        Node<T>* curr = first; 
        Node<T>* next = nullptr; 
 
        while (curr != nullptr) { 
            next = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = next; 
        } 
        first = prev; 
    }
};