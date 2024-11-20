#pragma once
#include <iostream>
#include <sstream>
using namespace std;
#include "structures.h"

void Mactions(const string& file_name,const string& query) {
    ofstream fout(file_name, ios_base::app);
    fout.close();
    stringstream ss(query);
    string token;
    string action;
    getline(ss,token,' ');
    action=token;
        Array arr;
        arr.size=0;
        arr.arr=new string[0];
        getline (ss,token,' ');
        string con_name=token;
    if (action=="MINIT"){
        cout << token << endl;
        getline(ss,token,' ');
        cout << token << endl;
        arr=arr.MINIT(file_name,con_name,stoi(token));
        arr.MOUT(file_name,con_name);
        return;
    } else {
        try{ arr.MGET(file_name,con_name);
       } catch(exception& ex){
       cerr << ex.what() << endl;
       return;
       }
    }
    if (action=="MINSERT") {
        getline(ss,token,' ');
        string val;
        getline(ss,val,' ');
        arr.MINSERT(stoi(token),val);
        arr.MOUT(file_name,con_name);
        return;
    }
    if (action=="MPUSH") {
        getline(ss,token,' ');
        arr.MPUSH(token);
        arr.MOUT(file_name,con_name);
        return;
    }  
    if (action == "MAT") {
        getline(ss,token,' ');
        cout << arr.MAT(stoi(token));
    }
    if (action== "MSIZE"){
        cout << arr.MSIZE()<<endl;
    }
}