#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct Node{
    T data;
    Node<T>* next;
    Node(T _data): data(_data) , next(nullptr){}

};
template <typename Key, typename Value>
struct HNode{
    Key key;
    Value value;
    HNode* next;
    HNode(const Key& _key, const Value& _value) :  key(_key), value(_value), next(nullptr) {}

};