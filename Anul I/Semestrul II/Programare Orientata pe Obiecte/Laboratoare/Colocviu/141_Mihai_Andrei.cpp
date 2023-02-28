/*
    Mihai Andrei-Alexandru
    Rulat cu Visual Studio Code
    Compilator : g++ (GCC) 11.2.0
    Tutore de laborator : Murgoci Alexandra

    examen.oop.fmi@gmail.com
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Bilet{
public:
    Bilet(){}

    virtual ~Bilet(){

    }

    friend istream &operator>>(istream& is,Bilet &b){
        return b.citire(is);
    }

    friend ostream &operator<<(ostream &out,Bilet &b){
        return b.afisare(out);
    }

    virtual istream& citire(istream &is){

    }
    virtual ostream& afisare(ostream &out){
        
    }

};

class BiletSuprafata : virtual public Bilet{
protected:

    const float pret=2.0;

public:

    BiletSuprafata(){}

    virtual ~BiletSuprafata(){

    }

    float getPret() const{
        return pret;
    }

    virtual ostream& afisare(ostream &out){
        out<<"\nBilet suprafata\n";
        out<<"\npretul unui bilet este "<<pret<<endl;
        return out;
    }

};

class BiletMetrou: virtual public Bilet{
protected:

    const float pret=2.5;

public:

    BiletMetrou(){}

    virtual ~BiletMetrou(){

    }

    float getPret() const{
        return pret;
    }

    virtual ostream& afisare(ostream &out){
        out<<"\nBilet metrou\n";
        out<<"\npretul unui bilet este "<<pret<<endl;
        return out;
    }

};

class BiletTranzit: public BiletSuprafata, public BiletMetrou{
protected:

    const float pret=3.0;
    int interval;

public:

    BiletTranzit(){}

    ~BiletTranzit(){

    }

    float getPret() const{
        return pret;
    }

    int getInterval() const{
        return interval;
    }

    void setInterval(int i){
        interval=i;
    }

    virtual ostream& afisare(ostream &out){
        out<<"\nBilet tranzit\n";
        out<<"\nTimp ramas: "<<interval;
        out<<"\npretul unui bilet este "<<pret<<endl;
        return out;
    }

};

class Card{
protected:
    int bilete_validate=0;
public:

    Card(){}

    virtual ~Card(){

    }

    friend istream &operator>>(istream& is,Card &b){
        return b.citire(is);
    }

    friend ostream &operator<<(ostream &out,Card &b){
        return b.afisare(out);
    }

    virtual istream& citire(istream &is){

    }
    virtual ostream& afisare(ostream &out){
        
    }

    virtual void adaugare_bilet(){

    }

    void validare_bilet(){
        bilete_validate++;
    }
};

class CardSuprafata: virtual public Card{
protected:
    vector <BiletSuprafata *> bileteSuprafata;
public:

    CardSuprafata(){}

    virtual ~CardSuprafata(){
        bileteSuprafata.clear();
    }

    vector <BiletSuprafata *> getBileteSuprafata() const{
        return bileteSuprafata;
    }

    void setBileteSUprafata(vector <BiletSuprafata *> bileteSuprafata){
        this->bileteSuprafata=bileteSuprafata;
    }

    virtual istream& citire(istream &is){
        int nr;
        while(true)
            try{
                cout<<"\nDati numarul de bilete din card: "; 
                cin>>nr;
                if(nr<0) throw string("\nInvalid\n");
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        string tip; BiletSuprafata *b;
        for(int i=0;i<nr;){
            try{
                cout<<"Dati tipul biletului. [s/t] \n ";
                getline(cin,tip);
                if(tip=="s")
                    b=new BiletSuprafata;
                else 
                    if(tip=="t")
                        b=new BiletTranzit;
                    else
                        throw string("\nTip invalid\n");
                bileteSuprafata.push_back(b);
                i++;    
            }
            catch(string s){
                cout<<s<<endl;
            }
        }

    }

    virtual ostream& afisare(ostream &out){
        out<<"\nCard suprafata\n";
        out<<"\nBiletele de pe card sunt:";
        for(int i=0;i<bileteSuprafata.size();i++)
            out<<bileteSuprafata[i]<<endl;
        return out;
    }

    virtual void adaugare_bilet(){
        BiletSuprafata *b;
        for(int i=0;i<bileteSuprafata.size()/8;i++){
            b=new BiletSuprafata;
            bileteSuprafata.push_back(b);
        }   
    }
};

class CardMetrou: virtual public Card{
protected:
    vector <BiletMetrou *> bileteMetrou;
public:

    CardMetrou(){}

    virtual ~CardMetrou(){
        bileteMetrou.clear();
    }

    vector <BiletMetrou *> getBileteMetrou() const{
        return bileteMetrou;
    }

    void setbileteMetrou(vector <BiletMetrou *> bileteSuprafata){
        this->bileteMetrou=bileteMetrou;
    }

    virtual istream& citire(istream &is){
        int nr;
        while(true)
            try{
                cout<<"\nDati numarul de bilete din card: "; 
                cin>>nr;
                if(nr<0) throw string("\nInvalid\n");
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        string tip; BiletMetrou *b;
        for(int i=0;i<nr;){
            try{
                cout<<"Dati tipul biletului. [m/t] \n ";
                getline(cin,tip);
                if(tip=="m")
                    b=new BiletMetrou;
                else 
                    if(tip=="t")
                        b=new BiletTranzit;
                    else
                        throw string("\nTip invalid\n");
                bileteMetrou.push_back(b);
                i++;    
            }
            catch(string s){
                cout<<s<<endl;
            }
        }

    }

    virtual ostream& afisare(ostream &out){
        out<<"\nCard suprafata\n";
        out<<"\nBiletele de pe card sunt:";
        for(int i=0;i<bileteMetrou.size();i++)
            out<<bileteMetrou[i]<<endl;
        return out;
    }

    virtual void adaugare_bilet(){
        BiletMetrou *b;
        for(int i=0;i<bileteMetrou.size()/8;i++){
            b=new BiletMetrou;
            bileteMetrou.push_back(b);
        }   
    }

};

class CardTranzit : public CardSuprafata, public CardMetrou{
protected:
    vector <BiletTranzit *> bileteTranzit;
public:
    CardTranzit(){}

    virtual ~CardTranzit(){
        bileteTranzit.clear();
    }

    vector <BiletTranzit *> getBileteTranzit() const{
        return bileteTranzit;
    }

    void setbileteTranzit(vector <BiletTranzit *> bileteSuprafata){
        this->bileteTranzit=bileteTranzit;
    }

    virtual istream& citire(istream &is){
        int nr;
        while(true)
            try{
                cout<<"\nDati numarul de bilete din card: "; 
                cin>>nr;
                if(nr<0) throw string("\nInvalid\n");
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        BiletTranzit *b;
        for(int i=0;i<nr;i++){
            b=new BiletTranzit;
            bileteTranzit.push_back(b);
        }

    }

    virtual ostream& afisare(ostream &out){
        out<<"\nCard suprafata\n";
        out<<"\nBiletele de pe card sunt:";
        for(int i=0;i<bileteTranzit.size();i++)
            out<<bileteTranzit[i]<<endl;
        return out;
    }

    virtual void adaugare_bilet(){
        BiletTranzit *b;
        for(int i=0;i<bileteTranzit.size()/8;i++){
            b=new BiletTranzit;
            bileteTranzit.push_back(b);
        }   
    }

};

class Manager{
private:
    vector <Card*> carduri;
    Manager()=default;
    static Manager* instanta;
public:
    static Manager* getInstanta(){
        if(instanta==nullptr)
            instanta=new Manager();
        return instanta;
    }

    static void deleteInstanta(){
        if(instanta!=nullptr)
            delete instanta;
        instanta=nullptr;
    }

    void cerinta1(){
        //Creare card
        string tip; Card* c;
        while(true)
            try{
                cout<<"\nDati tipul cardului: [S/M/T]"; 
                getline(cin,tip);
                if(tip=="S")
                    c=new CardSuprafata;
                else
                    if(tip=="M")
                        c=new CardMetrou;
                    else    
                        if(tip=="T")
                            c=new CardTranzit;
                        else throw string("\nInvalid\n");
                cin>>*c;
                carduri.push_back(c);
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
    }

    void cerinta3(){
        cout<<"\nDati cardul la care doriti sa adaugati un bilet.\n";
        int nr; cin>>nr;
        carduri[nr]->adaugare_bilet();

    }

    void cerinta6(){
        cout<<"\nDati cardul caruia doriti sa ii stiti detaliile.\n";
        int nr; cin>>nr;
        cout<<carduri[nr];
    }

};

Manager* Manager::instanta=nullptr;

int main(){
    Manager* m=m->getInstanta();
    int cerinta;
    cout<<"\nDati numarul cerintei.\n";
    cin>>cerinta;
    if(cerinta==1)
        m->cerinta1();
    else
        // if(cerinta==2)
        //     //
        // else
            if(cerinta==3)
                m->cerinta3();
            // else
            //     if(cerinta==4)
            //         //
                    // else
                    //     if(cerinta==5)
                    //         //
                    //     else
                            if(cerinta==6)
                                m->cerinta6();


    m->deleteInstanta();
    return 0;
}