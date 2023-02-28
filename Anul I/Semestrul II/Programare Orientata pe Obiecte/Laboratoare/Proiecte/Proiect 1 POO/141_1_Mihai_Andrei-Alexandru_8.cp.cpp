/*
   Tema 8. Clasa ”Multime” (multimi finite de numere intregi reprezentate ca tablouri unidimensionale)
       - membri privati pentru vectorul propriuzis si numarul de elemente;
       - constructori pentru initializare si copiere;
       - destructor (în cazul alocarii statice, se seteaza dimensiunea vectorului la zero,
       iar în cazul alocarii dinamice, se dezaloca zona de memorie utilizata);
       - metoda publica pentru transformare a unui vector in multime, \
       prin eliminarea duplicatelor din respectivul vector;

       - reuniune a doua multimi, implementata prin supraincarcarea operatorului +;
       - intersectie a doua multimi, implementata prin supraincarcarea operatorului *;
       - diferenta a doua multimi, implementata prin supraincarcarea operatorului -.

   Mihai Andrei-Alexandru, grupa 141
   07.03.2022
*/

#include <iostream>
using namespace std;

class Multime
{
    //- membri privati pentru vectorul propriuzis si numarul de elemente;
private:
    int set[1000], card;
    
public:
    //- constructori pentru initializare si copiere;
    Multime(int card)
    {
        cout << "This constructor called \n";
        this->card = card;
    }

    Multime()
    {
        // cout << "Constructor called \n";
    }

    Multime(Multime &set)
    {
        cout << "Copy constructor called \n";
        card = set.GetCard();
        int *multime = set.GetSet();
        for (int i = 0; i < card; i++)
            this->set[i] = multime[i];
    }

    // destructor
    ~Multime()
    {
        card = 0;
    }

    // geters
    int GetCard()
    {
        return card;
    }

    int *GetSet()
    {
        return set;
    }

    // setters
    void SetCard(int card)
    {
        this->card = card;
    }

    void SetSet(int set[])
    {
        for (int i = 0; i < card; i++)
            this->set[i] = set[i];
    }

    // metoda publica pentru trasnformarea unui vector in multime:
    void array_to_set()
    {
        // sortare
        int i, aux, j;
        for (i = 0; i < card - 1; i++)
            for (j = i + 1; j < card; j++)
                if (set[j] < set[i])
                {
                    aux = set[j], set[j] = set[i];
                    set[i] = aux;
                }

        // eliminare dubluri
        for (i = 0; i < card - 1;)
            if (set[i] == set[i + 1])
            {
                for (j = i + 1; j < card; j++)
                    set[j - 1] = set[j];

                card--;
            }
            else
                i++;
    }

    //  overload operator "+" ==> reuniune

    Multime operator+(const Multime &set1)
    {
        Multime Union;
        Union.card = this->card + set1.card;
        Union.set[Union.card];

        int i, j = 0;
        for (i = 0; i < this->card; i++)
            Union.set[i] = this->set[i];
        for (; i < Union.card; i++)
            Union.set[i] = set1.set[j++];

        Union.array_to_set();

        return Union;
    }

    // overload operator "*" ==> intersectia

    Multime operator*(const Multime &set1)
    {
        Multime Intersection;
        int i, j, p = 0;
        Intersection.card = 0;
        Intersection.set[(this->card > set1.card) ? this->card : set1.card];
        for (i = 0; i < this->card; i++)
            for (j = 0; j < set1.card; j++)
                if (this->set[i] == set1.set[j])
                {
                    Intersection.set[p++] = set[i];
                    Intersection.card++;
                }

        Intersection.array_to_set();

        return Intersection;
    }

    // overload operator "-" ==> diferenta

    Multime operator-(const Multime &set1)
    {
        Multime Difference;
        int i, j, p = 0, ok;
        Difference.card = 0;
        Difference.set[(this->card > set1.card) ? this->card : set1.card];
        for (i = 0; i < this->card; i++)
        {
            ok = 1;
            for (j = 0; j < set1.card; j++)
                if (this->set[i] == set1.set[j])
                {
                    ok = 0;
                    break;
                }
            if (ok == 1)
            {
                Difference.set[p++] = set[i];
                Difference.card++;
            }
        }
        Difference.array_to_set();
        return Difference;
    }

    // overload operator >> ==> citire
    friend istream &operator>>(istream &is, Multime &set1);

