#include <iostream>
using namespace std;

//structura nodului
struct nod
{
    int data;
    nod *next;
};

//stergere
nod* node_delete(nod* head,int data){
    nod* p,*q,*l;
    p=head;
    if(head->data==data){
        head=head->next;
        delete p;
    }
    else{
        while(p->next->data!=data)
            p=p->next;
        if(p->next==NULL)
            return NULL;
        else
        { 
            q=p->next;
            l=q;
            q=q->next;
            delete l;
            p->next=q;
        }
    }
    return head;
}

//afisare
void print(nod *nod)
{
    while (nod != NULL)
    {
        cout << nod->data << ' ';
        nod = nod->next;
    }
    cout << "\n";
}

//adaugare nod la inceputul listei
void add_first(nod **cap, int data)
{
    nod *nod_nou = new nod;
    nod_nou->data = data;
    nod_nou->next = *cap;
    *cap = nod_nou;
}

//adaugare nod la finalul listei
void add_last(nod **cap, int data)
{
    nod *nod_nou = new nod, *ultim = *cap;
    nod_nou->data = data;
    nod_nou->next = NULL;
    while (ultim->next != NULL)
        ultim = ultim->next;
    ultim->next = nod_nou;
}

//adaugare nod la finalul listei
void add_after(nod* anterior, int data){
    nod* nod_nou=new nod;
    nod_nou->data=data;
    nod_nou->next=anterior->next;
    anterior->next=nod_nou;
}

//operatia de stergere a unui nod din lista
nod* list_delete(nod *head)
{
    nod *p = head;
    head=head->next;
    delete p;
    return head;
}

//1.1
void list_sort(nod* cap){
    cap = NULL;
    int v[11], i, n;
    cout<<"\nDati numarul de elemente ale listei:";
    cin >> n;
    cout<<"\nDati elementele listei:\n";
    for (i = 1; i <= n; i++)
        cin >> v[i];
    add_first(&cap, v[1]);
    for (i = 2; i <= n; i++)
        if (v[i] <= (cap->data))
            add_first(&cap, v[i]);
        else
            add_last(&cap, v[i]);
    
    cout<<"\nDupa ordonare:\n";
    print(cap);
}

//1.2
void stergere_lista(nod* cap){
    cap = NULL;
    int n, i, v[11];

    cout<<"\nDati numarul de elemente ale listei:";
    cin >> n;
    cout<<"\nDati elementele listei:\n";

    cin>>v[1];
    add_first(&cap,v[1]);
    for (i = 2; i <= n; i++)
    {
        cin >> v[i];
        add_last(&cap, v[i]);
    }
    while (cap != NULL)
        cap=list_delete(cap);
    if (cap == NULL)
        cout << "\nLista este vida\n";
    else
        cout << "\nLista NU este vida\n";
}

//1.3
void stergere_valoare(nod * cap){
    cap = NULL;
    int n, i, v[11];
    cout<<"\nDati numarul de elemente ale listei:";
    cin >> n;
    cout<<"\nDati elementele listei\n"; cin>> v[1];
    add_first(&cap,v[1]);
    for (i = 2; i <= n; i++)
    {
        cin >> v[i];
        add_last(&cap, v[i]);
    }
    int x;
    cout<<"\nDati valoarea cautata:"; cin>>x;
    cap=node_delete(cap,x);
    if(cap!=NULL){
        cout<<"Elementul "<<x<<" a fost sters din lista.\n";
        print(cap);
    }
    else cout<<"Elementul "<<x<<" nu exista in lista.";
}

int main()
{
    //Apeluri pentru problemele 1.1, 1,2 si 1.3 .
    nod* head;
    list_sort(head); 
    //stergere_lista(head);
    //stergere_valoare(head);
    return 0;
}