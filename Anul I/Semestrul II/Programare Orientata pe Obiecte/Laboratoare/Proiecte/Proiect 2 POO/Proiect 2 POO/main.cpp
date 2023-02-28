// Tema 11.
// Mihai Andrei-Alexandru, grupa 141, 30.03.2022

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Persoana
{

protected:
    string nume, cnp;

public:
    // constructors
    Persoana()
    {
        // cout<<"Default (Persoana) constructor called\n";
    }

    Persoana(string nume, string cnp)
    {
        // cout<<"Parameterized (Persoana) constructor called\n";
        this->nume = nume;
        if (validare_cnp(cnp) == 1)
            this->cnp = cnp;
        else
            this->cnp = "-1";
    }

    // copy constructor
    Persoana(const Persoana &p1)
    {
        // cout<<"(Persoana) copy constructor called\n";
        nume = p1.nume;
        if (validare_cnp(p1.cnp) == 1)
            cnp = p1.cnp;
        else
            cnp = "-1";
    }

    // destructor
    ~Persoana()
    {
        nume = "\0";
        cnp = "\0";
        // cout<<"(Persoana) object destroied\n";
    }

    // Getters
    string Get_Nume()
    {
        return nume;
    }

    string Get_CNP()
    {
        return cnp;
    }

    // Setters
    void Set_Nume(string nume)
    {
        this->nume = nume;
    }

    void Set_CNP(string cnp)
    {
        this->cnp = cnp;
    }

    // Overloads
    friend istream &operator>>(istream &is, Persoana &p1);

    friend ostream &operator<<(ostream &out, const Persoana &p1);

    Persoana &operator=(const Persoana &p1)
    {
        this->nume = p1.nume;
        this->cnp = p1.cnp;
        return *this;
    }

    void date_cnp(long long x, int &numar_cifre, int &sex, int &zi_nastere, int &luna_nastere, int &an_nastere)
    {
        zi_nastere = x / 1000000 % 100;
        luna_nastere = x / 100000000 % 100;
        an_nastere = x / 10000000000 % 100;
        numar_cifre = 0;
        while (x > 9)
        {
            x /= 10;
            numar_cifre++;
        }
        numar_cifre++;
        sex = x;
    }

    // Functie care calculeaza varsta unei persoane din CNP
    int calcul_varsta(Persoana a)
    {

        time_t now = time(0);
        tm *ltm = localtime(&now);
        long long cnp = stoll(a.cnp);

        int sex, an_nastere, luna_nastere, zi_nastere, an, varsta, numar_cifre;

        date_cnp(cnp, numar_cifre, sex, zi_nastere, luna_nastere, an_nastere);

        if (sex == 1 || sex == 2)
        {
            an = 1900 + an_nastere;
        }
        else if (sex == 5 || sex == 6)
            an = 2000 + an_nastere;
        int an_curent = 1900 + ltm->tm_year;
        varsta = an_curent - an;

        if (ltm->tm_mon < luna_nastere)
            varsta--;
        else if (ltm->tm_mon == luna_nastere)
            if (ltm->tm_mday < zi_nastere)
                varsta--;
        return varsta;
    }

    // Extrage alte date din CNP
    void date_suplimentare(Persoana a)
    {

        long long cnp = stoll(a.cnp);
        int sex, an_nastere, luna_nastere, zi_nastere, an, varsta, numar_cifre;
        date_cnp(cnp, numar_cifre, sex, zi_nastere, luna_nastere, an_nastere);

        cout << "\nPersoana cu numele " << a.nume << ", de sex ";
        if (sex == 1 || sex == 5)
            cout << "M";
        else if (sex == 2 || sex == 6)
            cout << "F";
        if (sex < 3)
            an_nastere += 1900;
        else
            an_nastere += 2000;
        cout << " in varsta de " << calcul_varsta(a) << " este nascut(a) in data de ";
        cout << zi_nastere << "." << luna_nastere << "." << an_nastere << " .\n";
    }

    virtual void afisare_tip()
    {

        cout << "\nDatele afisate sunt de tip PERSOANA.\n";
    }

    int validare_cnp(string CNP)
    {
        long long cnp = stoll(CNP);
        int numar_cifre, sex, zi_nastere, luna_nastere, an_nastere;
        date_cnp(cnp, numar_cifre, sex, zi_nastere, luna_nastere, an_nastere);
        if (numar_cifre != 13)
        {
            cout << "\n!!! Eroare: Numarul de cifre din CNP nu este egal cu 13. Verificati datele introduse!!!\n\n";
            return 0;
        }
        else
        {
            if (sex != 1 && sex != 2 && sex != 5 && sex != 6)
            {
                cout << "\n!!! Eroare: Prima cifra, cea care corespunde sexului este invalida. Verificati datele introduse!!!\n\n";
                return 0;
            }
            if (luna_nastere > 12)
            {
                cout << "\n!!! Eroare: Cifrele 4 si 5, corespunzatoare lunii de nastere sunt invalide. Verificati datele introduse!!!\n\n";
                return 0;
            }
            if (an_nastere > 31)
            {
                cout << "\n!!! Eroare: Cifrele 6 si 7, corespunzatoare anului de nastere sunt invalide. Verificati datele introduse!!!\n\n";
                return 0;
            }
        }
        return 1;
    }
};

