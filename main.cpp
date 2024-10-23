#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "structures.h"
#include "parser.h"
int main(int argc, char** argv){
    cout <<argv[0]<<endl;
    string token=argv[1];
    if (token!="--file") {
        cout <<"Ошибка синтаксиса1" << endl;
        return 0;}
    token =argv[2];
    ofstream fout(token, ios_base::app);
    //if (fout.is_open())
    fout.close();
    token=argv[3];
    if (token!="--query"){
         cout <<"Ошибка синтаксиса2" << endl;
        return 0;
    }
    token=argv[4];
    cout << token<<endl;
    actions(argv[2],token);

}


//./dbms --file file.data --query 'HSET myhash key value'
//./main --file arrays.data --query 'MINSERT myArr  15'