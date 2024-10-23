#pragma once
#include <iostream>
#include "linkedlist.h"
using namespace std;

struct HNode{
    int key;
    string value;
    HNode* next;
    HNode(const int& _key, const string& _value) :  key(_key), value(_value), next(nullptr) {}

};

struct HashTable{


};