istream &operator>>(istream &is, Persoana &p1)
{
    cout << "\nDati numele persoanei: ";
    is >> p1.nume;
    cout << "Dati CNP-ul persoanei: ";
    is >> p1.cnp;
    while (p1.validare_cnp(p1.cnp) != 1)
    {
        cout << "Dati CNP-ul persoanei: ";
        is >> p1.cnp;
    }
    return is;
}

ostream &operator<<(ostream &out, const Persoana &p1)
{
    cout << "\nNumele persoanei este: ";
    out << p1.nume << '\n';
    cout << "CNP-ul persoanei este: ";
    cout << p1.cnp << '\n';
    return out;
}

void tip(Persoana *p)
{
    p->afisare_tip();
}

class Abonat : public Persoana
{

protected:
    int nrMaxCarti, nrCartiImprumutate, pretAbonament;
    int limita = 0;

public:
    // constructors
    Abonat()
    {
        // cout<<"Default (Abonat) contructor called\n";
    }

    Abonat(string nume, string cnp, int nrMaxCarti, int nrCartiImprumutate, int pretAbonament):Persoana(nume,cnp)
    {

        // cout<<"Parameterized (Abonat) contructor called\n";

        this->nrMaxCarti = nrMaxCarti;
        this->nrCartiImprumutate = nrCartiImprumutate;
        this->pretAbonament = pretAbonament;

        if (nrCartiImprumutate > nrMaxCarti)
        {
            limita = 1;
            cout << "\n!!! Abonatul a depasit limita abonamentului, avand numarul de carti imprumutate (";
            cout << nrCartiImprumutate << ") mai mare decat numarul maxim de carti permis in abonamentul sau (";
            cout << nrMaxCarti << ") .!!! \n";
        }
        else if (nrMaxCarti > pretAbonament)
        {
            limita = 2;
            cout << "\n!!! Abonatul a depasit limita abonamentului, avand numarul maxim de carti permis in abonamentul sau (";
            cout << nrMaxCarti << ") mai mare decat pretul abonamentului sau (";
            cout << pretAbonament << ") .!!! \n";
        }
        else
            cout << "\nAbonatul nu a depasit limita.\n";
    }

