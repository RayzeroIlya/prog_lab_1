#pragma once
#include <iostream>
#include "linkedlist.h"
using namespace std;


template <typename Key, typename Value>
struct HashTable{
    LinkedList<HNode<Key, Value>>* table[] ;
    int capacity;
    int size;

    HashTable(int _capacity = 5) : capacity (_capacity), size(0) {
        table= new LinkedList<HNode<Key,Value>>[capacity];
    }

    int hash(const Key& key){
        return key % capacity;
    }

    void HINSERT(const Key& key, const Value& value) {
        int index=hash(key);
        Node<HNode<Key,Value>>* current = table[index]->head;
        while(current) {
            if (current->data->key==key){
                current->data->value=value;
                return;
            }
            current=current->next;
        }


    table[index]->LPUSH(HNode<Key,Value>(key,value));
    size++;
    }
    Value HGETAT(const Key& key){
        int index=hash(key);
        Node<HNode<Key,Value>>* current=table[index]->head;
        while (current) {
            if (current->data->key == key) {
                return current->data->value;

            }
            current=current->next;
        }
        throw out_of_range("Такого ключа нет");
    }
    void HDEL(const Key& key){
        int index=hash(key);
        Node<HNode<Key,Value>>* current = table[index]->head;
        Node<HNode<Key,Value>>* prev = nullptr;
        while (current){
            if (current->data->key == key){
                if (prev) {
                    prev->next=current->next;
                } else {
                    table[index]->head=current->next;
                }
                delete current;
                size--;
                return;
            }
            prev=current;
            current=current->next;
        }
        throw out_of_range("Такого ключа нет");

    }

    

};