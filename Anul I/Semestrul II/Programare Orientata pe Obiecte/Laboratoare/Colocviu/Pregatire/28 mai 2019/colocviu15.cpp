#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Statie
{
protected:
    string strada;
    int numar, sector;
    vector<int> transport;
    string nume, codStatie = "";
    static int numarOrdine;

public:
    Statie() {}

    Statie(string strada, int numar, int sector, vector<int> transport, string nume)
    {
        this->strada = strada;
        this->numar = numar;
        this->sector = sector;
        this->transport = transport;
        this->nume = nume;
    }

    Statie(const Statie &s1)
    {
        this->strada = s1.strada;
        this->numar = s1.numar;
        this->sector = s1.sector;
        this->transport = s1.transport;
        this->nume = s1.nume;
        this->codStatie = s1.codStatie;
    }

    ~Statie()
    {
        strada = nume = codStatie = "";
        transport.clear();
        numar = sector = 0;
    }

    string getStrada() const
    {
        return strada;
    }

    void setStrada(string s)
    {
        strada = s;
    }

    int getNumar() const
    {
        return numar;
    }

    void setNume(int nr)
    {
        numar = nr;
    }

    int getSector() const
    {
        return sector;
    }

    void setSector(int s)
    {
        sector = s;
    }

    vector<int> getTransport() const
    {
        return transport;
    }

    void setTransport(vector<int> t)
    {
        transport = t;
    }

    string getNume() const
    {
        return nume;
    }

    void setNume(string n)
    {
        nume = n;
    }

    string getCodStatie() const
    {
        return codStatie;
    }

    void setCodStatie()
    {
        generareCodStatie();
    }

    int getNumarOrdine() const
    {
        return numarOrdine;
    }

    // void setCodStatie();

    Statie &operator=(const Statie &s1)
    {
        this->strada = s1.strada;
        this->numar = s1.numar;
        this->sector = s1.sector;
        this->transport = s1.transport;
        this->nume = s1.nume;
        this->codStatie = s1.codStatie;
        return *this;
    }

    friend istream &operator>>(istream &is, Statie &s){
        return s.citire(is);
    }

    friend ostream &operator<<(ostream &out, Statie &s){
        return s.afisare(out);
    }

    virtual istream& citire(istream &is)
    {
        cout << "strada: ";
        is >> strada;
        cout << "numa: ";
        is >> numar;
        cout << "sector :";
        is >> sector;
        // codstatie
        int nr, cod;
        cout << "numarul de mijloace de transport :";
        cin >> nr;
        cout << "codurile:\n";
        for (int i = 0; i < nr; i++)
        {
            cin >> cod;
            transport.push_back(cod);
        }
        cout << "\nnume: ";
        is >> nume;
        return is;
    }

    virtual ostream& afisare(ostream &out)
    {
        out << "\nstrada: " << strada;
        out << "\nnumar: " << numar;
        out << "\nsector :" << sector;
        out << "\ncodStatie: " << codStatie;
        out << "\ncodurile:\n";
        for (int i = 0; i < transport.size(); i++)
            out << transport[i] << ' ';
        out << "\nnume: " << nume;
        return out;
    }

    virtual void generareCodStatie(){};
};

int Statie::numarOrdine = 1;

class StatieUrbana : public Statie
{
public:
    void generareCodStatie()
    {
        codStatie += "SU";
        codStatie += "-";
        codStatie += to_string(numarOrdine);
        numarOrdine++;
    }

    StatieUrbana() {}

    StatieUrbana(string strada, int numar, int sector, vector<int> transport, string nume) : Statie(strada, numar, sector, transport, nume)
    {
        generareCodStatie();
    }

    StatieUrbana(const StatieUrbana &s1)
    {
        this->strada = s1.strada;
        this->numar = s1.numar;
        this->sector = s1.sector;
        this->transport = s1.transport;
        this->nume = s1.nume;
        this->codStatie = s1.codStatie;
    }

    virtual ~StatieUrbana()
    {
        strada = nume = codStatie = "";
        transport.clear();
        numar = sector = 0;
        codStatie = "";
        numarOrdine--;
    }