    // copy constructor
    Abonat(const Abonat &a1):Persoana(a1.nume,a1.cnp)
    {

        // cout<<"(Abonat) copy constructor called\n";
        nrMaxCarti = a1.nrMaxCarti;
        nrCartiImprumutate = a1.nrCartiImprumutate;
        pretAbonament = a1.pretAbonament;
        limita = a1.limita;

        if (limita == 1)
        {
            cout << "\n!!! Abonatul a depasit limita abonamentului, avand numarul de carti imprumutate (";
            cout << nrCartiImprumutate << ") mai mare decat numarul maxim de carti permis in abonamentul sau (";
            cout << nrMaxCarti << ") .!!! \n";
        }
        else if (limita == 2)
        {
            cout << "\n!!!Abonatul a depasit limita abonamentului, avand numarul maxim de carti permis in abonamentul sau (";
            cout << nrMaxCarti << ") mai mare decat pretul abonamentului sau (";
            cout << pretAbonament << ") .!!!\n";
        }
        else
            cout << "\nAbonatul nu a depasit limita.\n";
    }

    // destructor
    ~Abonat()
    {
        // cout<<"(Abonat) object destroied\n";
        nrMaxCarti = nrCartiImprumutate = pretAbonament = 0;
    }

    // Getters
    int Get_nrMaxCarti()
    {
        return nrMaxCarti;
    }

    int Get_NrCartiImprumutate()
    {
        return nrCartiImprumutate;
    }

    int Get_PretAbonament()
    {
        return pretAbonament;
    }

    int Get_Limita()
    {
        return limita;
    }

    // Setters
    void Set_NrMaxCarti(int nrMaxCarti)
    {
        this->nrMaxCarti = nrMaxCarti;
    }

    void Set_NrCartiImprumutate(int nrCartiImprumutate)
    {
        this->nrCartiImprumutate = nrCartiImprumutate;
    }

    void Set_PretAbonament(int pretAbonament)
    {
        this->pretAbonament = pretAbonament;
    }

    void Set_Limita(int limita)
    {
        this->limita = limita;
    }

    // Overloads
    friend istream &operator>>(istream &is, Abonat &a1);

    friend ostream &operator<<(ostream &out, const Abonat &a1);

    Abonat &operator=(const Abonat &a1)
    {
        Persoana::operator=(a1);
        this->nrMaxCarti = a1.nrMaxCarti;
        this->nrCartiImprumutate = a1.nrCartiImprumutate;
        this->pretAbonament = a1.pretAbonament;
        return *this;
    }

    void afisare_tip()
    {
        cout << "\nDatele afisate sunt de tip abonat.\n";
    }
};

istream &operator>>(istream &is, Abonat &a1)
{
    // persoana
    is >> dynamic_cast<Persoana &>(a1);

    // abonat
    cout << "Dati numarul maxim de carti: ";
    is >> a1.nrMaxCarti;
    cout << "Dati numarul de carti imprumutate: ";
    is >> a1.nrCartiImprumutate;
    cout << "Dati pretul abonamentului : ";
    is >> a1.pretAbonament;

    if (a1.nrCartiImprumutate > a1.nrMaxCarti)
    {
        a1.limita = 1;
        cout << "\n!!! Abonatul a depasit limita abonamentului, avand numarul de carti imprumutate (";
        cout << a1.nrCartiImprumutate << ") mai mare decat numarul maxim de carti permis in abonamentul sau (";
        cout << a1.nrMaxCarti << ") .!!! \n";
    }
    else if (a1.nrMaxCarti > a1.pretAbonament)
    {
        a1.limita = 2;
        cout << "\n!!! Abonatul a depasit limita abonamentului, avand numarul maxim de carti permis in abonamentul sau (";
        cout << a1.nrMaxCarti << ") mai mare decat pretul abonamentului sau (";
        cout << a1.pretAbonament << ") .!!! \n";
    }
    else
    {
        a1.limita = 0;
        cout << "\nAbonatul nu a depasit limita.\n";
    }
    return is;
}

