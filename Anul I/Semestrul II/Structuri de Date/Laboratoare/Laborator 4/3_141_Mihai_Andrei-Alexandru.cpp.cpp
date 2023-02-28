#include <iostream>

using namespace std;

//strucura pentru stiva
struct nod{
    int data;
    nod* next;
};

//afisarea elementelor stivei
void print_stack(nod* head){
    while(head!=NULL){
        cout<< head->data<<' ';
        head=head->next;
    }
    cout<<endl;
}

//scoaterea unui element de pe stiva
nod* pop(nod *head)
{
    nod *p = head;
    head=head->next;
    delete p;
    return head;
}

//adaugarea unui element pe stiva
void push(nod **cap, int data)
{
    nod *nod_nou = new nod;
    nod_nou->data=data;
    nod_nou->next = *cap;
    *cap = nod_nou;
}

int main(){

    //trebuie sa avem o structura de tipul (()(()))()() pentru ceva valid
    //daca avem de exemplu ( ( )(()), invalid pentru a doua paranteza
    
    int n,v[15],i,Min,Max;
    cout<<"Dati numarul de pini:";
    cin>>n;
    cout<<"Dati lista de perechi:\n";
    for(i=1;i<=n;i++)
        cin>>v[i];
    cout<<endl;

    nod* stack=NULL;
    push(&stack,v[1]); Min=Max=v[1];

    for(i=2;i<=n;i++){

        push(&stack,v[i]);

        if(stack->data>Max) Max=stack->data;
            else
                if(stack->data==Max){
                    stack=pop(stack);
                    stack=pop(stack);
                    if(stack!=NULL)
                        Max=stack->data;
                    else Max=0;
                }
                else 
                    if(stack->data==Min){
                        cout<<"Invalid.";
                        break;
                    }
    }

    if(stack==NULL) cout<<"Valid.";
    return 0;
}