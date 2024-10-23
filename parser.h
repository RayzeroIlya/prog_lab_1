#pragma once
#include <iostream>
#include <sstream>
using namespace std;
#include "structures.h"

void actions(const string& file_name,const string& query) {
    stringstream ss(query);
    string token;
    string action;
    getline(ss,token,' ');
    action=token;
            Array arr;
        arr.size=0;
        arr.arr=new int[0];
        getline (ss,token,' ');
        string con_name=token;
        arr.MGET(file_name,con_name);
        if (arr.arr==nullptr){
            cout << "Массива не существует." <<endl;
            return;
        }
    if (action=="MINIT"){
        cout << token << endl;
        getline(ss,token,' ');
        cout << token << endl;
        arr=arr.MINIT(file_name,con_name,stoi(token));
        arr.MOUT(file_name,con_name);
        return;
    }
    if (action=="MINSERT") {
        getline(ss,token,' ');
        string val;
        getline(ss,val,' ');
        arr.MINSERT(stoi(token),stoi(val));
        arr.MOUT(file_name,con_name);
        return;
    }
    if (action=="MPUSH") {
        

    }   






}