ostream &operator<<(ostream &out, const Abonat &a1)
{
    // persoana
    cout << "\nNumele abonatului este: ";
    out << a1.nume << '\n';
    cout << "CNP-ul abonatului este : ";
    out << a1.cnp << '\n';

    // abonat
    cout << "Numarul maxim de carti al abonatului este: ";
    out << a1.nrMaxCarti << '\n';
    cout << "Numarul cartilor imprumutate ale abonatului este: ";
    cout << a1.nrCartiImprumutate << '\n';
    cout << "Pretul abonamentului este : ";
    out << a1.pretAbonament;

    if (a1.limita == 1)
    {
        cout << "\n!!! Abonatul a depasit limita abonamentului, avand numarul de carti imprumutate (";
        cout << a1.nrCartiImprumutate << ") mai mare decat numarul maxim de carti permis in abonamentul sau (";
        cout << a1.nrMaxCarti << ") . !!!\n";
    }
    else if (a1.limita == 2)
    {
        cout << "\n!!! Abonatul a depasit limita abonamentului, avand numarul maxim de carti permis in abonamentul sau (";
        cout << a1.nrMaxCarti << ") mai mare decat pretul abonamentului sau (";
        cout << a1.pretAbonament << ") . !!!\n";
    }
    else
        cout << "\nAbonatul nu a depasit limita.\n";

    return out;
}

class Dosar : public Abonat
{

protected:
    Abonat *abonati;
    int lungime;
    int Nr_Abonati_Stersi = 0;
    Persoana abonati_stersi[101];
    static int deleted;

public:
    // constructors
    Dosar()
    {
        abonati = new Abonat[101];
        // cout<<"Default (Dosar) contructor called\n";
    }

    Dosar(Abonat abonati[], int lungime)
    {
        // cout << "Parameterized (Dosar) contructor called\n";
        this->lungime = lungime;
        for (int i = 1; i <= lungime; i++)
        {
            Abonat aux = *abonati;
            this->abonati[i] = aux;
        }
        Nr_Abonati_Stersi = 0;
    }

    // copy constructor
    Dosar(const Dosar &d1)
    {
        // cout<<"(Dosar) copy constructor called\n";
        lungime = d1.lungime;
        for (int i = 1; i <= lungime; i++)
            abonati[i] = d1.abonati[i];
        Nr_Abonati_Stersi = 0;
    }

    // destructor
    ~Dosar()
    {
        delete abonati;
    }

    // Getters
    int Get_Lungime()
    {
        return lungime;
    }

    Abonat *Get_Abonati()
    {
        return abonati;
    }

    Abonat Get_Abonat_Index(int index)
    {
        return abonati[index];
    }

    // Setters
    void Set_Lungime(int lungime)
    {
        this->lungime = lungime;
    }

    void Set_Abonati(Abonat abonati[])
    {
        Set_Lungime(lungime);
        for (int i = 1; i <= lungime; i++)
            this->abonati[i] = abonati[i];
    }

    // Overloads
    friend istream &operator>>(istream &is, Dosar &d1);

    friend ostream &operator<<(ostream &out, const Dosar &d1);

    Dosar &operator=(const Dosar &d1)
    {
        Abonat::operator=(d1);
        this->lungime = d1.lungime;
        int i;
        for (i = 1; i <= d1.lungime; i++)
            this->abonati[i] = d1.abonati[i];
        return *this;
    }

    // Functie de eliminare a unui abonat din dosar
    void eliminare_abonat(Dosar &d, int index)
    {
        cout << "\nSe va elimina abonatul cu urmatoarele date:\n";
        cout << d.abonati[index];
        ;
        d.Nr_Abonati_Stersi++;
        d.abonati_stersi[d.Nr_Abonati_Stersi] = d.abonati[index];
        deleted++;

        for (int i = index + 1; i <= d.lungime; i++)
            d.abonati[i - 1] = d.abonati[i];
        d.lungime--;
    }

    // Functie care elimina dintr-un dosar toti abonatii care au depasit limita abonamentului
    void eliminare_abonati_limita(Dosar &d, int index_dosar)
    {
        int ok = 0;
        for (int i = 1; i <= d.lungime;)
            if (d.abonati[i].Get_Limita() == 1)
            {
                if (ok == 0)
                {
                    cout << "\nDOSARUL " << index_dosar << ":\n";
                    ok = 1;
                }
                eliminare_abonat(d, i);
            }
            else
                i++;
    }

