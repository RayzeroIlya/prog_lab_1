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
    HashTable<string,string> hTable(10);
    getline (ss,token,' ');
    string con_name=token;
    if (action == "HINIT") {
    ofstream fout(con_name+"|"+file_name);
    fout.close();
        hTable.saveToFile(con_name+"|"+file_name);
        return;
    } else {

      try{  hTable.loadFromFile(con_name+"|"+file_name);
      } catch(exception& ex) {
        cerr << ex.what() << endl;   
      }
    }
    if (action == "HINSERT"){
        string key;
        getline (ss,key,' ');
        getline(ss,token);
        hTable.HINSERT((key),token);
        hTable.saveToFile(con_name+"|"+file_name);
       return;
    }
    if (action == "HREMOVE"){
        getline(ss,token,' ');
        hTable.HREMOVE((token));
        hTable.saveToFile(con_name+"|"+file_name);
        return;
    }
    if (action =="HGET"){
        getline(ss,token,' ');
        cout << "Getted value -> " <<hTable.HGET(token);
        return;
    }

}