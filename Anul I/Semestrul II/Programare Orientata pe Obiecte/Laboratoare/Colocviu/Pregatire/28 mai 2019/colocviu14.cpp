#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Bilet
{
protected:
    string statiePlecare, statieSosire, serie;
    int an, luna, zi, ora, minut;
    int cod, durata, distanta;
    double pret;

public:
    virtual void generare_serie() {}

    virtual void calcul_pret() {}

    Bilet() {}

    Bilet(string statiePlecare, string statieSosire, int an, int luna, int zi, int ora, int minut, int cod, int durata, int distanta)
    {
        this->statiePlecare = statiePlecare;
        this->statieSosire = statieSosire;
        this->an = an;
        this->luna = luna;
        this->zi = zi;
        this->ora = ora;
        this->minut = minut;
        this->cod = cod;
        this->durata = durata;
        this->distanta = distanta;
    }

    Bilet(const Bilet &b1)
    {
        this->statiePlecare = b1.statiePlecare;
        this->statieSosire = b1.statieSosire;
        this->an = b1.an;
        this->luna = b1.luna;
        this->zi = b1.zi;
        this->ora = b1.ora;
        this->minut = b1.minut;
        this->cod = b1.cod;
        this->durata = b1.durata;
        this->distanta = b1.distanta;
    }

    virtual ~Bilet()
    {
        statiePlecare = statieSosire = "";
        an = luna = zi = ora = minut = cod = durata = distanta = 0;
    }

    string getstatiePlecare() const
    {
        return statiePlecare;
    }

    string getstatieSosire() const
    {
        return statieSosire;
    }

    int getAn() const
    {
        return an;
    }

    int getLuna() const
    {
        return luna;
    }

    int getZi() const
    {
        return zi;
    }

    int getOra() const
    {
        return ora;
    }

    int getMinut() const
    {
        return minut;
    }
    int getCod() const
    {
        return cod;
    }

    int getDurata() const
    {
        return durata;
    }

    int getDistanta() const
    {
        return distanta;
    }

    string getSerie()
    {
        return serie;
    }

    void setStatiePlecare(string s)
    {
        statiePlecare = s;
    }

    void setStatieSosire(string s)
    {
        statieSosire = s;
    }

    void setAn(int a)
    {
        an = a;
    }

    void setLuna(int l)
    {
        luna = l;
    }

    void setZi(int z)
    {
        zi = z;
    }

    void setOra(int o)
    {
        ora = o;
    }

    void setMinut(int m)
    {
        minut = m;
    }

    void setCod(int c)
    {
        cod = c;
    }

    void setDurata(int d)
    {
        durata = d;
    }

    void setDistanta(int d)
    {
        distanta = d;
    }

    Bilet &operator=(const Bilet &b1)
    {
        this->statiePlecare = b1.statiePlecare;
        this->statieSosire = b1.statieSosire;
        this->an = b1.an;
        this->luna = b1.luna;
        this->zi = b1.zi;
        this->ora = b1.ora;
        this->minut = b1.minut;
        this->cod = b1.cod;
        this->durata = b1.durata;
        this->distanta = b1.distanta;
        return *this;
    }

    friend istream &operator>>(istream &is, Bilet &b1);
    friend ostream &operator<<(ostream &out, const Bilet &b1);

    virtual void afisare()
    {
        cout << "\nstatiePlecare: " << statiePlecare;
        cout << "\nstatieSosire: " << statieSosire;
        cout << "\ndata:" << zi << "." << luna << "." << an;
        cout << "\nla ora: " << ora << ":" << minut;
        cout << "\ncod :" << cod;
        cout << "\ndurata: " << durata;
        cout << "\ndistanta: " << distanta;
    }
};