    // Funtie de creare a unui nou abonat si de adaugare a lui in dosar.
    void adaugare_abonat(Dosar &d, int index, int identificator)
    {
        if (identificator == 0)
        {
            cout << "\nSe va adauga un abonat la pozitia " << index << " cu urmatoarele date:\n\n";
            Abonat a1;
            cin >> a1;

            for (int i = index; i <= d.lungime; i++)
                d.abonati[i + 1] = d.abonati[i];
            d.lungime++;

            d.abonati[index] = a1;
        }
        else
        {
            cout << "\nSe va creea un abonament persoanei cu urmatoarele date:\n\n";
            Persoana p1;
            cin >> p1;
            if (dynamic_cast<Abonat *>(&p1) == NULL)
            {
                int nrMaxCarti, nrCartiImprumutate, pretAbonament;
                cout << "Dati numarul maxim de carti: ";
                cin >> nrMaxCarti;
                cout << "Dati numarul de carti imprumutate: ";
                cin >> nrCartiImprumutate;
                cout << "Dati pretul abonamentului : ";
                cin >> pretAbonament;

                Abonat a1(p1.Get_Nume(), p1.Get_CNP(), nrMaxCarti, nrCartiImprumutate, pretAbonament);

                if (nrCartiImprumutate > nrMaxCarti)
                {
                    a1.Set_Limita(1);
                    cout << "\n!!! Abonatul a depasit limita abonamentului, avand numarul de carti imprumutate (";
                    cout << nrCartiImprumutate << ") mai mare decat numarul maxim de carti permis in abonamentul sau (";
                    cout << nrMaxCarti << ") .!!! \n";
                }
                else if (nrMaxCarti > pretAbonament)
                {
                    a1.Set_Limita(2);
                    cout << "\n!!! Abonatul a depasit limita abonamentului, avand numarul maxim de carti permis in abonamentul sau (";
                    cout << nrMaxCarti << ") mai mare decat pretul abonamentului sau (";
                    cout << pretAbonament << ") .!!! \n";
                }
                else
                {
                    a1.Set_Limita(0);
                    cout << "\nAbonatul nu a depasit limita.\n";
                }
                for (int i = index; i <= d.lungime; i++)
                    d.abonati[i + 1] = d.abonati[i];
                d.lungime++;

                d.abonati[index] = a1;
            }
        }
    }

    // Functie care afiseaza numarul de abonati care au fost stersi din toate dosarele
    static void print_deleted()
    {
        if (deleted == 0)
            cout << "\nNu a fost eliminat niciun abonat din dosare.\n";
        else if (deleted == 1)
            cout << "A fost eliminat un singur abonat din toate dosarele.\n";
        else
            cout << "\nNumarul de abonati care au fost eliminati din toate dosarele este de " << deleted << "." << endl;
    }

    // Functie care afiseaza numarul de abonati care au fost stersi din toate dosarele
    void afisare_nr_abonati_stersi()
    {
        if (Nr_Abonati_Stersi == 0)
            cout << "\nNu a fost eliminat niciun abonat din dosar.\n";
        else if (Nr_Abonati_Stersi == 1)
            cout << "A fost eliminat un singur abonat din dosar.\n";
        else
            cout << "\nNumarul de abonati care au fost eliminati din dosar este de " << Nr_Abonati_Stersi << "." << endl;
    }

    void afisare_abonati_stersi(Dosar &d, int index_dosar)
    {
        int i;
        cout << "\nDOSARUL " << index_dosar << ":\n";
        for (i = 1; i <= d.Nr_Abonati_Stersi; i++)
            cout << d.abonati_stersi[i];

        tip(d.abonati_stersi);
    }
};

int Dosar::deleted = 0;

istream &operator>>(istream &is, Dosar &d1)
{
    cout << "\nDati lungimea dosarului: ";
    is >> d1.lungime;
    if (d1.lungime)
    {
        cout << "\nDati date despre abonati:\n";
        for (int i = 1; i <= d1.lungime; i++)
            is >> d1.abonati[i];
    }
    return is;
}

