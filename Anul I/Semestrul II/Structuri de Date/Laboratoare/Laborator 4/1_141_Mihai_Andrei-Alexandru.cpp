#include <iostream>
using namespace std;

//structura cozii
struct nod{
    int data,prioritate;
    nod* next;
};

//afisarea elementelor cozii
void print_coada(nod* head){
    cout<<"Coada de prioritati este formata din elementele:\n";
    while(head!=NULL){
        cout<<head->data<<" p"<<head->prioritate<<endl;
        head=head->next;
    }
    cout<<endl;
}
//functie de adaugare a unui nod la inceputul cozii
void add_first(nod **cap, int data,int prioritate)
{
    nod *nod_nou = new nod;
    nod_nou->data = data;
    nod_nou->prioritate=prioritate;
    nod_nou->next = *cap;
    *cap = nod_nou;
}

//functie de adaugare a unui nod
nod* push(nod * head,int data,int prioritate){

    nod* nod_nou=new nod,*aux=head;
    nod_nou->data=data;
    nod_nou->prioritate=prioritate;

    //cautam locul unde trebuie adaugat noul nod in coada de prioritati
    if(head==NULL || nod_nou->prioritate<head->prioritate)
        add_first(&head,data,prioritate);
    else{
        while(aux->next!=NULL && nod_nou->prioritate>aux->next->prioritate)
            aux=aux->next;
        nod_nou->next=aux->next;
        aux->next=nod_nou;
    }
    return head;
}

//functie de stergere a nodului de prioritate maxima (primul) din coada
nod* pop(nod* head)
{
    nod *p = head;
    head=head->next;
    delete p;
    return head;
}

int main(){
    nod* coada=NULL;
    coada=push(coada,45,7);
    coada=push(coada,70,2);
    coada=push(coada,65,1);
    coada=push(coada,45,2);
    coada=push(coada,45,2);
    coada=push(coada,10,3);
    coada=push(coada,45,1);
    print_coada(coada);
    coada=pop(coada);
    print_coada(coada);
    return 0;
}