istream &operator>>(istream &is, Bilet &b1)
{
    cout << "statiePlecare: ";
    is >> b1.statiePlecare;
    cout << "statieSosire: ";
    is >> b1.statieSosire;
    cout << "\ndata:\n";
    while (true)
    {
        try
        {
            cout << "an: ";
            is >> b1.an;
            if (b1.an < 1)
                throw string("\nInvalid!\n");
            cout << "luna: ";
            is >> b1.luna;
            if (b1.luna < 1 || b1.luna > 12)
                throw string("\nInvalid!\n");
            cout << "zi: ";
            is >> b1.zi;
            if (b1.zi < 1 || b1.luna > 31)
                throw string("\nInvalid!\n");
            cout << "ora: ";
            is >> b1.ora;
            if (b1.ora < 0 || b1.ora > 24)
                throw string("\nInvalid!\n");
            cout << "minut: ";
            is >> b1.minut;
            if (b1.minut < 0 || b1.minut > 59)
                throw string("\nInvalid!\n");
            cout << "cod :";
            is >> b1.cod;
            cout << "durata: ";
            is >> b1.durata;
            cout << "distanta: ";
            is >> b1.distanta;
            break;
        }
        catch (string s)
        {
            cout << s << endl;
        }
    }
    return is;
}

ostream &operator<<(ostream &out, const Bilet &b1)
{
    out << "\nstatiePlecare: " << b1.statiePlecare;
    out << "\nstatieSosire: " << b1.statieSosire;
    out << "\ndata:" << b1.zi << "." << b1.luna << "." << b1.an;
    out << "\nla ora: " << b1.ora << ":" << b1.minut;
    out << "\ncod :" << b1.cod;
    out << "\ndurata: " << b1.durata;
    out << "\ndistanta: " << b1.distanta;
    return out;
}

class BiletRegio : public Bilet
{
protected:
    string clasa;
    static int numarOrdineR;

public:
    void generare_serie()
    {
        serie += "R-";
        serie += clasa;
        serie += "-";
        serie += to_string(numarOrdineR);
    }

    void calcul_pret()
    {
        pret = 0.39 * distanta;
        if (clasa == "I")
            pret += 0.2 * pret;
    }

    BiletRegio() {}

    BiletRegio(string statiePlecare, string statieSosire, int an, int luna, int zi,
               int ora, int minut, int cod, int durata, int distanta, string clasa) : Bilet(statiePlecare, statieSosire, an, luna, zi, ora, minut, cod, durata, distanta)
    {
        this->clasa = clasa;
        generare_serie();
        calcul_pret();
        numarOrdineR++;
    }

    BiletRegio(const BiletRegio &b1)
    {
        this->statiePlecare = b1.statiePlecare;
        this->statieSosire = b1.statieSosire;
        this->an = b1.an;
        this->luna = b1.luna;
        this->zi = b1.zi;
        this->ora = b1.ora;
        this->minut = b1.minut;
        this->cod = b1.cod;
        this->durata = b1.durata;
        this->distanta = b1.distanta;
        this->pret = b1.pret;
        this->clasa = b1.clasa;
        this->serie = serie;
    }

    virtual ~BiletRegio()
    {
        statiePlecare = statieSosire = clasa = "";
        an = luna = zi = ora = minut = cod = durata = distanta = 0;
    }

    string getClasa() const
    {
        return clasa;
    }

    double getPret() const
    {
        return pret;
    }

    void setSerie()
    {
        generare_serie();
    }

    void setClasa(string c)
    {
        clasa = c;
    }

    void setPret()
    {
        calcul_pret();
    }

    BiletRegio &operator=(const BiletRegio &b1)
    {
        this->statiePlecare = b1.statiePlecare;
        this->statieSosire = b1.statieSosire;
        this->an = b1.an;
        this->luna = b1.luna;
        this->zi = b1.zi;
        this->ora = b1.ora;
        this->minut = b1.minut;
        this->cod = b1.cod;
        this->durata = b1.durata;
        this->distanta = b1.distanta;
        this->pret = b1.pret;
        this->clasa = b1.clasa;
        this->serie = serie;
        return *this;
    }

    friend istream &operator>>(istream &is, BiletRegio &b1);
    friend ostream &operator<<(ostream &out, const BiletRegio &b1);

