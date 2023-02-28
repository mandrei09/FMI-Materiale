#include <iostream>
#include <string>

using namespace std;

//strucura pentru stiva de stringuri (operatori)
struct nod{
    string data;
    nod* next;
};

//strcutura pentru stiva de numere
struct numar{
    int data;
    numar* next;
};

//functii de afisare a celor 2 stive
void print_operatori(nod* head){
    while(head!=NULL){
        cout<< head->data<<' ';
        head=head->next;
    }
    cout<<endl;
}

void print_numere(numar* head){
    while(head!=NULL){
        cout<< head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

//funcii de eliminare de pe stive
nod* pop_operator(nod *head)
{
    nod *p = head;
    head=head->next;
    delete p;
    return head;
}

numar* pop_numar(numar *head)
{
    numar *p = head;
    head=head->next;
    delete p;
    return head;
}

//functii de adaugare pe stive
void push_operator(nod **cap, string data)
{
    nod *nod_nou = new nod;
    nod_nou->data = data;
    nod_nou->next = *cap;
    *cap = nod_nou;
}

void push_numar(numar **cap, int data)
{
    numar *nod_nou = new numar;
    nod_nou->data = data;
    nod_nou->next = *cap;
    *cap = nod_nou;
}

void calculate(string expresie){
    numar* numere=NULL; nod *operatori=NULL; int i,aux,ok,nr=0,elemente,minus=0; string empty; 
    
    //Deciderea numarului initial de elemente pentru a face o operatie
    if(expresie[0]=='(' || expresie[1]=='(') elemente=1;
    else elemente=2;

    for(i=0;i<expresie.length();){
        aux=0,ok=0;
        while(expresie[i]==' ')
            i++;
        while((int)expresie[i]>=48 and (int)expresie[i]<=58){
            ok=1;
            aux=aux*10+((int)(expresie[i])-48);
            i++;
        }

        //daca s-a format un numar
        if(ok==1){
            if(minus==1){
                //avem -(), adaugam toate elementele cu - pe stiva
                if(operatori->data=="(")
                    push_numar(&numere,-aux);
                else
                    //am terminat de adaugat elementele cu -
                    if(operatori->data==")")
                        minus=0;
                    else{
                        //nu avem (), se adauga un singur numar cu -
                        push_numar(&numere,-aux);
                        minus=0;
                    }
            }
            //se adauga numarul nemodificat
            else push_numar(&numere,aux);
            nr++;
        }

        //verificare operatori
        if(nr>=elemente)
            if(operatori->data=="+"){
                aux=numere->data;
                numere=pop_numar(numere); nr--;
                numere->data+=aux;
                operatori=pop_operator(operatori);
            }
            else
                if(operatori->data=="-"){
                    aux=numere->data;
                    numere=pop_numar(numere); nr--;
                    numere->data-=aux;
                    operatori=pop_operator(operatori);
                }
        
        //adaugare operatori
        empty=""; 
        empty.push_back(expresie[i]); 

        push_operator(&operatori,empty);

        //tratam cazul -()+...
        if(operatori->data=="-" && numere==NULL)
            minus=1;

        //cand apelam pop de 2 ori o sa se scoata de pe stiva ambele paranteze ()
        if(operatori->data==")"){
            operatori=pop_operator(operatori);
            operatori=pop_operator(operatori);
            if(elemente!=2) elemente--;
        }
        else
            if(operatori->data=="(")
                elemente++;
        i++;
}

    //a ramas un singur numar pe stiva, rezultatul
    if(nr==1)
        cout<<"Rezultatul expresiei este:"<<numere->data<<endl;
    else{
        //au ramas 2 numere pe stiva, se va executa ultima operatie
        if(operatori->data=="+"){
            aux=numere->data;
            numere=pop_numar(numere); nr--;
            numere->data+=aux;
            operatori=pop_operator(operatori);
        }
        else
            if(operatori->data=="-"){
                aux=numere->data;
                numere=pop_numar(numere); nr--;
                numere->data-=aux;
                operatori=pop_operator(operatori);
            }

        cout<<"Rezultatul expresiei este:"<<numere->data<<endl;
    }
}
int main(){
    string expresie;
    cout<<"Dati expresia:\n";
    getline(cin,expresie);
    calculate(expresie);
    return 0;
}