ostream &operator<<(ostream &out, const Dosar &d1)
{
    if (d1.lungime == 0)
        cout << "\nDosarul este gol, nu exista abonati in dosar.\n";
    else
    {
        if (d1.lungime == 1)
            cout << "\n\nEste un singur abonat in dosar, cu urmatoarele date:\n";
        else
            cout << "\n\nSunt " << d1.lungime << " abonati in dosar, cu urmatoarele date:\n";
        for (int i = 1; i <= d1.lungime; i++)
        {
            out << d1.abonati[i];
            cout << "\n";
        }
    }
    return out;
}

void citire_dosare(int &n, Dosar d[])
{
    int i;
    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "\nIntroduceti numarul de dosare: ";
    cin >> n;
    cout << "\n------------------------------------------------------------------------------------\n\n";
    cout << "Introduceti date in fiecare dosar:\n\n";
    for (i = 1; i <= n; i++)
    {
        cout << "DOSARUL " << i << '\n';
        cin >> d[i];
        cout << '\n';
    }
}

void afisare_dosare(int n, Dosar d[])
{
    int i;
    cout << "------------------------------------------------------------------------------------\n\n";
    cout << "AU FOST INTRODUSE DATE IN URMATOARELE DOSARE:\n\n";
    for (i = 1; i <= n; i++)
    {
        cout << "DOSARUL " << i << '\n';
        cout << d[i] << "\n";
    }

    tip(d->Get_Abonati());
}