    void afisare()
    {
        cout << "\nstatiePlecare: " << statiePlecare;
        cout << "\nstatieSosire: " << statieSosire;
        cout << "\ndata:" << zi << "." << luna << "." << an;
        cout << "\nla ora: " << ora << ":" << minut;
        cout << "\ncod :" << cod;
        cout << "\ndurata: " << durata;
        cout << "\ndistanta: " << distanta;
        cout << "\npret: " << pret;
        cout << "\nclasa: " << clasa;
        cout << "\nserie: " << serie << endl;
    }
};

istream &operator>>(istream &is, BiletRegio &b1)
{
    cout << "statiePlecare: ";
    is >> b1.statiePlecare;
    cout << "statieSosire: ";
    is >> b1.statieSosire;
    cout << "\ndata:\n";

    while (true)
    {
        try
        {
            cout << "an: ";
            is >> b1.an;
            if (b1.an < 1)
                throw string("\nInvalid!\n");
            cout << "luna: ";
            is >> b1.luna;
            if (b1.luna < 1 || b1.luna > 12)
                throw string("\nInvalid!\n");
            cout << "zi: ";
            is >> b1.zi;
            if (b1.zi < 1 || b1.luna > 31)
                throw string("\nInvalid!\n");
            cout << "ora: ";
            is >> b1.ora;
            if (b1.ora < 0 || b1.ora > 24)
                throw string("\nInvalid!\n");
            cout << "minut: ";
            is >> b1.minut;
            if (b1.minut < 0 || b1.minut > 59)
                throw string("\nInvalid!\n");
            cout << "cod :";
            is >> b1.cod;
            cout << "durata: ";
            is >> b1.durata;
            cout << "distanta: ";
            is >> b1.distanta;
            cout << "clasa: ";
            is >> b1.clasa;
            b1.generare_serie();
            b1.numarOrdineR++;
            b1.calcul_pret();
            break;
        }
        catch (string s)
        {
            cout << s << endl;
        }
    }
    return is;
}

ostream &operator<<(ostream &out, const BiletRegio &b1)
{
    out << "\nstatiePlecare: " << b1.statiePlecare;
    out << "\nstatieSosire: " << b1.statieSosire;
    out << "\ndata:" << b1.zi << "." << b1.luna << "." << b1.an;
    out << "\nla ora: " << b1.ora << ":" << b1.minut;
    out << "\ncod :" << b1.cod;
    out << "\ndurata: " << b1.durata;
    out << "\ndistanta: " << b1.distanta;
    out << "\npret: " << b1.pret;
    out << "\nclasa: " << b1.clasa;
    out << "\nserie: " << b1.serie << endl;
    return out;
}

class BiletInterRegio : public Bilet
{
protected:
    int locRezervat;
    string clasa;
    static int numarOrdineIR;

public:
    void generare_serie()
    {
        serie += "IR-";
        serie += clasa;
        serie += "-";
        serie += to_string(numarOrdineIR);
    }

    void calcul_pret()
    {
        pret = 0.7 * distanta;
        if (clasa == "I")
            pret += 0.2 * pret;
    }

    BiletInterRegio() {}

    BiletInterRegio(string statiePlecare, string statieSosire, int an, int luna, int zi,
                    int ora, int minut, int cod, int durata, int distanta, int locRezervat, string clasa) : Bilet(statiePlecare, statieSosire, an, luna, zi, ora, minut, cod, durata, distanta)
    {
        this->clasa = clasa;
        this->locRezervat = locRezervat;
        generare_serie();
        numarOrdineIR++;
        calcul_pret();
    }

    BiletInterRegio(const BiletInterRegio &b1)
    {
        this->statiePlecare = b1.statiePlecare;
        this->statieSosire = b1.statieSosire;
        this->an = b1.an;
        this->luna = b1.luna;
        this->zi = b1.zi;
        this->ora = b1.ora;
        this->minut = b1.minut;
        this->cod = b1.cod;
        this->durata = b1.durata;
        this->distanta = b1.distanta;
        this->pret = b1.pret;
        this->clasa = b1.clasa;
        this->locRezervat = b1.locRezervat;
        this->serie = serie;
    }

