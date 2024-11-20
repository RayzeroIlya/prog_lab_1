#pragma once
#include <iostream>
#include "node.h"
using namespace std;
template <typename T>
struct Queue{
    Node<T>* first;
    Node<T>* last;
    Queue<T>() : first(nullptr),last(nullptr){}
    ~Queue() { 
        while (first) { 
            QPOP(); // Освобождаем память, удаляя все узлы 
        } 
    }
    T QPOP() {
        if (first==nullptr) throw runtime_error("Queue is empty");
        Node<T>* fNode=first;
        T temp=fNode->data;
        first=first->next;
        if(first==nullptr) last=nullptr; 
        delete fNode;
        return temp;
        //return fNode; //удалять после вывода когда понадобился.
    }
    void QPUSH(const T& _data) {
        Node<T>* newNode=new Node<T>(_data);
        if (first == nullptr){
            first=last=newNode;
            return;
        }
        last->next=newNode;
        last=newNode;
    }
    T QPEEK(){
        return first->data;
    }

    Queue<T>* QGET(const string& file_name, const string& con_name){
        ifstream fin(file_name,ios_base::in);
        string row;
        Queue<T>* queue= new Queue<T>();
        while (getline(fin,row)){
            stringstream ss(row);
            string val;
            getline(ss,val,' ');
            if (val==con_name){
                while(getline(ss,val,' ')){
                    queue->QPUSH(val);
                }
                fin.close();
                return queue;
            }
        }
        fin.close();
        throw runtime_error("Queeue doesnt exist");
    }

    void QOUT(const string&file_name, const string& con_name){
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
        Node<T>* cur = first;
        while (cur){
            fout << cur->data << " ";
            cur=cur->next;
        }
        fout << endl;
        remove(file_name.c_str());
        rename((file_name+".tmp").c_str(), file_name.c_str());
    }
    Queue<T>* QINIT (const string& file_name, const string& con_name){
        ofstream fout (file_name, ios_base::app);
        Queue<T>* queue=new Queue<T>();
        return queue;
    }
};