    virtual void afisare()
    {
        cout << "\nSTATIE URBANA\n";
        cout << "\nstrada: " << strada;
        cout << "\nnumar: " << numar;
        cout << "\nsector :" << sector;
        cout << "\ncodStatie: " << codStatie;
        cout << "\ncodurile:\n";
        for (int i = 0; i < transport.size(); i++)
            cout << transport[i] << ' ';
        cout << "\nnume: " << nume;
    }

    StatieUrbana &operator=(const StatieUrbana &s1)
    {
        this->strada = s1.strada;
        this->numar = s1.numar;
        this->sector = s1.sector;
        this->transport = s1.transport;
        this->nume = s1.nume;
        this->codStatie = s1.codStatie;
        return *this;
    }

    virtual istream& citire(istream &is)
    {
        cout << "strada: ";
        is >> strada;
        cout << "numar: ";
        is >> numar;
        cout << "sector :";
        is >> sector;
        int nr, cod;
        cout << "numarul de mijloace de transport :";
        cin >> nr;
        cout << "codurile:\n";
        for (int i = 0; i < nr; i++)
        {
            cin >> cod;
            transport.push_back(cod);
        }
        cout << "nume: ";
        is >> nume;
        generareCodStatie();
        return is;
    }

    virtual ostream& afisare(ostream& out)
    {
        out << "\nSTATIE URBANA\n";
        out << "\nstrada: " << strada;
        out << "\nnumar: " << numar;
        out << "\nsector :" << sector;
        out << "\ncodStatie: " << codStatie;
        out << "\ncodurile:\n";
        for (int i = 0; i < transport.size(); i++)
            out << transport[i] << ' ';
        out << "\nnume: " << nume;
        return out;
    }
};

class StatieExtraUrbana : public Statie
{
public:
    void generareCodStatie()
    {
        codStatie += "SE";
        codStatie += "-";
        codStatie += to_string(numarOrdine);
        numarOrdine++;
    }

    StatieExtraUrbana() {}

    StatieExtraUrbana(string strada, int numar, int sector, vector<int> transport, string nume) : Statie(strada, numar, sector, transport, nume)
    {
        generareCodStatie();
    }

    StatieExtraUrbana(const StatieExtraUrbana &s1)
    {
        this->strada = s1.strada;
        this->numar = s1.numar;
        this->sector = s1.sector;
        this->transport = s1.transport;
        this->nume = s1.nume;
        this->codStatie = s1.codStatie;
    }

    virtual ~StatieExtraUrbana()
    {
        strada = nume = codStatie = "";
        transport.clear();
        numar = sector = 0;
        codStatie = "";
        numarOrdine--;
    }

    StatieExtraUrbana &operator=(const StatieExtraUrbana &s1)
    {
        this->strada = s1.strada;
        this->numar = s1.numar;
        this->sector = s1.sector;
        this->transport = s1.transport;
        this->nume = s1.nume;
        this->codStatie = s1.codStatie;
        return *this;
    }

    virtual istream& citire(istream& is){
        cout << "strada: ";
        is >> strada;
        cout << "numar: ";
        is >> numar;
        cout << "sector :";
        is >> sector;
        int nr, cod;
        cout << "numarul de mijloace de transport :";
        cin >> nr;
        cout << "codurile:\n";
        for (int i = 0; i < nr; i++)
        {
            cin >> cod;
            transport.push_back(cod);
        }
        cout << "nume: ";
        is >> nume;
        generareCodStatie();
        return is;
    }

    virtual ostream& afisare(ostream& out)
    {
        out << "\nSTATIE EXTRAURBANA\n";
        out << "\nstrada: " << strada;
        out << "\nnumar: " << numar;
        out << "\nsector :" << sector;
        out << "\ncodStatie: " << codStatie;
        out << "\ncodurile:\n";
        for (int i = 0; i < transport.size(); i++)
            out << transport[i] << ' ';
        out << "\nnume: " << nume;
        return out;
    }

};

class Calatorie
{

