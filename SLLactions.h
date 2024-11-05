#pragma once
#include <iostream>
#include <sstream>
using namespace std;
#include "structures.h"

void SLLactions(const string& file_name,const string& query) {
    stringstream ss(query);
    string token;
    string action;
    getline(ss,token,' ');
    action=token;
        LinkedList<string>* list;
        getline (ss,token,' ');
        string con_name=token;



    if (action=="SLINIT"){
        cout << token<< endl;
        getline(ss,token,' ');
        cout << token << endl;
        list =list->SLINIT(file_name, con_name);
        list->SLOUT(file_name,con_name);
        return;
    } else {
        try{ list = list->SLGET(file_name,con_name);}
        catch(exception& ex){
            cerr <<ex.what()<<endl;
            return;
        }



    }
    if (action=="SLINSERT") {
        getline(ss,token,' ');
        list->SLINSERT(token);
        list->SLOUT(file_name,con_name);
        return;
    }
    if (action=="SLPUSH") {
            getline(ss,token,' ');
            list->SLPUSH(token);
            
            list->SLOUT(file_name,con_name);
        return;
    }   
    if (action == "SLDELHEAD") {
        list -> SLDELHEAD();
        list->SLOUT(file_name,con_name);
        return;
    }

    if (action == "SLDELTAIL") {
        list-> SLDELTAIL();
        list->SLOUT(file_name,con_name);
        return;

    }
    if (action == "SLDEL"){
        getline(ss,token,' ');
        list->SLDEL(token);
        list->SLOUT(file_name,con_name);
        return;
    }
    if (action == "SLFIND"){
        getline(ss,token,' ');
        Node<int>* finded_val = new Node<int>();
        if (finded_val != nullptr) {
            cout << "Value finded" <<endl;
        } else cout << "Value didnt find" << endl;
        delete finded_val;
        return;
    }
}