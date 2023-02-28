#include <iostream>
#include <map>
#include <string>
using namespace std;

void mapping(map<int,char> &dictionar){
    dictionar[1]='I';
    dictionar[5]='V';
    dictionar[10]='X';
    dictionar[50]='L';
    dictionar[100]='C';
    dictionar[500]='D';
    dictionar[1000]='M';
}

void printMap(map<int,char> dictionar){
    map<int, char>::iterator itr;
    cout << "\tINT\tROMAN\n";
    for (itr = dictionar.begin(); itr != dictionar.end(); itr++) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
}

int primaCifra(int numar){
    while(numar>9)
        numar/=10;
    return numar;
}

int stergePrimaCifra(int numar){
    int p=1,aux=0;
    while(numar>9){
        aux+=numar%10*p;
        p*=10;
        numar/=10;
    }
    return aux;
}

string intToRoman(int numar,map<int,char> dictionar){
    string roman=""; int prima,poz=0; map<int, char>::iterator itr;
    while(numar){
        //1. Verific daca numarul meu este compus dintr-o singura cifra romana.
        for (itr = dictionar.begin(); itr != dictionar.end(); itr++) {
            if(numar<itr->first) {poz=itr->first; break;}
            if(numar==itr->first){
                roman.push_back(itr->second);
                return roman;
            }
        }

        //poz este urmatoarea cifra romana mai mare decat numarul meu

        if(poz==0) poz=1000;

        //2. Numarul este compus, pentru fiecare cifra verificam:
        prima=primaCifra(numar);
        if(prima<4){
            itr=dictionar.find(poz); 
            if(poz!=1000) itr--;
            for(int i=0;i<prima;i++)
                roman.push_back(itr->second);
        }
        else
            if(prima==4){
                itr=dictionar.find(poz);
                itr--;
                roman.push_back(itr->second);
                itr++;
                roman.push_back(itr->second);
            }
            else
                if(prima==5){
                    itr=dictionar.find(poz);
                    itr--;
                    roman.push_back(itr->second);
                }
                else
                    if(prima>5 && prima<9){
                        itr=dictionar.find(poz);
                        itr--;
                        roman.push_back(itr->second);
                        prima-=primaCifra(itr->first);
                        itr--;
                        for(int i=0;i<prima;i++)
                            roman.push_back(itr->second);
                    }
                    else
                        if(prima==9){
                            itr=dictionar.find(poz);
                            itr--; itr--;
                            roman.push_back(itr->second);
                            itr++; itr++;
                            roman.push_back(itr->second);
                        }
        numar=stergePrimaCifra(numar);
    }
    return roman;
}

void printNumbers(map<int,char> dictionar){
    for(int i=1;i<4000;i++)
        cout<<i<<" : "<<intToRoman(i,dictionar)<<endl;
}

int main(){
    map<int,char> dictionar;
    mapping(dictionar);
    printMap(dictionar);
    printNumbers(dictionar);
    return 0;
}