    // overload operator << ==> afisare
    friend ostream &operator<<(ostream &out, const Multime &set1);
};
ostream &operator<<(ostream &out, const Multime &set1)
{
    cout << "Cardinalul multimii este: ";
    out << set1.card << '\n';
    int i;
    cout << "Elementele multimii sunt: ";
    for (i = 0; i < set1.card; i++)
        out << set1.set[i] << ' ';
    cout << '\n';
    return out;
}

istream &operator>>(istream &is, Multime &set1)
{
    cout << "Dati cardinalul multimii: ";
    is >> set1.card;
    cout << "Dati elementele multimii: ";
    int i;
    for (i = 0; i < set1.card; i++)
        is >> set1.set[i];
    return is;
}

void read_sets(int &n, Multime m[])
{
    int i;
    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "\nIntroduceti numarul de multimi: ";
    cin >> n;
    cout << "\n------------------------------------------------------------------------------------\n\n";
    cout << "Introduceti multimile:\n\n";
    for (i = 1; i <= n; i++)
    {
        cout << "MULTIMEA " << i << '\n';
        cin >> m[i];
        m[i].array_to_set();
        cout << '\n';
    }
}

void print_sets(int n, Multime m[])
{
    int i;
    cout << "------------------------------------------------------------------------------------\n\n";
    cout << "MULTIMILE CARE AU FOST INTRODUSE SUNT URMATOARELE:\n\n";
    for (i = 1; i <= n; i++)
    {
        cout << "MULTIMEA " << i << '\n';
        cout << m[i] << "\n";
    }
}

int main()
{
    Multime set[101];
    Multime multimi[101];
    int n, ok = 0;
    while (true)
    {
        int optiune = 0;
        cout << "\n------------------------------------------------------------------------------------\n\n";
        cout << "VA ROG SELECTATI OPTIUNEA DIN MENIUL DE MAI JOS PRIN INTRODUCEREA NUMARULUI CORESPUNZATOR IN CONSOLA.\n\n";
        cout << "1. Creare multimilor memorate.\n";
        cout << "2. Afisare multimilor memorate.\n";
        cout << "3. Reuniune multimilor memorate.\n";
        cout << "4. Intersectie multimilor memorate.\n";
        cout << "5. Diferenta multimilor memorate.\n";
        cout << "6. Iesire din program.\n\n";
        cout << "Optiune: ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
        {
            read_sets(n, multimi);
            ok = 1;
            break;
        }
        case 2:
        {
            print_sets(n, multimi);
            break;
        }
        case 3:
        {
            if (ok == 1)
            {
                cout << "------------------------------------------------------------------------------------\n\n";
                cout << "SE VA EXECUTA REUNIUNEA MULTIMILOR MEMORATE!\n\n";
                int i;
                Multime reuniune;
                for (i = 1; i <= n; i++)
                    reuniune = reuniune + multimi[i];
                cout << reuniune;
            }
            else
                cout << "\nNU S-A MEMORAT NICIO MULTIME, VA ROG INTRODUCETI COMANDA 1 PENTRU O INTRODUCE DATE DESPRE MULTIMI!\n";
            break;
        }
        case 4:
        {
            if (ok == 1)
            {
                cout << "------------------------------------------------------------------------------------\n\n";
                cout << "SE VA EXECUTA INTERSECTIA MULTIMILOR MEMORATE!\n\n";
                int i;
                Multime intersectie = multimi[1];
                for (i = 2; i <= n; i++)
                    intersectie = intersectie * multimi[i];
                cout << intersectie;
            }
            else
                cout << "\nNU S-A MEMORAT NICIO MULTIME, VA ROG INTRODUCETI COMANDA 1 PENTRU O INTRODUCE DATE DESPRE MULTIMI!\n";
            break;
        }
        case 5:
        {
            if (ok == 1)
            {
                cout << "------------------------------------------------------------------------------------\n\n";
                cout << "SE VA EXECUTA DIFERENTA MULTIMILOR MEMORATE!\n\n";
                int i;
                Multime diferenta = multimi[1];
                for (i = 2; i <= n; i++)
                    diferenta = diferenta - multimi[i];
                cout << diferenta;
            }
            else
                cout << "\nNU S-A MEMORAT NICIO MULTIME, VA ROG INTRODUCETI COMANDA 1 PENTRU O INTRODUCE DATE DESPRE MULTIMI!\n";
            break;
        }
        case 6:
            cout << "\nMultumesc pentru ca mi-ati folosit programul, o zi buna! :)\n";
            exit(0);
            break;

        default:
            cout << "\nOPTIUNE INVALIDA, VA ROG SELECTATI UNA DINTRE CELE DE MAI JOS.\n\n";
            cout << "------------------------------------------------------------------------------------\n\n";
            break;
        }
    }
    return 0;
}