    virtual ~BiletInterRegio()
    {
    }

    string getClasa() const
    {
        return clasa;
    }

    int getLocRezervat() const
    {
        return locRezervat;
    }

    double getPret() const
    {
        return pret;
    }

    void setSerie()
    {
        generare_serie();
    }

    void setClasa(string c)
    {
        clasa = c;
    }

    void setLocRezervat(int l)
    {
        locRezervat = l;
    }

    void setPret()
    {
        calcul_pret();
    }

    BiletInterRegio &operator=(const BiletInterRegio &b1)
    {
        this->statiePlecare = b1.statiePlecare;
        this->statieSosire = b1.statieSosire;
        this->an = b1.an;
        this->luna = b1.luna;
        this->zi = b1.zi;
        this->ora = b1.ora;
        this->minut = b1.minut;
        this->cod = b1.cod;
        this->durata = b1.durata;
        this->distanta = b1.distanta;
        this->pret = b1.pret;
        this->clasa = b1.clasa;
        this->locRezervat = b1.locRezervat;
        this->serie = serie;
        return *this;
    }

    friend istream &operator>>(istream &is, BiletInterRegio &b1);
    friend ostream &operator<<(ostream &out, const BiletInterRegio &b1);

    void afisare()
    {
        cout << "\nstatiePlecare: " << statiePlecare;
        cout << "\nstatieSosire: " << statieSosire;
        cout << "\ndata:" << zi << "." << luna << "." << an;
        cout << "\nla ora: " << ora << ":" << minut;
        cout << "\ncod :" << cod;
        cout << "\ndurata: " << durata;
        cout << "\ndistanta: " << distanta;
        cout << "\npret: " << pret;
        cout << "\nclasa: " << clasa;
        cout << "\nlocRezervat: " << locRezervat;
        cout << "\nserie: " << serie << endl;
    }
};

istream &operator>>(istream &is, BiletInterRegio &b1)
{
    cout << "statiePlecare: ";
    is >> b1.statiePlecare;
    cout << "statieSosire: ";
    is >> b1.statieSosire;
    cout << "\ndata:\n";
    while (true)
    {
        try
        {
            cout << "an: ";
            is >> b1.an;
            if (b1.an < 1)
                throw string("\nInvalid!\n");
            cout << "luna: ";
            is >> b1.luna;
            if (b1.luna < 1 || b1.luna > 12)
                throw string("\nInvalid!\n");
            cout << "zi: ";
            is >> b1.zi;
            if (b1.zi < 1 || b1.luna > 31)
                throw string("\nInvalid!\n");
            cout << "ora: ";
            is >> b1.ora;
            if (b1.ora < 0 || b1.ora > 24)
                throw string("\nInvalid!\n");
            cout << "minut: ";
            is >> b1.minut;
            if (b1.minut < 0 || b1.minut > 59)
                throw string("\nInvalid!\n");
            cout << "cod :";
            is >> b1.cod;
            cout << "durata: ";
            is >> b1.durata;
            cout << "distanta: ";
            is >> b1.distanta;
            cout << "clasa: ";
            is >> b1.clasa;
            cout << "locRezervat: ";
            is >> b1.locRezervat;
            b1.generare_serie();
            b1.numarOrdineIR++;
            b1.calcul_pret();
            break;
        }
        catch (string s)
        {
            cout << s << endl;
        }
    }
    return is;
}

ostream &operator<<(ostream &out, const BiletInterRegio &b1)
{
    out << "\nstatiePlecare: " << b1.statiePlecare;
    out << "\nstatieSosire: " << b1.statieSosire;
    out << "\ndata:" << b1.zi << "." << b1.luna << "." << b1.an;
    out << "\nla ora: " << b1.ora << ":" << b1.minut;
    out << "\ncod :" << b1.cod;
    out << "\ndurata: " << b1.durata;
    out << "\ndistanta: " << b1.distanta;
    out << "\npret: " << b1.pret;
    out << "\nclasa: " << b1.clasa;
    out << "\nlocRezervat: " << b1.locRezervat;
    out << "\nserie: " << b1.serie << endl;
    return out;
}

