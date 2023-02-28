#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Companie{
protected:
    string denumire,cod;
    int an;
    vector <string> destinatii;
public:

    Companie(){}

    Companie(string denumire,string cod,int an,vector <string> destinatii){
        this->denumire=denumire;
        this->cod=cod;
        this->an=an;
        this->destinatii=destinatii;
    }

    Companie(const Companie &c){
        this->denumire=c.denumire;
        this->cod=c.cod;
        this->an=c.an;
        this->destinatii=c.destinatii;
    }

    virtual ~Companie(){
        denumire=cod="";
        an=0;
        destinatii.clear();
    }

    string getDenumire() const{
        return denumire;
    }

    void setDenumire(string d){
        denumire=d;
    }

    string getCod() const{
        return cod;
    }

    void setCod(string c){
        cod=c;
    }

    int getAn() const{
        return an;
    }
    
    void setAn(int a){
        an=a;
    }

    vector <string> getDestinatii() const{
        return destinatii;
    }

    void setDestinatii(vector <string> d){
        destinatii=d;
    }

    Companie &operator=(const Companie &c){
        this->denumire=c.denumire;
        this->cod=c.cod;
        this->an=c.an;
        this->destinatii=c.destinatii;
        return *this;
    }

    friend istream &operator>>(istream &is, Companie &c);
    friend ostream &operator<<(ostream &out,const Companie &c);

    virtual void citire(){
        cout<<"\ndenumire: "; cin>>denumire;
        cout<<"\ncod :" ; cin>>cod;
        cout<<"\nnumarul de destinatii: "; int nr; cin>>nr;
        cout<<"\ndestinatiile:\n";
        for(int i=0;i<nr;i++)
            cin>>destinatii[i];
        cout<<endl;
    }

};

istream &operator>>(istream &is, Companie &c){
    cout<<"\ndenumire: "; is>>c.denumire;
    cout<<"\ncod :" ; is>>c.cod;
    cout<<"\nnumarul de destinatii: "; int nr; is>>nr;
    cout<<"\ndestinatiile:\n";
    for(int i=0;i<nr;i++)
        is>>c.destinatii[i];
    cout<<endl;
    return is;
}

ostream &operator<<(ostream &out,const Companie &c){
    out<<"\ndenumire: "<<c.denumire;
    out<<"\ncod :"<<c.cod;
    out<<"\ndestinatiile:\n";
    for(int i=0;i<c.destinatii.size();i++)
        out<<c.destinatii[i]<<' ';
    out<<endl;
    return out;
}

class CompanieLowCost : public Companie{
protected:
    int costSuplimentar;
    int greutateBagaj;

public:
    CompanieLowCost(){}

    CompanieLowCost(string denumire,string cod,int an,vector <string> destinatii,int costSuplimentar,int greutateBagaj):
        Companie(denumire,cod,an,destinatii){
            this->costSuplimentar=costSuplimentar;
            this->greutateBagaj=greutateBagaj;
        }

    CompanieLowCost (const CompanieLowCost &c){
        this->denumire=c.denumire;
        this->cod=c.cod;
        this->an=c.an;
        this->destinatii=c.destinatii;
        this->costSuplimentar=c.costSuplimentar;
        this->greutateBagaj=c.greutateBagaj;
    }

    virtual ~CompanieLowCost(){
        denumire=cod="";
        an=costSuplimentar=greutateBagaj=0;
        destinatii.clear();
    }

    int getCostSuplimentar() const{
        return costSuplimentar;
    }

    void setCostSuplimentar(int c){
        costSuplimentar=c;
    }

    int getGreutateBagaj() const{
        return greutateBagaj;
    }

    void setGreutateBagaj(int g){
        greutateBagaj=g;
    }

    CompanieLowCost &operator=(const CompanieLowCost &c){
        this->denumire=c.denumire;
        this->cod=c.cod;
        this->an=c.an;
        this->destinatii=c.destinatii;
        this->costSuplimentar=c.costSuplimentar;
        this->greutateBagaj=c.greutateBagaj;
        return *this;
    }

