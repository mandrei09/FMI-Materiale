#include <iostream>
using namespace std;
//structura nodului
struct nod
{
    int grad, coef;
    nod *next;
};

//adauga un nod la inceputul listei
void add_first(nod **head, int grad, int coef)
{
    nod *nou = new nod;
    nou->grad = grad;
    nou->coef = coef;
    nou->next = *head;
    *head = nou;
}

//adauga un nod la finalul listei
void add_last(nod **head, int grad, int coef)
{
    nod *nou = new nod, *last = *head;
    nou->grad = grad;
    nou->coef = coef;
    nou->next = NULL;
    while (last->next != NULL)
        last = last->next;
    last->next = nou;
}

//inmultirea unui polinom cu un scalar
void inmultire_scalar(nod *head, int scalar)
{
    while (head != NULL)
    {
        head->coef *= scalar;
        head = head->next;
    }
}

//valoarea unui polinom intr-un punct
int valoare_in_punct(nod *head, int x0)
{
    int valoare = 0, aux, i;
    while (head != NULL)
    {
        aux = 1;
        for (i = 1; i <= head->grad; i++)
            aux *= x0;
        aux *= head->coef;
        valoare += aux;
        head = head->next;
    }
    return valoare;
}

//suma a doua polinoame
nod *suma_polinoame(nod *p, nod *q)
{
    nod *suma = NULL;
    if (p->grad > q->grad)
    {
        add_first(&suma, p->grad, p->coef);
        p = p->next;
    }
    else if (p->grad < q->grad)
    {
        add_first(&suma, q->grad, q->coef);
        q = q->next;
    }
    else
    {
        add_first(&suma, q->grad, p->coef + q->coef);
        p = p->next;
        q = q->next;
    }

    while (p != NULL && q != NULL)
    {
        if (p->grad > q->grad)
        {
            add_last(&suma, p->grad, p->coef);
            p = p->next;
        }
        else if (p->grad < q->grad)
        {
            add_last(&suma, q->grad, q->coef);
            q = q->next;
        }
        else
        {
            add_last(&suma, q->grad, p->coef + q->coef);
            p = p->next;
            q = q->next;
        }
    }
    //similar cu interclasarea, la final se adauga ce a mai ramas
    while (p != NULL)
    {
        add_last(&suma, p->grad, p->coef);
        p = p->next;
    }
    while (q != NULL)
    {
        add_last(&suma, q->grad, q->coef);
        q = q->next;
    }
    return suma;
}

//afisare lista
void print(nod *head)
{
    while (head != NULL)
    {
        cout << head->coef << "X" << "^" << head->grad;
        if (head->next != NULL)
            cout << " + ";
        head = head->next;
    }
    cout << "\n\n";
}

//structura ajutatoare
struct date
{
    int grad, coef;
};

//creare polinom
nod *list_create(nod *head)
{
    head = NULL;
    int n, i;
    date v[15];
    cout << "\nDati numarul de elemente ale listei:";
    cin >> n;
    cout << "\nDati elementele listei (gradul, apoi coeficientul pentru fiecare element):\n";
    cin >> v[1].grad >> v[1].coef;
    add_first(&head, v[1].grad, v[1].coef);
    for (i = 2; i <= n; i++)
    {
        cin >> v[i].grad >> v[i].coef;
        add_last(&head, v[i].grad, v[i].coef);
    }
    return head;
}
int main()
{
    nod *h1, *h2, *suma;
    int x0,scalar;

    h1 = list_create(h1);

    cout<<"\nPolinomul creat este urmatorul:\n";
    print(h1);

    cout<<"Dati scalar:" ; cin>>scalar;
    cout<<"\nDupa inmultirea cu scalar, polinomul a devenit:\n";
    inmultire_scalar(h1, scalar);
    print(h1);

    cout << "Dati valoarea3 x0:";
    cin >> x0;
    cout << "Valoarea polinomului in punctul " << x0 << " este " << valoare_in_punct(h1, x0) << "\n";

    h2 = list_create(h2);
    cout<<"\nPolinomul creat este urmatorul:\n";
    print(h2);
    suma = suma_polinoame(h1,h2);
    cout<<"\nPolinomul suma este urmatorul:\n";
    print(suma);
    return 0;
}