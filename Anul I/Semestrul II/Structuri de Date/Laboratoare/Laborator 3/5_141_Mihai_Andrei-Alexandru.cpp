#include <iostream>
using namespace std;
//structura nodului
struct nod
{
    int data;
    nod *next;
};

//afisare lista
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
void add_first(nod **head, int data)
{
    nod *nod_nou = new nod;
    nod_nou->data = data;
    nod_nou->next = *head;
    *head = nod_nou;
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

//operatia de stergere, neavand acces la nodul initial
void stergere_fara_head(nod *nod_de_sters)
{
    nod *aux = nod_de_sters->next;
    nod_de_sters->data = aux->data;
    nod_de_sters->next = aux->next;
    delete aux;
}

int main()
{
    //creare lista
    nod *head = NULL;
    int n, i, v[11];
    
    cout << "\nDati numarul de elemente ale listei:";
    cin >> n;
    cout << "\nDati elementele listei\n";
    cin >> v[1];
    add_first(&head, v[1]);
    for (i = 2; i <= n; i++)
    {
        cin >> v[i];
        add_last(&head, v[i]);
    }

    cout << "\nInainte de stergere:\n";
    print(head);
    stergere_fara_head(head->next);
    cout << "\nDupa stergere:\n";
    print(head);
}