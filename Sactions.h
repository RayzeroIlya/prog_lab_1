#pragma once
#include <iostream>
#include <sstream>
using namespace std;
#include "structures.h"

void Sactions(const string& file_name,const string& query) {
    stringstream ss(query);
    string token;
    string action;
    getline(ss,token,' ');
    action=token;
    Stack<string>* stack;
    getline (ss,token,' ');
    string con_name=token;

    if (action == "SINIT"){
        cout << "WHIHIELEL";
        stack =stack->SINIT(file_name, con_name);
        stack->SOUT(file_name,con_name);
        return;
    } else {
        try{ stack = stack->SGET(file_name,con_name);}
        catch(exception& ex){
            cerr <<ex.what()<<endl;
            return;
        }
    }
    if (action == "SPUSH"){
        getline(ss,token,' ');
        stack->SPUSH(token);
        stack->SOUT(file_name,con_name);
        return;
    }
    if (action == "SPOP") {
        try {
        auto val = stack->SPOP();
        cout << "Poped value -> " <<val<<endl;
        stack->SOUT(file_name, con_name);
        }catch(exception& ex){
            cerr<< ex.what() << endl;
            return;
        }

        return;
    }

}