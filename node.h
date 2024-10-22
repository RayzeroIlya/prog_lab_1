#pragma once
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int _data): data(_data) , next(nullptr){}

};