    float pret = 2.0;
    Statie *plecare, *sosire;
    bool linieDirecta;

public:
    void calculPret()
    {
        if(dynamic_cast<StatieUrbana*>(plecare) && dynamic_cast<StatieUrbana*>(sosire) && linieDirecta==0)
            pret+=pret*0.15;
        else
            if(dynamic_cast<StatieExtraUrbana*>(plecare) && dynamic_cast<StatieExtraUrbana*>(sosire) && linieDirecta==1)
                pret+=pret*0.2;
            else
                if(dynamic_cast<StatieExtraUrbana*>(plecare) && dynamic_cast<StatieExtraUrbana*>(sosire) && linieDirecta==0)
                    pret+=pret*0.25;
                else
                    if(dynamic_cast<StatieExtraUrbana*>(plecare) && dynamic_cast<StatieUrbana*>(sosire) && linieDirecta==1)
                        pret+=pret*0.30;
                    else
                        if(dynamic_cast<StatieExtraUrbana*>(plecare) && dynamic_cast<StatieUrbana*>(sosire) && linieDirecta==0)
                            pret+=pret*0.40;
    }

    Calatorie() {}

    Calatorie(Statie *plecare, Statie *sosire, bool linieDirecta)
    {
        this->plecare = plecare;
        this->sosire = sosire;
        this->linieDirecta = linieDirecta;
        calculPret();
    }

    Calatorie(const Calatorie &c)
    {
        this->plecare = c.plecare;
        this->sosire = c.sosire;
        this->pret = c.pret;
        this->linieDirecta = c.linieDirecta;
    }

    virtual ~Calatorie()
    {
        pret = 0;
        delete plecare;
        delete sosire;
    }

    int getPret() const
    {
        return pret;
    }

    void setPret()
    {
        calculPret();
    }

    Statie *getPlecare() const
    {
        return plecare;
    }

    void setPlecare(Statie *p)
    {
        plecare = p;
    }

    Statie getSosire() const
    {
        return *sosire;
    }

    void setSosire(Statie *p)
    {
        sosire = p;
    }

    bool isLinieDirecta() const
    {
        return linieDirecta;
    }

    void setLinieDirecta(bool l)
    {
        linieDirecta = l;
    }

    Calatorie &operator=(const Calatorie &c)
    {
        this->plecare = c.plecare;
        this->sosire = c.sosire;
        this->pret = c.pret;
        this->linieDirecta = c.linieDirecta;
        return *this;
    }

    friend istream &operator>>(istream &is, Calatorie &c);
    friend ostream &operator<<(ostream &out, const Calatorie &c);
};

istream &operator>>(istream &is, Calatorie &c)
{
    string tip;
    Statie* s=nullptr;
    while (true)
    {
        try
        {
            cout << "statia de plecare: [SU/SE] ? ";
            is >> tip;
            if (tip != "SU" && tip != "SE")
                throw string("Tip invalid de statie!\n");
            if (tip == "SU") s=new StatieUrbana;
            else s=new StatieExtraUrbana;
            is>>*s;
            c.plecare=s;
        }
        catch (string s)
        {
            cout << s << endl;
        }
        try
        {
            cout << "statia de sosire: [SU/SE] ? ";
            is >> tip;
            if (tip != "SU" && tip != "SE")
                throw string("Tip invalid de statie!\n");
            if (tip == "SU") s=new StatieUrbana;
            else s=new StatieExtraUrbana;
            is>>*s;
            c.sosire=s;
        }
        catch (string s)
        {
            cout << s << endl;
        }
        break;
    }
    cout<<"\nEste linie directa intre cele 2 statii? :"; is>>c.linieDirecta;
    c.calculPret();
    return is;
}

ostream &operator<<(ostream &out, const Calatorie &c)
{
    out << "\n\npret " << c.pret;
    out << "\nstatie plecare:\n\n";
    out<<*c.plecare;
    out << "\nstatie sosire:\n\n";
    out<<*c.sosire;
    if(c.linieDirecta==1)
        out<<"\nLinie directa.\n";
    else out<<"\nNu e linie directa.\n";
    return out;
}

int main()
{
    Calatorie c1;
    cin >> c1;
    cout<<c1;
    return 0;
}