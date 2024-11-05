#pragma once
#include <iostream>
#include <sstream>
using namespace std;
#include "structures.h"

void HTactions(const string& file_name,const string& query) {
    stringstream ss(query);
    string token;
    string action;
    getline(ss,token,' ');
    action=token;
    HashTable<string,string>* hTable;
    getline (ss,token,' ');
    string con_name=token;
    if (action=="HINIT"){
        getline(ss,token,' ');
        hTable =hTable->HINIT(stoi(token));
        hTable->HOUT(file_name,con_name);
        return;
    } else {
        try{ hTable = hTable->HGET(file_name,con_name);}
        catch(exception& ex){
            cerr <<ex.what()<<endl;
            return;
        }
    }
    if (action == "HINSERT"){
        string key;
        getline (ss,key,' ');
        getline(ss,token);
        hTable->HINSERT(key,token);
        hTable->HOUT(file_name,con_name);
       // for (auto i = 0;i<6;i++) cout << hTable[i][i];
    }


}