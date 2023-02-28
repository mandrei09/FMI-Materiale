#include <iostream>
using namespace std;
//structura nodului
struct nod
{
    int data;
    nod *next;
};

//afisare lista circulara
void print(nod *head)
{
    nod *aux = head;
    cout << aux->data << ' ';
    aux = aux->next;
    while (aux != head)
    {
        cout << aux->data << ' ';
        aux = aux->next;
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
    while (ultim->next != *cap)
        ultim = ultim->next;
    ultim->next = nod_nou;
    nod_nou->next = *cap;
}

//lista circulara ==> 2 liste circulare
void impartire(nod *head, nod **head1, nod **head2)
{
    nod *slow = head, *fast = head, *aux1, *aux2;

    //determinam prin fast si slow pozitiile de start 
    //ale celor 2 liste
    while (fast->next != head)
    {
        fast = fast->next;
        if (fast->next != head)
            fast = fast->next;
        slow = head->next;
    }
    if (fast->next == head)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // cout<<fast->data<<' '<<slow->data;

    //prima lista: de la fast pana la nodul precedent lui slow
    head = fast;
    aux1 = NULL;
    add_first(&aux1, fast->data);
    aux1->next = aux1;
    head = head->next;
    while (head != slow)
    {
        add_last(&aux1, head->data);
        head = head->next;
    }

    //a doua lista: de la slow pana la nodul precedent lui fast
    aux2 = NULL;
    add_first(&aux2, slow->data);
    aux2->next = aux2;
    head = head->next;
    while (head != fast)
    {
        add_last(&aux2, head->data);
        head = head->next;
    }

    //returnam adresa head-ului pentru fiecare lista
    *head1 = aux1;
    *head2 = aux2;
}

int main()
{
    nod *head = NULL;
    int n, i, v[11];

    //creare lista circulara
    cout << "\nDati numarul de elemente ale listei:";
    cin >> n;
    cout << "Dati elementele listei:\n";
    cin >> v[1];
    add_first(&head, v[1]);
    head->next = head;
    for (i = 2; i <= n; i++)
    {
        cin >> v[i];
        add_last(&head, v[i]);
    }

    //impartire in 2 liste circulare
    nod *head1, *head2;
    impartire(head, &head1, &head2);

    cout<<"\nPrima lista:\n";
    print(head1);
    cout<<"\nA doua lista:\n";
    print(head2);

    return 0;
}