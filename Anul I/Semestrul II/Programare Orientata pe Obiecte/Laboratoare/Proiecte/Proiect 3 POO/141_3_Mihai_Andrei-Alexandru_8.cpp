/*
    Tema 8 – Pizzeria X testează un nou soft, dezvoltat în maniera OOP, pentru gestionarea activității sale.
Codul propriu-zis contine o clasa abstracta care contine doar metoda virtuala pura de calcul al prețului unui produs,
iar din aceasta clasa deriva clasa Pizza. În realizarea oricărui produs intra un anumit număr de ingrediente pentru
care se cunosc denumirile, cantitatile și prețul unitar. Prețul unui produs finit este data de prețul ingredientelor
plus manopera (o suma constanta fixată de producător). Daca pizza este comandata OnLine, la preț se mai adaugă și
5% din pret la fiecare 10 km parcursi de angajatul care livrează la domiciliu.
Structura de date: unordered_map sau unordered_set <id_pizza, list sau vector <ingredient>>

Cerința suplimentară:
- Să se adauge toate campurile relevante pentru modelarea acestei probleme.

- Să se construiască clasa template Meniu care sa gestioneze tipurie de pizza comercializate.
Clasa trebuie sa contina indexul unui produs (incrementat automat la vanzarea unui produs
prin supraincarcarea operatorului +=) și o structură de date, alocata dinamic.

- Să se construiască o specializare pentru tipul Comanda_Online care sa trateze tipurile de pizza
vegetariana într-un document contabil separat din care sa rezulte valoarea totala incasata din vanzarea acestora.

Tema 3 de laborator POO, nr. 8

Mihai Andrei-Alexandru, 10.05.2022

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Produs
{
public:
    virtual void calcul_pret() = 0;
};

class Ingrediente
{
protected:
    string denumire;
    int cantitate;
    double pret;

public:
    friend class Pizza;

    // contructors
    Ingrediente()
    {
        // cout<<"Default (Ingrediente) contructor called\n";
    }

    Ingrediente(string denumire, int cantitate, double pret)
    {
        // cout<<"Parameterized (Ingrediente) contructor called\n";
        this->denumire = denumire;
        this->cantitate = cantitate;
        this->pret = pret;
    }

    Ingrediente(const Ingrediente &i1)
    {
        // cout<<"Copy constructor (Ingrediente) called\n";
        denumire = i1.denumire;
        cantitate = i1.cantitate;
        pret = i1.pret;
    }

    // destructor
    ~Ingrediente()
    {
        // cout<<"(Ingrediente) object destroied\n";
    }

    // gettes
    string get_Denumire() const
    {
        return denumire;
    }

    int get_Cantitate() const
    {
        return cantitate;
    }

    double get_Pret() const
    {
        return pret;
    }

    // setters
    void set_Denumire(string denumire)
    {
        this->denumire = denumire;
    }

    void set_Cantitate(int cantitate)
    {
        this->cantitate = cantitate;
    }

    void set_Pret(double pret)
    {
        this->pret = pret;
    }

    // overloads
    friend istream &operator>>(istream &is, Ingrediente &i1);

    friend ostream &operator<<(ostream &os, const Ingrediente &i1);

    Ingrediente &operator=(const Ingrediente &i1)
    {
        this->denumire = i1.denumire;
        this->cantitate = i1.cantitate;
        this->pret = i1.pret;
        return *this;
    }

    bool operator==(const Ingrediente &i1) const
    {
        return denumire == i1.denumire && cantitate == i1.cantitate && pret == i1.pret;
    }

    bool operator!=(const Ingrediente &i1) const
    {
        return !(denumire == i1.denumire && cantitate == i1.cantitate && pret == i1.pret);
    }
};

istream &operator>>(istream &is, Ingrediente &i1)
{
    cout << "\nDati denumirea ingredientului: ";
    is >> i1.denumire;
    cout << "Dati cantitatea de " << i1.denumire << ": ";
    is >> i1.cantitate;
    cout << "Dati pretul pentru " << i1.denumire << ": ";
    is >> i1.pret;
    return is;
}

ostream &operator<<(ostream &os, const Ingrediente &i1)
{
    cout << "\nDenumirea ingredientului este: ";
    os << i1.denumire << endl;
    cout << "Cantitatea de " << i1.denumire << " este: ";
    os << i1.cantitate << endl;
    cout << "Pretul pentru " << i1.denumire << " este: ";
    os << i1.pret << endl;
    return os;
}

class Pizza : public Produs, public Ingrediente
{
protected:
    int pret_pizza, nr_ingrediente, cantitate_pizza;
    const int manopera = 5;
    vector<Ingrediente> ingrediente;

public:
    virtual void calcul_pret()
    {
        pret_pizza = manopera;
        for (int i = 0; i < nr_ingrediente; i++)
            pret_pizza += ingrediente[i].cantitate * ingrediente[i].pret;
    }

    virtual void citire()
    {
        Ingrediente i1;
        cout << "\nDati numarul de ingrediente pentru pizza: ";
        cin >> nr_ingrediente;
        cout << "\nDati datele despre ingrediente:\n";
        for (int i = 0; i < nr_ingrediente; i++)
        {
            cin >> i1;
            ingrediente.push_back(i1);
        }
        calcul_pret();
        cout << "\nDati cantitatea pentru acesta pizza: ";
        cin >> cantitate_pizza;
    }

    virtual void afisare()
    {
        cout << "Pretul pentru pizza este: " << pret_pizza << ".\n";
        cout << "\nIngredientele pentru pizza sunt:\n";
        for (int i = 0; i < ingrediente.size(); i++)
            cout << ingrediente[i] << endl;
        cout << "Cantitatea pentru acesta pizza este " << cantitate_pizza << "\n\n";
    }

    // constructors
    Pizza() : Ingrediente()
    {
        // cout<<"Default (Pizza) contructor called\n";
    }

    Pizza(int nr_ingrediente, vector<Ingrediente> ingrediente)
    {
        // cout<<"Parameterized (Pizza) contructor called\n";
        this->nr_ingrediente = nr_ingrediente;
        this->cantitate_pizza = cantitate_pizza;
        for (int i = 0; i < nr_ingrediente; i++)
            this->ingrediente[i] = ingrediente[i];
        calcul_pret();
    }

    Pizza(const Pizza &p1)
    {
        // cout<<"Copy constructor (Pizza) called\n";
        nr_ingrediente = p1.nr_ingrediente;
        cantitate_pizza = p1.cantitate_pizza;
        for (int i = 0; i < p1.nr_ingrediente; i++)
            ingrediente.push_back(p1.ingrediente[i]);
        pret_pizza = p1.pret_pizza;
    }

    // destructor
    ~Pizza()
    {
        // cout<<"(Pizza) object destroied\n";
    }

    // getters

    int get_Pret_Pizza() const
    {
        return pret_pizza;
    }

    int get_Cantitate_Pizza() const
    {
        return cantitate_pizza;
    }

    int get_Nr_Ingrediente() const
    {
        return nr_ingrediente;
    }

    vector<Ingrediente> get_Ingrediente() const
    {
        return ingrediente;
    }

    int get_Manopera() const
    {
        return manopera;
    }

    // setters

    void set_Pret_Pizza(int pret_pizza)
    {
        this->pret_pizza = pret_pizza;
    }

    void set_Nr_Ingrediente(int nr_ingrediente)
    {
        this->nr_ingrediente = nr_ingrediente;
    }

    void set_Ingrediente(vector<Ingrediente> ingrediente)
    {
        for (int i = 0; i < nr_ingrediente; i++)
            this->ingrediente[i] = ingrediente[i];
    }

    void set_Cantitate_Pizza(int cantitate_pizza)
    {
        this->cantitate_pizza = cantitate_pizza;
    }

    // overloads
    friend istream &operator>>(istream &is, Pizza &p1);

    friend ostream &operator<<(ostream &os, const Pizza &p1);

    Pizza &operator=(const Pizza &p1)
    {
        this->pret_pizza = p1.pret_pizza;
        this->nr_ingrediente = p1.nr_ingrediente;
        this->cantitate_pizza = p1.cantitate_pizza;
        for (int i = 0; i < p1.nr_ingrediente; i++)
            ingrediente.push_back(p1.ingrediente[i]);
        return *this;
    }

    bool operator==(const Pizza &p1) const
    {
        Ingrediente::operator==(p1);
        if (pret_pizza != p1.pret_pizza)
            return 0;
        else if (nr_ingrediente != p1.nr_ingrediente)
            return 0;
        else
            for (int i = 0; i < p1.nr_ingrediente; i++)
                if (ingrediente[i] != p1.ingrediente[i])
                    return 0;
        return 1;
    }

    bool operator!=(const Pizza &p1) const
    {
        Ingrediente::operator==(p1);
        if (pret_pizza == p1.pret_pizza)
            return 0;
        else if (nr_ingrediente == p1.nr_ingrediente)
            return 0;
        else
            for (int i = 0; i < p1.nr_ingrediente; i++)
                if (ingrediente[i] == p1.ingrediente[i])
                    return 0;
        return 1;
    }
};

istream &operator>>(istream &is, Pizza &p1)
{
    Ingrediente i1;
    cout << "\nDati numarul de ingrediente pentru pizza: ";
    is >> p1.nr_ingrediente;
    cout << "\nDati datele despre ingrediente:\n";
    for (int i = 0; i < p1.nr_ingrediente; i++)
    {
        is >> i1;
        p1.ingrediente.push_back(i1);
    }
    p1.calcul_pret();
    cout << "\nDati cantitatea pentru acesta pizza: ";
    is >> p1.cantitate_pizza;
    return is;
}

ostream &operator<<(ostream &os, const Pizza &p1)
{
    os << "Pretul pentru pizza este: " << p1.pret_pizza << ".\n";
    os << "\nIngredientele pentru pizza sunt:\n";
    for (int i = 0; i < p1.ingrediente.size(); i++)
        os << p1.ingrediente[i] << endl;
    os << "Cantitatea pentru acesta pizza este " << p1.cantitate_pizza << "\n\n";
    return os;
}

class Pizza_Vegetariana : public Pizza
{
protected:
    int pret_pizza, nr_ingrediente, cantitate_pizza;
    const int manopera = 5;
    vector<Ingrediente> ingrediente;

public:
    virtual void calcul_pret()
    {
        pret_pizza = manopera;
        for (int i = 0; i < nr_ingrediente; i++)
            pret_pizza += ingrediente[i].get_Cantitate() * ingrediente[i].get_Pret();
    }

    // constructors
    Pizza_Vegetariana() : Pizza()
    {
        // cout<<"Default (Pizza) contructor called\n";
    }

    Pizza_Vegetariana(int nr_ingrediente, vector<Ingrediente> ingrediente)
    {
        // cout<<"Parameterized (Pizza) contructor called\n";
        this->nr_ingrediente = nr_ingrediente;
        this->cantitate_pizza = cantitate_pizza;
        for (int i = 0; i < nr_ingrediente; i++)
            this->ingrediente[i] = ingrediente[i];
        calcul_pret();
    }

    Pizza_Vegetariana(const Pizza_Vegetariana &p1)
    {
        // cout<<"Copy constructor (Pizza) called\n";
        nr_ingrediente = p1.nr_ingrediente;
        cantitate_pizza = p1.cantitate_pizza;
        for (int i = 0; i < p1.nr_ingrediente; i++)
            ingrediente.push_back(p1.ingrediente[i]);
        pret_pizza = p1.pret_pizza;
    }

    // destructor
    ~Pizza_Vegetariana()
    {
        // cout<<"(Pizza) object destroied\n";
    }

    // getters

    int get_Pret_Pizza() const
    {
        return pret_pizza;
    }

    int get_Cantitate_Pizza() const
    {
        return cantitate_pizza;
    }

    int get_Nr_Ingrediente() const
    {
        return nr_ingrediente;
    }

    vector<Ingrediente> get_Ingrediente() const
    {
        return ingrediente;
    }

    int get_Manopera() const
    {
        return manopera;
    }

    // setters

    void set_Pret_Pizza(int pret_pizza)
    {
        this->pret_pizza = pret_pizza;
    }

    void set_Nr_Ingrediente(int nr_ingrediente)
    {
        this->nr_ingrediente = nr_ingrediente;
    }

    void set_Ingrediente(vector<Ingrediente> ingrediente)
    {
        for (int i = 0; i < nr_ingrediente; i++)
            this->ingrediente[i] = ingrediente[i];
    }

    void set_Cantitate_Pizza(int cantitate_pizza)
    {
        this->cantitate_pizza = cantitate_pizza;
    }

    // overloads
    friend istream &operator>>(istream &is, Pizza_Vegetariana &p1);

    friend ostream &operator<<(ostream &os, const Pizza_Vegetariana &p1);

    Pizza_Vegetariana &operator=(const Pizza_Vegetariana &p1)
    {
        this->pret_pizza = p1.pret_pizza;
        this->nr_ingrediente = p1.nr_ingrediente;
        this->cantitate_pizza = p1.cantitate_pizza;
        for (int i = 0; i < p1.nr_ingrediente; i++)
            ingrediente.push_back(p1.ingrediente[i]);
        return *this;
    }

    bool operator==(const Pizza_Vegetariana &p1) const
    {
        Ingrediente::operator==(p1);
        if (pret_pizza != p1.pret_pizza)
            return 0;
        else if (nr_ingrediente != p1.nr_ingrediente)
            return 0;
        else
            for (int i = 0; i < p1.nr_ingrediente; i++)
                if (ingrediente[i] != p1.ingrediente[i])
                    return 0;
        return 1;
    }

    bool operator!=(const Pizza_Vegetariana &p1) const
    {
        Ingrediente::operator==(p1);
        if (pret_pizza == p1.pret_pizza)
            return 0;
        else if (nr_ingrediente == p1.nr_ingrediente)
            return 0;
        else
            for (int i = 0; i < p1.nr_ingrediente; i++)
                if (ingrediente[i] == p1.ingrediente[i])
                    return 0;
        return 1;
    }
};

istream &operator>>(istream &is, Pizza_Vegetariana &p1)
{
    Ingrediente i1;
    cout << "\nDati numarul de ingrediente pentru pizza: ";
    is >> p1.nr_ingrediente;
    cout << "\nDati datele despre ingrediente:\n";
    for (int i = 0; i < p1.nr_ingrediente; i++)
    {
        is >> i1;
        p1.ingrediente.push_back(i1);
    }
    p1.calcul_pret();
    cout << "\nDati cantitatea pentru acesta pizza: ";
    is >> p1.cantitate_pizza;
    return is;
}

ostream &operator<<(ostream &os, const Pizza_Vegetariana &p1)
{
    os << "Pretul pentru pizza este: " << p1.pret_pizza << ".\n";
    os << "\nIngredientele pentru pizza sunt:\n";
    for (int i = 0; i < p1.ingrediente.size(); i++)
        os << p1.ingrediente[i] << endl;
    os << "Cantitatea pentru acesta pizza este " << p1.cantitate_pizza << "\n\n";
    return os;
}

template <class T>
class Comanda : public Pizza
{
protected:

    T pizza[101];
    int pret_comanda = 0;
    int tipuri_pizza;

public:
    virtual void citire()
    {
        cout<<"\nDati numarul tipurilor de pizza: "; cin>>tipuri_pizza;
        cout << "\nDati datele despre pizza:\n";
        for (int i = 0; i < tipuri_pizza; i++)
        {
            cin >> pizza[i];
            pret_comanda += pizza[i].get_Pret_Pizza() * pizza[i].get_Cantitate_Pizza();
        }
    }

    virtual void afisare()
    {
        cout<<"\nNumarul tipurilor de pizza: "; cout<<tipuri_pizza<<endl;
        cout << "\nDatele despre pizza sunt:\n";
        for (int i = 0; i < tipuri_pizza; i++)
            cout << pizza[i];
        cout << "Pretul comenzii este " << pret_comanda << endl;
    }

    // constructors
    Comanda() : Pizza()
    {
        // cout<<"Default (Comanda_online) contructor called\n";
    }

    Comanda(int tipuri_pizza,T pizza[])
    {
        // cout<<"Parameterized (Comanda) contructor called\n";
        this->tipuri_pizza=tipuri_pizza;
        for (int i = 0; i < tipuri_pizza; i++)
        {
            this->pizza[i] = pizza[i];
            calcul_pret();
            pret_comanda += pizza[i].pret_pizza * pizza[i].cantitate_pizza;
        }
    }

    Comanda(const Comanda<T> &c1)
    {
        // cout<<"Copy constructor (Comanda) called\n";
        tipuri_pizza=c1.tipuri_pizza;
        for (int i = 0; i < tipuri_pizza; i++)
            pizza[i] = c1.pizza[i];
        pret_comanda = c1.pret_comanda;
    }

    // destructor
    ~Comanda()
    {
        // cout<<"(Comanda) object destroied\n";
    }

    // getters
    T get_Pizza() const
    {
        return pizza;
    }

    T get_Pizza_Index(int i) const
    {
        return pizza[i];
    }

    int get_Pret_Comanda() const
    {
        return pret_comanda;
    }

    int get_Tipuri_Pizza() const{
        return tipuri_pizza;
    }

    // setters
    void set_Pizza(int tipuri_pizza,T pizza[])
    {
        this->tipuri_pizza=tipuri_pizza;
        for (int i = 0; i < tipuri_pizza; i++)
            this->pizza[i] = pizza[i];
    }

    void set_Pret_Comanda(int pret_comanda)
    {
        this->pret_comanda = pret_comanda;
    }

    void set_Tipuri_Pizza(int tipuri_pizza){
        this->tipuri_pizza=tipuri_pizza;
    }

    // overloads

    Comanda &operator=(const Comanda<T> &c1)
    {
        // Pizza::operator=(c1);
        this->tipuri_pizza=tipuri_pizza;
        for (int i = 0; i < tipuri_pizza; i++)
            this->pizza[i] = c1.pizza[i];
        pret_comanda = c1.pret_comanda;
        return *this;
    }

    T &operator[](int index)
    {
        return pizza[index];
    }

    bool operator==(const Comanda<T> &c1) const
    {
        if(c1.tipuri_pizza!=tipuri_pizza) return 0;
        else
            for (int i = 0; i < tipuri_pizza; i++)
                if (pizza[i] != c1.pizza[i])
                    return 0;
        return 1;
    }

    bool operator!=(const Comanda<T> &c1) const
    {
        if(c1.tipuri_pizza==tipuri_pizza) return 0;
        else
            for (int i = 0; i < tipuri_pizza; i++)
                if (pizza[i] == c1.pizza[i])
                    return 0;
        return 1;
    }

    template <class U>
    friend istream &operator>>(istream &in, Comanda<U> &c1);

    template <class U>
    friend ostream &operator<<(ostream &out, const Comanda<U> &c1);
};

template <class U>
istream &operator>>(istream &in, Comanda<U> &c1)
{
    cout<<"\nDati numarul tipurilor de pizza: "; in>>c1.tipuri_pizza;
    cout << "\nDati datele despre pizza:\n";
    for (int i = 0; i < c1.tipuri_pizza; i++)
    {
        in >> c1.pizza[i];
        c1.pret_comanda += c1.pizza[i].get_Pret_Pizza() * c1.pizza[i].get_Cantitate_Pizza();
    }
    return in;
}

template <class U>
ostream &operator<<(ostream &out, const Comanda<U> &c1)
{
    out<<"\nNumarul tipurilor de pizza: "; out<<c1.tipuri_pizza<<endl;
    out << "\nDatele despre pizza sunt:\n";
    for (int i = 0; i < c1.tipuri_pizza; i++)
        out << c1.pizza[i];
    out << "Pretul comenzii este " << c1.pret_comanda << endl;
    return out;
}

template <class T>
class Comanda_online : public Comanda<T>
{

protected:
    int km_parcursi;

public:

    int calcul_pret(T p)
    {
        return p.get_Pret_Pizza() + (km_parcursi / 10) * 0.05 * p.get_Pret_Pizza();
    }

    virtual void citire(){
        cout << "\nDati numarul de km parcursi la livrare: ";
        cin >> km_parcursi;
        cout<< "\nDati numarul de tipuri de pizza: "; cin>>this->tipuri_pizza;
        cout << "\nDati datele despre pizza:\n";
        for (int i = 0; i < this->tipuri_pizza; i++)
        {
            cin >> this->pizza[i];
            this->pret_comanda += calcul_pret(this->pizza[i]) * this->pizza[i].get_Cantitate_Pizza();
        }
    }

    virtual void afisare(){
        cout << "\nNumarul de km parcursi la livrare este " << km_parcursi << endl;
        cout<< "\nNumarul de tipuri de pizza este "<< this->tipuri_pizza<<endl;
        cout << "\nDatele despre pizza sunt:\n";
        for (int i = 0; i < this->tipuri_pizza; i++)
            cout << this->pizza[i];
        cout << "Pretul comenzii este " << this->pret_comanda << endl;
    }

    // constructors
    Comanda_online() : Comanda<T>()
    {
        // cout<<"Default (Comanda_online) contructor called\n";
    }

    Comanda_online(T pizza[], int km_parcursi,int tipuri_pizza) : Comanda<T>(pizza,tipuri_pizza)
    {
        // cout<<"Parameterized (Comanda_online) contructor called\n";
        this->km_parcursi = km_parcursi;
        this->tipuri_pizza=tipuri_pizza;
        for (int i = 0; i < tipuri_pizza; i++)
        {
            this->pizza[i] = pizza[i];
            pizza[i].pret_pizza = calcul_pret(pizza[i]);
            this->pret_comanda += pizza[i].pret_pizza * pizza[i].cantitate_pizza;
        }
    }

    Comanda_online(const Comanda_online<T> &c1)
    {
        // cout<<"Copy constructor (Comanda_online) called\n";
        this->km_parcursi = c1.km_parcursi;
        this->tipuri_pizza=c1.tipuri_pizza;
        for (int i = 0; i < c1.tipuri_pizza; i++)
            this->pizza[i] = c1.pizza[i];
        this->pret_comanda = c1.pret_comanda;
    }

    // destructor
    ~Comanda_online()
    {
        // cout<<"(Comanda_online) object destroied\n";
    }

    // getters

    int get_Km_Parcursi() const
    {
        return km_parcursi;
    }

    // setters

    void set_Km_Parcursi(int km_parcursi)
    {
        this->km_parcursi = km_parcursi;
    }

    // overloads

    Comanda_online &operator=(const Comanda_online<T> &c1)
    {
        Comanda<T>::operator=(c1);
        this->km_parcursi = c1.km_parcursi;
        return *this;
    }

    bool operator==(const Comanda_online<T> &c1) const
    {
        Comanda<T>::operator==(c1);
        return km_parcursi == c1.km_parcursi;
    }

    bool operator!=(const Comanda_online<T> &c1) const
    {
        Comanda<T>::operator!=(c1);
        return !(km_parcursi == c1.km_parcursi);
    }

    template <class U>
    friend istream &operator>>(istream &in, Comanda_online<U> &c1);

    template <class U>
    friend ostream &operator<<(ostream &out, const Comanda_online<U> &c1);
};

template <class U>
istream &operator>>(istream &in, Comanda_online<U> &c1)
{
    cout << "\nDati numarul de km parcursi la livrare: ";
    in >> c1.km_parcursi;
    cout<< "\nDati numarul de tipuri de pizza: "; in>>c1.tipuri_pizza;
    cout << "\nDati datele despre pizza:\n";
    for (int i = 0; i < c1.tipuri_pizza; i++)
    {
        in >> c1.pizza[i];
        c1.pret_comanda += c1.calcul_pret(c1.pizza[i]) * c1.pizza[i].get_Cantitate_Pizza();
    }
    return in;
}

template <class U>
ostream &operator<<(ostream &out, const Comanda_online<U> &c1)
{
    out << "\nNumarul de km parcursi la livrare este " << c1.km_parcursi << endl;
    out<< "\nNumarul de tipuri de pizza este "<< c1.tipuri_pizza<<endl;
    out << "\nDatele despre pizza sunt:\n";
    for (int i = 0; i < c1.tipuri_pizza; i++)
        out << c1.pizza[i];
    cout << "Pretul comenzii este " << c1.pret_comanda << endl;
    return out;
}

template <class U>
class HashFunction
{
public:
    size_t operator()(const U &c1) const
    {
        return c1.get_Cantitate() + c1.get_Denumire().length() + c1.get_Id_Pizza();
    }
};

template <class T>
class Meniu
{
protected:
    static int index;
    int nr_pizza;
    unordered_map<int, T> meniu;
    
public:

    virtual void citire(){
        cout << "\nDati numarul de tipuri de pizza din meniu: ";
        cin >> nr_pizza;
        cout << "Dati datele despre tipurile de pizza:\n";
        int ID;
        T p1;
        for (int i = 0; i < nr_pizza; i++)
        {
            cin >> p1;
            cout << "\nDati ID-ul pentru acest tip de pizza: ";
            cin >> ID;
            meniu[ID] = p1;
        }
    }

    virtual void afisare(){
        cout << "\nIndexul meniului este egal cu: " << index << endl;
        cout << "\nNumarul de tipuri de pizza din acest meniu este " << nr_pizza<<"\n\n";
        cout << "Tipurile de pizza din meniu sunt urmatoarele:\n\n";
        for (auto x : meniu)
            cout << "ID: " << x.first << "\n" << x.second << endl;
    }

    // constructors
    Meniu()
    {
        // cout<<"Default (Meniu) contructor called\n";
    }

    Meniu(int index, unordered_map<int, T> meniu, int nr_pizza)
    {
        // cout<<"Parameterized (Meniu) contructor called\n";
        this->index = index;
        this->nr_pizza = nr_pizza;
        this->meniu = meniu;
    }

    Meniu(const Meniu &m1)
    {
        // cout<<"Copy constructor (Meniu) called\n";
        this->index = m1.index;
        this->nr_pizza = m1.nr_pizza;
        this->meniu = m1.meniu;
    }

    // destructor

    ~Meniu()
    {
        // cout<<"(Meniu) object destroied\n";
    }

    // getters

    int get_Index() const
    {
        return index;
    }

    int get_Nr_Pizza() const{
        return nr_pizza;
    }


    unordered_map<int, T> get_Meniu() const
    {
        return meniu;
    }

    // setters

    void set_Index(int index)
    {
        this->index = index;
    }

    void set_Tipuri_Pizza(int tipuri_pizza)
    {
        this->tipuri_pizza = tipuri_pizza;
    }

    void set_Meniu(unordered_map<int, T> meniu)
    {
        this->meniu = meniu;
    }

    // overloads

    Meniu<T> &operator=(const Meniu<T> &m1)
    {
        this->tipuri_pizza = m1.tipuri_pizza;
        this->meniu = m1.meniu;
        return *this;
    }

    Meniu<T> operator+=(const Comanda_online<T> &m1)
    {
        int ok = 0;
        for (int i = 0; i < m1.get_Tipuri_Pizza(); i++)
            for (auto x : meniu)
                if (m1.get_Pizza_Index(i) == x.second)
                {
                    ok = 1;
                    if (m1.get_Pizza_Index(i).get_Cantitate_Pizza() <= x.second.get_Cantitate_Pizza())
                    {
                        index += m1.get_Pizza_Index(i).get_Cantitate_Pizza();
                        meniu[x.first].set_Cantitate_Pizza(x.second.get_Cantitate_Pizza() - m1.get_Pizza_Index(i).get_Cantitate_Pizza());
                    }
                    else
                        cout << "\nNu exista cantitatea de pizza mentionata in stoc.\n";
                }
        if (ok == 0)
            cout << "\nNu exista tipul de pizza specificat in comanda in meniu.\n";
        return *this;
    }

    template <class U>
    friend istream &operator>>(istream &in, Meniu<U> &m1);

    template <class U>
    friend ostream &operator<<(ostream &out, const Meniu<U> &m1);
};

template <class U>
int Meniu<U>::index = 0;

template <class U>
istream &operator>>(istream &in, Meniu<U> &m1)
{
    cout << "\nDati numarul de tipuri de pizza din meniu: ";
    in >> m1.nr_pizza;
    cout << "Dati datele despre tipurile de pizza:\n";
    int ID;
    U p1;
    for (int i = 0; i < m1.nr_pizza; i++)
    {
        in >> p1;
        cout << "\nDati ID-ul pentru acest tip de pizza: ";
        in >> ID;
        m1.meniu[ID] = p1;
    }
    return in;
}

template <class U>
ostream &operator<<(ostream &out, const Meniu<U> &m1)
{
    out << "\nIndexul meniului este egal cu: " << m1.index << endl;
    out << "\nNumarul de tipuri de pizza din acest meniu este " << m1.nr_pizza << endl
        << endl;
    out << "Tipurile de pizza din meniu sunt urmatoarele:\n\n";
    for (auto x : m1.meniu)
        cout << "ID: " << x.first << "\n"
             << x.second << endl;
    return out;
}

template<>
class Meniu<Comanda_online<Pizza_Vegetariana>>
{
protected:

    int nr_pizza;
    unordered_map<int, Pizza_Vegetariana> meniu;
    static int incasari_v;

public:

    virtual void citire(){
        cout<<"\nDati numarul tipurilor de pizza: "; cin>>nr_pizza;
        cout << "Dati datele despre tipurile de pizza vegetariana:\n";
        int ID;
        Pizza_Vegetariana p1;
        for (int i = 0; i < nr_pizza; i++)
        {
            cin >> p1;
            cout << "\nDati ID-ul pentru acest tip de pizza: ";
            cin >> ID;
            meniu[ID] = p1;
        }
    }

    virtual void afisare(){
        cout << "\nNumarul de tipuri de pizza din acest meniu este " << nr_pizza << endl << endl;
        cout << "Tipurile de pizza vegetariana din meniu sunt urmatoarele:\n\n";
        for (auto x : meniu)
            cout << "ID: " << x.first << "\n"
                << x.second << endl;
    }

    // constructors
    Meniu()
    {
        // cout<<"Default (Meniu) contructor called\n";
    }

    Meniu(int index, unordered_map<int, Pizza_Vegetariana> meniu, int nr_pizza)
    {
        // cout<<"Parameterized (Meniu) contructor called\n";
        this->nr_pizza = nr_pizza;
        this->meniu = meniu;
    }

    Meniu(const Meniu &m1)
    {
        // cout<<"Copy constructor (Meniu) called\n";
        nr_pizza = m1.nr_pizza;
        meniu = m1.meniu;
    }

    // destructor

    ~Meniu()
    {
        // cout<<"(Meniu) object destroied\n";
    }

    // getters

    int get_Nr_Pizza() const
    {
        return nr_pizza;
    }

    unordered_map<int, Pizza_Vegetariana> get_Meniu() const
    {
        return meniu;
    }

    // setters

    void set_Nr_Pizza(int tipuri_pizza)
    {
        this->nr_pizza = nr_pizza;
    }

    void set_Meniu(unordered_map<int, Pizza_Vegetariana> meniu)
    {
        this->meniu = meniu;
    }

    // functie afisare incasari pizza vegetariana
    static void print_incasari()
    {
        cout << "\nIncasarile pentru pizza vegetariana sunt egale cu " << incasari_v << endl;
    }

    // overloads

    Meniu<Comanda_online<Pizza_Vegetariana>> &operator=(const Meniu<Comanda_online<Pizza_Vegetariana>> &m1)
    {
        this->nr_pizza = nr_pizza;
        this->meniu = m1.meniu;
        return *this;
    }

    Meniu<Comanda_online<Pizza_Vegetariana>> operator+=(const Comanda_online<Pizza_Vegetariana> &m1)
    {
        int ok = 0;
        for (int i = 0; i < m1.get_Tipuri_Pizza(); i++)
            for (auto x : meniu)
                if (m1.get_Pizza_Index(i) == x.second)
                {
                    ok = 1;
                    if (m1.get_Pizza_Index(i).get_Cantitate_Pizza() <= x.second.get_Cantitate_Pizza())
                    {
                        incasari_v += m1.get_Pret_Comanda();
                        meniu[x.first].set_Cantitate_Pizza(x.second.get_Cantitate_Pizza() - m1.get_Pizza_Index(i).get_Cantitate_Pizza());
                    }
                    else
                        cout << "\nNu exista cantitatea de pizza mentionata in stoc.\n";
                }
        if (ok == 0)
            cout << "\nNu exista tipul de pizza specificat in comanda in meniu.\n";
        return *this;
    }

    friend istream &operator>>(istream &in, Meniu<Comanda_online<Pizza_Vegetariana>> &m1);

    friend ostream &operator<<(ostream &out, const Meniu<Comanda_online<Pizza_Vegetariana>> &m1);
};

int Meniu<Comanda_online<Pizza_Vegetariana>>::incasari_v = 0;

istream &operator>>(istream &in, Meniu<Comanda_online<Pizza_Vegetariana>> &m1)
{
    cout<< "\nDati numarul de tipuri de pizza din meniu: "; in>>m1.nr_pizza;
    cout << "Dati datele despre tipurile de pizza vegetariana:\n";
    int ID;
    Pizza_Vegetariana p1;
    for (int i = 0; i < m1.nr_pizza; i++)
    {
        in >> p1;
        cout << "\nDati ID-ul pentru acest tip de pizza: ";
        in >> ID;
        m1.meniu[ID] = p1;
    }
    return in;
}

ostream &operator<<(ostream &out, const Meniu<Comanda_online<Pizza_Vegetariana>> &m1)
{
    out << "\nNumarul de tipuri de pizza din acest meniu este " << m1.nr_pizza << endl
        << endl;
    out << "Tipurile de pizza vegetariana din meniu sunt urmatoarele:\n\n";
    for (auto x : m1.meniu)
        cout << "ID: " << x.first << "\n"
             << x.second << endl;
    return out;
}

int main()
{

    Meniu<Pizza> meniu; 
    Meniu<Comanda_online<Pizza_Vegetariana>> meniu_v;
    Comanda_online<Pizza> co_p[51]; Comanda_online<Pizza_Vegetariana> co_pv[51];
    int ok = 0, ok_v=0, ok_c=0, numar_comenzi, numar_comenzi_v;
    while (true)
    {
        int optiune;
        cout << "\n------------------------------------------------------------------------------------\n\n";
        cout << "VA ROG SELECTATI OPTIUNEA DIN MENIUL DE MAI JOS PRIN INTRODUCEREA NUMARULUI CORESPUNZATOR IN CONSOLA.\n\n";
        cout << "1. Introducerea datelor in meniul de pizza.\n";
        cout << "2. Introducerea datelor in meniul de pizza vegetariana.\n";
        cout << "3. Afisarea datelor din meniul de pizza.\n";
        cout << "4. Afisarea datelor din meniul de pizza vegetariana.\n";
        cout << "5. Introducerea datelor pentru comenzi.\n";
        cout << "6. Afisarea datelor pentru comenzi.\n";
        cout << "7. Vanzare - toate comenzile.\n";
        cout << "8. Afisare index dosar pizza.\n";
        cout << "9. Afisare incasari dosar pizza vegetariana.\n";
        cout << "10. Iesire din program.\n\n";
        cout << "Optiune: ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
        {
            cin>>meniu;
            ok = 1;
            break;
        }
        case 2:
        {
            cin>>meniu_v;
            ok_v=1;
            break;
        }
        case 3:
        {
            try
            {
                if(ok==1){
                    cout << "------------------------------------------------------------------------------------\n\n";
                    cout<<"Se vor afisa datele din meniul de pizza.\n";
                    cout<<meniu<<endl;
                }
                else throw(ok);
            }
            catch(int ok){
                cout << "\nNU AU FOST MEMORATE DATE IN MENIU, VA ROG INTRODUCETI COMANDA 1 PENTRU O INTRODUCE DATE IN MENIU!\n";
            }
            break;
        }
        case 4:
        {
            try
            {
                if(ok_v==1){
                    cout << "------------------------------------------------------------------------------------\n\n";
                    cout<<"Se vor afisa datele din meniul de pizza vegetariana.\n";
                    cout<<meniu_v<<endl;
                }
                else throw(ok);
            }
            catch(int ok){
                cout << "\nNU AU FOST MEMORATE DATE IN MENIU, VA ROG INTRODUCETI COMANDA 2 PENTRU O INTRODUCE DATE IN MENIU!\n";
            }
            break;
        }

        case 5:
        {
            try{
                cout<<"\nDati numarul de comenzi pentru pizza: "; cin>>numar_comenzi;
                cout<<"\nDati numarul de comenzi pentru pizza vegetariana: "; cin>>numar_comenzi_v;
                if(numar_comenzi<0)
                    throw(numar_comenzi);
                if(numar_comenzi_v<0)
                    throw(numar_comenzi_v);
                cout<<"\nMENIU PIZZA\n";
                for (int i = 0; i < numar_comenzi; i++)
                    cin >> co_p[i];
                cout<<"\nMENIU PIZZA VEGETARIANA\n";
                for (int i = 0; i < numar_comenzi_v; i++)
                    cin >> co_pv[i];
            }
            catch(int nr){
                cout<<"\nNU SE POATE INTRODUCE UN NUMAR <0 DE COMENZI.\n";
            }
            break;
        }

        case 6:
        {
            cout<<"\nSe vor afisa datele pentru comenzi:\n";
            for (int i = 0; i < numar_comenzi; i++)
                cout<< co_p[i];
            for (int i = 0; i < numar_comenzi_v; i++)
                cout<< co_pv[i];
            break;
        }

        case 7:
        {
            if(ok==0) cout << "\nNU AU FOST MEMORATE DATE IN MENIU, VA ROG INTRODUCETI COMANDA 1 PENTRU O INTRODUCE DATE IN MENIU!\n";
            else
                if(ok_v==0) cout << "\nNU AU FOST MEMORATE DATE IN MENIU, VA ROG INTRODUCETI COMANDA 2 PENTRU O INTRODUCE DATE IN MENIU!\n";
                else
                    cout<<"\nSe vor vinde pizzele comandate:\n";
            for (int i = 0; i < numar_comenzi; i++)
                meniu+=co_p[i];
            for (int i = 0; i < numar_comenzi_v; i++)
                meniu_v+=co_pv[i];
            break;
        }

        case 8:
        {
            try{
                if(ok==0)
                    throw(ok);
                cout<<"\nSe va afisa indexul meniului: "<<meniu.get_Index();
            }
            catch(int ok){
                cout << "\nNU AU FOST MEMORATE DATE IN MENIU, VA ROG INTRODUCETI COMANDA 1 PENTRU O INTRODUCE DATE IN MENIU!\n";
            }
            break;
        }

        case 9:
        {
            try{
                if(ok_v==0)
                    throw(ok_v);
                cout<<"\nSe vor afisa incasarile meniului de pizza vegetariana: ";
                meniu_v.print_incasari();
            }
            catch(int ok_v){
                cout << "\nNU AU FOST MEMORATE DATE IN MENIU, VA ROG INTRODUCETI COMANDA 2 PENTRU O INTRODUCE DATE IN MENIU!\n";
            }
            break;
        }

        case 10:
        {
            cout << "\nMultumesc pentru ca mi-ati folosit programul, o zi buna! :)\n\n";
            exit(0);
            break;
        }

        default:
            cout << "\nOPTIUNE INVALIDA, VA ROG SELECTATI UNA DINTRE CELE DE MAI JOS.\n\n";
            cout << "------------------------------------------------------------------------------------\n\n";
            break;
        }
    }
    return 0;
}