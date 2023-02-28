#include <iostream>
using namespace std;
//structura nodului
struct nod
{
    int data;
    nod *next;
    nod *prev;
};

//adaugare la inceputul listei
void add_first(nod **head, int data)
{
    nod *nou = new nod;
    nou->data = data;
    nou->next = *head;
    nou->prev = NULL;
    *head = nou;
}

//adaugare la finalul listei
void add_last(nod **head, int data)
{
    nod *nou = new nod, *last = *head;
    nou->data = data;
    nou->next = NULL;
    while (last->next != NULL)
        last = last->next;
    last->next = nou;
    nou->prev = last;
}

//creare lista din numar
nod* list_create(nod* head,int number){
    add_first(&head,number%10); number/=10;
    while(number){
        add_last(&head,number%10);
        number/=10;
    }
    return head;
}

//creare numar din lista
int list_to_number(nod* head){
    int x=0;
    while(head->next!=NULL)
        head=head->next;
    while(head!=NULL){
        x=x*10+head->data;
        head=head->prev;
    }
    return x;
}

int main()
{
    nod *headx = NULL, *heady=NULL;
    int x,y;
    cout<<"\nDati 2 numere naturale:"; cin>>x>>y;
    headx=list_create(headx,x);
    heady=list_create(heady,y);
    cout<<"\nSuma numerelor este "<<list_to_number(headx)+list_to_number(heady)<<".\n";
    return 0;
}