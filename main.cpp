#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "structures.h"
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
    ofstream fout(token, ios_base::app);
    fout.close();
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
    || action == "SLDELHEAD" || action == "SLDELTAIL" || action=="SELDEL"
    || action = "SLFIND" ) SLLactions(argv[2],token);

    if (action == "SINIT" || action == "SPUSH"
     || action == "SPOP") Sactions(argv[2],token);

    if (action=="QINIT" || action == "QPUSH" 
    || action == "QPOP") Qactions(argv[2],token);

    if (action == "HINIT" || action =="HINSERT" || action ==)

  HTactions("htables.data","HINIT mg 2");
}


//./dbms --file file.data --query 'HSET myhash key value'
//./main --file arrays.data --query 'MPUSH myArr  15'
// ./main --file slists.data --query 'SLPUSH myL  15'
// ./main --file queues.data --query 'QPUSH myL 15'