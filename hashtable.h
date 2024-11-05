#pragma once
#include <iostream>
#include "linkedlist.h"
using namespace std;


template <typename Key, typename Value>
struct HashTable{
    HNode<Key,Value>** table;

    int size;

    HashTable<Key,Value>(size_t _capacity ) : size (_capacity){
        table= new HNode<Key,Value>*[size];
        for (size_t i =0;i<size;i++){
            table[i]=nullptr;
            
        }
    }

        ~HashTable() {  //Деструктор
        for (size_t i = 0; i < size; ++i) {
            HNode<Key,Value>* current = table[i];
            while (current != nullptr) {
                HNode<Key,Value>* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] table;
    }
    size_t hash(const Key& key){
        return stoi(key) % size;
    }
    HashTable<Key,Value>* HINIT(const int& size){
        HashTable<Key,Value>* newTable = new HashTable<Key,Value>(size);
        return newTable;
    }
    void HINSERT(const Key& key, const Value& value) {
        int index=hash(key);
        HNode<Key,Value>* current = table[index];
        while(current) {
            if (current->key==key){
                current->value=value;
                //cout << "Key exists" <<endl;
                return;
            }
            current=current->next;
        }  
        HNode<Key,Value>* newHNode = new HNode(key,value);
        newHNode->next=table[index];
        table[index]=newHNode;
    }
    Value HGETAT(const Key& key){
        size_t index=hash(key);
        HNode<Key,Value>* current = table[index];
        while (current) {
            if (current->key == key) {
                return current->value;

            }
            current=current->next;
        }
        throw out_of_range("Такого ключа нет");
    }
    void HDEL(const Key& key){
        int index=hash(key);
        HNode<Key,Value>* current = table[index];
        HNode<Key,Value>* prev = nullptr;
        while (current){
            if (current->key == key){
                if (prev== nullptr) {
                    table[index]=current->next;
                } else {
                    prev->next=current->next;
                }
                delete current;
                return;
            }
            prev=current;
            current=current->next;
        }
        throw out_of_range("Такого ключа нет");

    }

    
        void HOUT(const string& file_name,const string& con_name){
        ifstream fin(file_name);
        ofstream fout(file_name+".tmp", ios_base::app);
        string row;
        while (getline(fin,row)){
            string name;
            stringstream ss(row);
            getline(ss,name,' ');
                if (name==con_name) {
                    while(getline(fin,row) && row!="&%$$%&");
                    continue;
                    }
            fout << row <<endl;
        }
        fout << con_name << endl;
        fout << size << endl;
        for (size_t i=0; i<size;i++){
            fout << i <<" " << table[i] <<endl;
        }
        fout<<"&%$$%&" << endl;
        remove(file_name.c_str());
        rename((file_name+".tmp").c_str(), file_name.c_str());
        }

            HashTable<Key,Value>* HGET(const string& file_name, const string& con_name){
        ifstream fin(file_name,ios_base::in);
        string row;

        while (getline(fin,row)){
            stringstream ss(row);
            string val;
            getline(ss,val,' ');
            if (val==con_name){
                getline(fin,row); 
                stringstream ss(row);
                getline(ss,val,' ');
                int size=stoi(val);
                HashTable<Key,Value>* htable= new HashTable<Key,Value>(size);
                while(getline(fin,row) && row!="&%$$%&"){
                    stringstream ssRow(row);
                    string key;
                    getline (ssRow,key,' ');
                    getline(ssRow,val);
                    htable->table[key]= new HNode<string,string>(key,val);
                }
                fin.close();
                return htable;
            }
        }
        fin.close();
        throw runtime_error("HashTable doesnt exist"); 
    }

        HNode<Key,Value>& operator[](const Key& key){
            return table[key];
        }
};