#pragma once
#include <iostream>
#include <sstream>
using namespace std;
#include "structures.h"

void Qactions(const string& file_name,const string& query) {
    stringstream ss(query);
    string token;
    string action;
    getline(ss,token,' ');
    action=token;
        Queue<string>* queue;
        getline (ss,token,' ');
        string con_name=token;



    if (action=="QINIT"){
        cout << token<< endl;
        getline(ss,token,' ');
        cout << token << endl;
        queue =queue->QINIT(file_name, con_name);
        queue->QOUT(file_name,con_name);
        return;
    } else {
        try{ queue = queue->QGET(file_name,con_name);}
        catch(exception& ex){
            cerr <<ex.what()<<endl;
            return;
        }
    }
    if (action == "QPUSH"){
        getline(ss,token,' ');
        queue->QPUSH(token);
        queue->QOUT(file_name,con_name);
        return;
    }
    if (action == "QPOP") {
        try {
        auto val = queue->QPOP();
        cout << "Poped value -> " <<val<<endl;
        queue->QOUT(file_name, con_name);
        }catch(exception& ex){
            cerr<< ex.what() << endl;
            return;
        }

        return;
    }

}