    friend istream &operator>>(istream &is, CompanieLowCost &c);
    friend ostream &operator<<(ostream &out,const CompanieLowCost &c);

    virtual void citire(){
        cout<<"\ndenumire: "; cin>>denumire;
        cout<<"\ncod :" ; cin>>cod;
        cout<<"\nnumarul de destinatii: "; int nr; cin>>nr;
        cout<<"\ndestinatiile:\n";
        for(int i=0;i<nr;i++)
            cin>>destinatii[i];
        cout<<endl;
        cout<<"\ncostSuplimentar: "; cin>>costSuplimentar;
        cout<<"\ngreutateBagaj: "; cin>>greutateBagaj;
    }
};

istream &operator>>(istream &is, CompanieLowCost &c){
    cout<<"\ndenumire: "; is>>c.denumire;
    cout<<"\ncod :" ; is>>c.cod;
    cout<<"\nnumarul de destinatii: "; int nr; is>>nr;
    cout<<"\ndestinatiile:\n";
    for(int i=0;i<nr;i++)
        is>>c.destinatii[i];
    cout<<endl;
    cout<<"\ncostSuplimentar: "; is>>c.costSuplimentar;
    cout<<"\ngreutateBagaj: "; is>>c.greutateBagaj;
    return is;
}

ostream &operator<<(ostream &out,const CompanieLowCost &c){
    out<<"\ndenumire: "<<c.denumire;
    out<<"\ncod :"<<c.cod;
    out<<"\ndestinatiile:\n";
    for(int i=0;i<c.destinatii.size();i++)
        out<<c.destinatii[i]<<' ';
    out<<endl;
    out<<"\ncostSuplimentar: "<<c.costSuplimentar;
    out<<"\ngreutateBagaj: "<<c.greutateBagaj;
    return out;
}

class CompanieLinie : public Companie{
protected:
    
public:

    CompanieLinie(){}

    CompanieLinie(string denumire,string cod,int an,vector <string> destinatii):
         Companie(denumire,cod,an,destinatii){}
    
    CompanieLinie(const CompanieLinie &c){
        this->denumire=c.denumire;
        this->cod=c.cod;
        this->an=c.an;
        this->destinatii=c.destinatii;
    }

    virtual ~CompanieLinie(){
        denumire=cod="";
        an=0;
        destinatii.clear();
    }

    CompanieLinie &operator=(const CompanieLinie &c){
        this->denumire=c.denumire;
        this->cod=c.cod;
        this->an=c.an;
        this->destinatii=c.destinatii;
        return *this;
    }

    friend istream &operator>>(istream &is, CompanieLinie &c);
    friend ostream &operator<<(ostream &out,const CompanieLinie &c);

    virtual void citire(){
        cout<<"\ndenumire: "; cin>>denumire;
        cout<<"\ncod :" ; cin>>cod;
        cout<<"\nnumarul de destinatii: "; int nr; cin>>nr;
        cout<<"\ndestinatiile:\n";
        for(int i=0;i<nr;i++)
            cin>>destinatii[i];
        cout<<endl;
    }

};

istream &operator>>(istream &is, CompanieLinie &c){
    cout<<"\ndenumire: "; is>>c.denumire;
    cout<<"\ncod :" ; is>>c.cod;
    cout<<"\nnumarul de destinatii: "; int nr; is>>nr;
    cout<<"\ndestinatiile:\n";
    for(int i=0;i<nr;i++)
        is>>c.destinatii[i];
    cout<<endl;
    return is;
}

ostream &operator<<(ostream &out,const CompanieLinie &c){
    out<<"\ndenumire: "<<c.denumire;
    out<<"\ncod :"<<c.cod;
    out<<"\ndestinatiile:\n";
    for(int i=0;i<c.destinatii.size();i++)
        out<<c.destinatii[i]<<' ';
    out<<endl;
}

class Zbor{
protected:
    static int numar;
    string destinatie;
    int an,luna,zi,ora,minut;
    int durata;
    const string plecare = "Bucuresti";
};

int Zbor::numar=1;

int main(){
    return 0;
}