#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Mactions.h"
#include "SLLactions.h"
#include "Qactions.h"
#include "HTactions.h"
#include "Sactions.h"
int main(int argc, char** argv){
  
   cout <<argv[0]<<endl;
    string token=argv[1];
    if (token!="--file") {
        cout <<"Ошибка синтаксиса флаг --file" << endl;
        return 0;}
    token =argv[2];
    token=argv[3];
    if (token!="--query"){
         cout <<"Ошибка синтаксиса флаг --query" << endl;
        return 0;
    }
    token=argv[4];
    cout << token<<endl;
    stringstream ss(token);
    string action;
    getline(ss,action,' ');

    if (action == "MINIT" || action == "MINSERT" || action == "MPUSH"
    || action == "MAT" || action == "MSIZE") Mactions(argv[2],token);

    if (action == "SLINIT" || action == "SLINSERT" || action == "SLPUSH"
    || action == "SLDELHEAD" || action == "SLDELTAIL" || action=="SELDEL" || action == "SLFIND" ) SLLactions(argv[2],token);

    if (action == "SINIT" || action == "SPUSH"
     || action == "SPOP") Sactions(argv[2],token);

    if (action=="QINIT" || action == "QPUSH" 
    || action == "QPOP") Qactions(argv[2],token);

    if (action == "HINIT" || action =="HINSERT" || action =="HGET"
    || action == "HREMOVE") HTactions(argv[2],token);

    if (action == "PRINT"){
        string row;
        string name;
        string file_name=argv[2];
        if (file_name=="htables.data") {
            getline(ss,name,' ');
            cout << file_name << endl;
            ifstream fin(name+"|"+file_name);
            cout << "HTable name-> " << token << endl;
            while(getline(fin,row)) cout << row << endl; 
            fin.close();
            return 0;
        }
        ifstream fin(argv[2]);
        while(getline(fin,row)) cout << row << endl; 
        fin.close();
    }



}


//./dbms --file file.data --query 'HSET myhash key value'
//./main --file arrays.data --query 'MPUSH myArr  15'
// ./main --file slists.data --query 'SLPUSH myL  15'
// ./main --file queues.data --query 'QPUSH myL 15'
// ./main --file htables.data --query 'HINIT test'
// ./main --file stacks.data --query 'SPUSH myS test'