void afisare_bilete_tren(vector<Bilet *> bilete, int cod)
{
    int ok = 0;
    cout << "Se vor afisa biletele eliberate pentru trenul cu codul " << cod << endl;
    for (int i = 0; i < bilete.size(); i++)
    {
        if (bilete[i]->getCod() == cod)
        {
            bilete[i]->afisare();
            cout << endl;
            ok = 1;
            break;
        }
    }
    if (ok == 0)
        cout << "\nNu exista.\n";
}

void afisare_bilete_distanta(vector<Bilet *> bilete, int distanta)
{
    int ok = 0;
    cout << "Se vor afisa biletele eliberate pentru calatorii pe o distanta mai mare de " << distanta << endl;
    for (int i = 0; i < bilete.size(); i++)
    {
        if (bilete[i]->getDistanta() > distanta)
        {
            bilete[i]->afisare();
            cout << endl;
            ok = 1;
        }
    }
    if (ok == 0)
        cout << "\nNu exista.\n";
}


//nu merge
void anulare_bilet(vector<Bilet *> bilete, string serie)
{
    cout << "Se va anula biletul care are seria " << serie;
    for (int i = 0; i < bilete.size(); i++)
    {
        if (bilete[i]->getSerie() == serie){
            bilete.erase(bilete.begin() + i);
            break;
        }
    }
}

void afisare_bilete(vector<Bilet *> bilete)
{
    for (int i = 0; i < bilete.size(); i++)
    {
        bilete[i]->afisare();
        cout << endl;
    }
}

int BiletRegio::numarOrdineR = 1;
int BiletInterRegio::numarOrdineIR = 1;

int main()
{
    vector<Bilet *> bilete;
    Bilet *b; BiletInterRegio b2; BiletRegio b1;
    int optiune;
    while (true)
    {
        try
        {
            cout << "\n\n1.Eliberare bilet nou.\n";
            cout << "2.Afisarea tutoror biletelor.\n";
            cout << "3.Listarea biletelor eliberate pentru un anumit tren.\n";
            cout << "4.Listarea biletelor eliberate pentru calatorii pe o distanta mai mare ca o valoare data.\n";
            cout << "5.Anularea unui bilet.\n";
            cout << "6.Exit.\n\n";
            cin >> optiune;
            if (optiune < 1 || optiune > 6)
                throw string("Invalid!\n");
            if (optiune == 1)
            {
                string tip;
                cout << "Ce fel de tren doriti sa luati? (R/IR)\n";
                try
                {
                    cin >> tip;
                    if (tip != "R" && tip != "IR")
                        throw string("Invalid!\n");
                    else if (tip == "R")
                    {
                        cin >> b1;
                        b = &b1;
                        bilete.push_back(b);
                    }
                    else
                    {
                        cin >> b2;
                        b = &b2;
                        bilete.push_back(b);
                    }
                }
                catch (string s)
                {
                    cout << s << endl;
                }
            }
            else if (optiune == 2)
            {
                afisare_bilete(bilete);
            }
            else if (optiune == 3)
            {
                int cod;
                cout << "\nDati cod: ";
                cin >> cod;
                afisare_bilete_tren(bilete, cod);
            }
            else if (optiune == 4)
            {
                int distanta;
                cout << "\nDati distanta: ";
                cin >> distanta;
                afisare_bilete_distanta(bilete, distanta);
            }
            else if (optiune == 5)
            {
                string serie;
                cout << "\nDati serie: ";
                cin >> serie;
                anulare_bilet(bilete, serie);
            }
            else if (optiune == 6)
            {
                cout << "Se va iesi din program.\n";
                break;
            }
        }
        catch (string s)
        {
            cout << s << endl;
        }
    }
    return 0;
}