int main()
{
    Dosar dosare[101];
    int n, ok = 0;
    while (true)
    {
        int optiune;
        cout << "\n------------------------------------------------------------------------------------\n\n";
        cout << "VA ROG SELECTATI OPTIUNEA DIN MENIUL DE MAI JOS PRIN INTRODUCEREA NUMARULUI CORESPUNZATOR IN CONSOLA.\n\n";
        cout << "1. Introducerea datelor in dosare.\n";
        cout << "2. Afisarea datelor din toate dosarele.\n";
        cout << "3. Afisarea datelor dintr-un anumit dosar.\n";
        cout << "4. Prelucrarea datelor dintr-un anumit dosar.\n";
        cout << "5. Stergerea din toate dosarele a abonatilor care au depasit limita abonamentului.\n";
        cout << "6. Afisarea numarului de abonati stersi din toate dosarele.\n";
        cout << "7. Afisarea tuturor persoanelor care au fost sterse din dosare.\n";
        cout << "8. Iesire din program.\n\n";
        cout << "Optiune: ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
        {
            citire_dosare(n, dosare);
            ok = 1;
            break;
        }
        case 2:
        {
            if (ok == 1)
                afisare_dosare(n, dosare);
            else
                cout << "\nNU AU FOST MEMORATE DATE IN NICIUN DOSAR, VA ROG INTRODUCETI COMANDA 1 PENTRU O INTRODUCE DATE IN DOSARE!\n";
            break;
        }
        case 3:
        {
            if (ok == 1)
            {
                cout << "------------------------------------------------------------------------------------\n\n";
                cout << "Introduceti indexul dosarului pe care doriti sa il afisati (un numar de la 1 la " << n << "):";
                int numar_dosar;
                cin >> numar_dosar;
                while (numar_dosar < 1 || numar_dosar > n)
                {
                    cout << "\nAti introdus un index de dosar invalid, va rog introduceti in consola o valoare cuprinsa intre 1 si " << n << '\n';
                    cout << "Introduceti indexul dosarului pe care doriti sa il afisati (un numar de la 1 la " << n << "):";
                    cin >> numar_dosar;
                }

                cout << dosare[numar_dosar];
            }
            else
                cout << "\nNU AU FOST MEMORATE DATE IN NICIUN DOSAR, VA ROG INTRODUCETI COMANDA 1 PENTRU O INTRODUCE DATE IN DOSARE!\n";
            break;
        }
        case 4:
        {
            if (ok == 1)
            {
                cout << "------------------------------------------------------------------------------------\n\n";
                cout << "Introduceti indexul dosarului pe care doriti sa il afisati (un numar de la 1 la " << n << "): ";
                int numar_dosar;
                cin >> numar_dosar;
                while (numar_dosar < 1 || numar_dosar > n)
                {
                    cout << "\nAti introdus un index de dosar invalid, va rog introduceti in consola o valoare cuprinsa intre 1 si " << n << '\n';
                    cout << "Introduceti indexul dosarului pe care doriti sa il afisati (un numar de la 1 la " << n << "):";
                    cin >> numar_dosar;
                }

                int optiune_submeniu;
                while (true)
                {

                    cout << "\n------------------------------------------------------------------------------------\n\n";
                    cout << "VA ROG SELECTATI OPTIUNEA DIN MENIUL DE MAI JOS PRIN INTRODUCEREA NUMARULUI CORESPUNZATOR IN CONSOLA.\n\n";
                    cout << "9.  Afisarea datelor din dosarul selectat.\n";
                    cout << "10. Stergerea unui anumit abonat din dosarul selectat.\n";
                    cout << "11. Stergerea din dosarul selectat a tuturor abonatilor care depasesc limitele abonamentului.\n";
                    cout << "12. Afisarea numarului de abonati care au fost stersi .\n";
                    cout << "13. Adaugarea unui abonat in dosarul selectat.\n";
                    cout << "14. Afisarea datelor suplimentare (extrase din CNP) ale unui abonat din dosarul selectat.\n";
                    cout << "15. Iesire din submeniu.\n\n";
                    cout << "Optiune: ";

                    cin >> optiune_submeniu;

                    if (optiune_submeniu == 9)
                    {
                        cout << "\n------------------------------------------------------------------------------------\n\n";
                        cout << "Se vor afisa datele din dosarul selectat, cu indexul " << numar_dosar << " .\n";
                        cout << dosare[numar_dosar];
                    }
                    else if (optiune_submeniu == 10)
                    {
                        cout << "\n------------------------------------------------------------------------------------\n\n";
                        int index_abonat;
                        cout << "\nDati indexul abonatului pe care doriti sa-l stergeti (un numar natural intre 1 si " << dosare[numar_dosar].Get_Lungime() << ") .\n";
                        cin >> index_abonat;
                        while (index_abonat < 1 || index_abonat > dosare[numar_dosar].Get_Lungime())
                        {
                            cout << "\nAti introdus un index de dosar invalid, va rog introduceti in consola o valoare cuprinsa intre 1 si " << n << '\n';
                            cout << "Introduceti indexul abonatului pe care doriti sa il afisati (un numar de la 1 la " << dosare[numar_dosar].Get_Lungime() << "):";
                            cin >> index_abonat;
                        }
                        cout << "Se va sterge abonatul cu indexul " << index_abonat << " din dosar .\n";
                        dosare[numar_dosar].eliminare_abonat(dosare[numar_dosar], index_abonat);
                    }
                    else if (optiune_submeniu == 11)
                    {
                        cout << "\n------------------------------------------------------------------------------------\n\n";
                        cout << "Se vor elimina din dosar toti abonatii care au depasit limita abonamentului.\n";
                        dosare[numar_dosar].eliminare_abonati_limita(dosare[numar_dosar], numar_dosar);
                    }
                    else if (optiune_submeniu == 12)
                    {
                        cout << "\n------------------------------------------------------------------------------------\n\n";
                        cout << "Se va afisa numarul de abonati care au fost stersi din dosarul selectat. \n";
                        dosare[numar_dosar].afisare_nr_abonati_stersi();
                    }
                    else if (optiune_submeniu == 13)
                    {
                        cout << "\n------------------------------------------------------------------------------------\n\n";
                        while (true)
                        {
                            cout << "Doriti sa adaugati un abonat la dosar sau sa creati un abonament pentru o persoana? [A/P] \n";
                            char optiune;
                            cin >> optiune;
                            cin.get();
                            if (optiune == 'A' or optiune == 'a')
                            {
                                dosare[numar_dosar].adaugare_abonat(dosare[numar_dosar], 1, 0);
                                break;
                            }
                            else if (optiune == 'P' or optiune == 'p')
                            {
                                dosare[numar_dosar].adaugare_abonat(dosare[numar_dosar], 1, 1);
                                break;
                            }
                            else
                                cout << "\nOptiune invalida!\n";
                        }
                    }
                    else if (optiune_submeniu == 14)
                    {
                        cout << "\n------------------------------------------------------------------------------------\n\n";
                        int index_abonat;
                        cout << "\nDati indexul abonatului caruia doriti sa-i aflati datele (un numar natural intre 1 si " << dosare[numar_dosar].Get_Lungime() << ") :\n";
                        cin >> index_abonat;
                        while (index_abonat < 1 || index_abonat > dosare[numar_dosar].Get_Lungime())
                        {
                            cout << "\nAti introdus un index de dosar invalid, va rog introduceti in consola o valoare cuprinsa intre 1 si " << n << '\n';
                            cout << "\nDati indexul abonatului caruia doriti sa-i aflati datele (un numar natural intre 1 si " << dosare[numar_dosar].Get_Lungime() << ") :\n";
                            cin >> index_abonat;
                        }
                        cout << "Se vor afisa datele abonatului " << index_abonat << " din dosarul selectat .\n";
                        dosare[numar_dosar].date_suplimentare(dosare[numar_dosar].Get_Abonat_Index(index_abonat));
                    }
                    else if (optiune_submeniu == 15)
                    {
                        cout << "\n------------------------------------------------------------------------------------\n\n";
                        cout << "Se va iesi din acest submeniu.\n";
                        break;
                    }
                    else
                    {
                        cout << "\nOPTIUNE INVALIDA, VA ROG SELECTATI UNA DINTRE CELE DE MAI JOS.\n\n";
                        cout << "------------------------------------------------------------------------------------\n\n";
                    }
                }
            }
            else
                cout << "\nNU S-A MEMORAT NICIO MULTIME, VA ROG INTRODUCETI COMANDA 1 PENTRU O INTRODUCE DATE DESPRE MULTIMI!\n";
            break;
        }

        case 5:
        {
            cout << "\n------------------------------------------------------------------------------------\n\n";
            cout << "Se vor elimina din toate dosarele abonatii care au depasit limita abonamentului .\n";
            if (ok == 1)
            {
                for (int i = 1; i <= n; i++)
                    dosare[i].eliminare_abonati_limita(dosare[i], i);
            }
            else
                cout << "\nNU AU FOST MEMORATE DATE IN NICIUN DOSAR, VA ROG INTRODUCETI COMANDA 1 PENTRU O INTRODUCE DATE IN DOSARE!\n";
            break;
        }

        case 6:
        {
            if (ok == 1)
            {
                cout << "\n------------------------------------------------------------------------------------\n\n";
                cout << "\nSe va afisa numarul de abonati care au fost stersi din toate dosarele.\n";
                dosare->print_deleted();
            }
            else
                cout << "\nNU AU FOST MEMORATE DATE IN NICIUN DOSAR, VA ROG INTRODUCETI COMANDA 1 PENTRU O INTRODUCE DATE IN DOSARE!\n";
            break;
        }

        case 7:
        {
            if (ok == 1)
            {
                cout << "\nSe va afisa pe ecran pentru fiecare dosar lista persoanelor care au fost sterse.\n";
                for (int i = 1; i <= n; i++)
                    dosare[i].afisare_abonati_stersi(dosare[i], i);
            }
            else
                cout << "\nNU AU FOST MEMORATE DATE IN NICIUN DOSAR, VA ROG INTRODUCETI COMANDA 1 PENTRU O INTRODUCE DATE IN DOSARE!\n";
            break;
        }

        case 8:
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
