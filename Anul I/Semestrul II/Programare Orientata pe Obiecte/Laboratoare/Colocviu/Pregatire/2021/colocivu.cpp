#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Malware{
protected:
    float ratingImpact=0.0;
    vector <int> dataInfectare;
    string nume;
    string metodaInfectare="unknown";
    vector <string> registriiInfectati;
public:
    Malware(){}

    Malware(float ratingImpact, vector <int> dataInfectare,string nume,string metodaInfectare,vector <string> registriiInfectati){
        this->ratingImpact=ratingImpact;
        this->dataInfectare=dataInfectare;
        this->nume=nume;
        this->metodaInfectare=metodaInfectare;
        this->registriiInfectati=registriiInfectati;
    }

    Malware(const Malware &m){
        this->ratingImpact=m.ratingImpact;
        this->dataInfectare=m.dataInfectare;
        this->nume=m.nume;
        this->metodaInfectare=m.metodaInfectare;
        this->registriiInfectati=m.registriiInfectati;
    }

    virtual ~Malware(){
        ratingImpact=0.0;
        dataInfectare.clear();
        nume=metodaInfectare="";
        registriiInfectati.clear();
    }

    float getRatingImpact() const{
        return ratingImpact;
    }

    vector<int> getDataInfectare() const{
        return dataInfectare;
    }

    string getNume() const{
        return nume;
    }

    string getMetodaInfectare() const{
        return metodaInfectare;
    }

    vector <string> getRegistriiInfectati() const{
        return registriiInfectati;
    }

    void setRatingImpact(float ratingImpact){
        this->ratingImpact=ratingImpact;
    }

    void setDataInfectare(vector <int> dataInfectare){
        this->dataInfectare=dataInfectare;
    }

    void setNume(string nume){
        this->nume=nume;
    }

    void setMetodaInfectare(string metodaInfectare){
        this->metodaInfectare=metodaInfectare;
    }

    void setRegistriiInfectati(vector <string> registriiInfectati){
        this->registriiInfectati=registriiInfectati;
    }

    Malware &operator =(const Malware &m){
        this->ratingImpact=m.ratingImpact;
        this->dataInfectare=m.dataInfectare;
        this->nume=m.nume;
        this->metodaInfectare=m.metodaInfectare;
        this->registriiInfectati=m.registriiInfectati;
        return *this;
    }

    friend istream &operator>>(istream &is, Malware &m){
        return m.citire(is);
    }
    friend ostream &operator<<(ostream &out,Malware &m){
        return m.afisare(out);
    }

    virtual void calculRatingImpact()=0;

    virtual istream& citire(istream &is)=0;

    virtual ostream& afisare(ostream &out)=0;
};

// istream &operator>>(istream &is, Malware &m){
//     cout<<"\ndataInfectare:\n";
//     int x;
//     while(true){
//         try{
//             cout<<"\nzi:"; is>>x;
//             if(x<1 || x>31)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }

//     while(true){
//         try{
//             cout<<"\nluna:"; cin>>x;
//             if(x<1 || x>12)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }
//     while(true){
//         try{
//             cout<<"\nan:"; is>>x;
//             if(x<1)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }
//     cout<<"\nnume: "; is>>m.nume;
//     cout<<"\nmetodaInfectare: "; is>>m.metodaInfectare;
//     cout<<"\nnumarul de registrii infectati: "; int nr; is>>nr;
//     cout<<"\nregistrii:\n";
//     string aux;
//     for(int i=0;i<=nr;i++){
//         getline(cin,aux);
//         m.registriiInfectati.push_back(aux);
//     }
//     return is;
// }

// ostream &operator<<(ostream &out, const Malware &m){
//     out<<"\n\nratingImpact: "<<m.ratingImpact;
//     out<<"\ndataInfectare:\n";
//     out<<"\nzi:"<<m.dataInfectare[0];
//     out<<"\nluna:"<<m.dataInfectare[1];
//     out<<"\nan:"<<m.dataInfectare[2];
//     out<<"\nnume: "<<m.nume;
//     out<<"\nmetodaInfectare: "<<m.metodaInfectare;
//     out<<"\nregistrii:\n";
//     for(int i=0;i<m.registriiInfectati.size();i++)
//         out<<m.registriiInfectati[i]<<' ';
//     return out;
// }

class Rootkit : virtual public Malware{
protected:
    vector <string> listaImporturi;
    vector <string> listaStringuri;

public:

    Rootkit(){}

    Rootkit(float ratingImpact, vector <int> dataInfectare,string nume,string metodaInfectare,vector <string> registriiInfectati,vector <string> listaImporturi,vector <string> listaStringuri):
        Malware(ratingImpact,dataInfectare,nume,metodaInfectare,registriiInfectati){
            this->listaImporturi=listaImporturi;
            this->listaStringuri=listaStringuri;
        }

    Rootkit(const Rootkit& m){
        this->ratingImpact=m.ratingImpact;
        this->dataInfectare=m.dataInfectare;
        this->nume=m.nume;
        this->metodaInfectare=m.metodaInfectare;
        this->registriiInfectati=m.registriiInfectati;
        this->listaImporturi=m.listaImporturi;
        this->listaStringuri=m.listaStringuri;
    }

    virtual ~Rootkit(){
        ratingImpact=0.0;
        dataInfectare.clear();
        nume=metodaInfectare="";
        registriiInfectati.clear();
        listaImporturi.clear();
        listaStringuri.clear();
    }

    vector <string> getListaImporturi() const{
        return listaImporturi;
    }

    void setListaImporturi(vector <string> listaImporturi){
        this->listaImporturi=listaImporturi;
    }

    vector <string> getListaStringuri() const{
        return listaStringuri;
    }

    void setListaStringuri(vector <string> listaStringuri){
        this->listaStringuri=listaStringuri;
    }

    Rootkit &operator=(const Rootkit& m){
        this->ratingImpact=m.ratingImpact;
        this->dataInfectare=m.dataInfectare;
        this->nume=m.nume;
        this->metodaInfectare=m.metodaInfectare;
        this->registriiInfectati=m.registriiInfectati;
        this->listaImporturi=m.listaImporturi;
        this->listaStringuri=m.listaStringuri;
        return *this;
    }

    // friend istream &operator>>(istream &is, Rootkit &m);
    // friend ostream &operator<<(ostream &out, const Rootkit &m);

    virtual void calculRatingImpact(){
        for(int i=0;i<registriiInfectati.size();i++)
            if(registriiInfectati[i]=="HKLM-run" || registriiInfectati[i]=="HKCU-run")
                ratingImpact+=20;
        for(int i=0;i<listaImporturi.size();i++)
            if(listaImporturi[i]=="System Service Descriptor Table" || listaImporturi[i]=="SSDT" || listaImporturi[i]=="NtCreateFile")
                ratingImpact+=100;
        for(int i=0;i<listaStringuri.size();i++)
            if(listaStringuri[i]=="ntoskrnl.exe")
                ratingImpact*=2;
    }

    virtual istream& citire(istream &is){
        cout<<"\ndataInfectare:\n";
        int x;
        while(true){
            try{
                cout<<"\nzi:"; is>>x;
                if(x<1 || x>31)
                    throw string("\nInvalid!\n");
                dataInfectare.push_back(x);
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        }

        while(true){
            try{
                cout<<"\nluna:"; cin>>x;
                if(x<1 || x>12)
                    throw string("\nInvalid!\n");
                dataInfectare.push_back(x);
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        }
        while(true){
            try{
                cout<<"\nan:"; is>>x;
                if(x<1)
                    throw string("\nInvalid!\n");
                dataInfectare.push_back(x);
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        }
        cout<<"\nnume: "; is>>nume;
        cout<<"\nmetodaInfectare: "; is>>metodaInfectare;
        cout<<"\nnumarul de registrii infectati: "; int nr; is>>nr;
        cout<<"\nregistrii:\n";
        string aux;
        for(int i=0;i<=nr;i++){
            getline(cin,aux);
            registriiInfectati.push_back(aux);
        }
        cout<<"\nnumar importuri:"; is>>nr;
        cout<<"\nimporturi:\n";
        for(int i=0;i<=nr;i++){
            getline(cin,aux);
            listaImporturi.push_back(aux);
        }
        cout<<"\nnumar stringuri:"; is>>nr;
        cout<<"\nstringuri:\n";
        for(int i=0;i<=nr;i++){
            getline(cin,aux);
            listaStringuri.push_back(aux);
        }
        return is;
    }

    virtual ostream& afisare(ostream &out){
        out<<"\n\nratingImpact: "<<ratingImpact;
        out<<"\ndataInfectare:\n";
        out<<"\nzi:"<<dataInfectare[0];
        out<<"\nluna:"<<dataInfectare[1];
        out<<"\nan:"<<dataInfectare[2];
        out<<"\nnume: "<<nume;
        out<<"\nmetodaInfectare: "<<metodaInfectare;
        out<<"\nregistrii:\n";
        for(int i=0;i<registriiInfectati.size();i++)
            out<<registriiInfectati[i]<<' ';
        out<<"\nimporturi:\n";
        for(int i=0;i<listaImporturi.size();i++)
            out<<listaImporturi[i]<<' ';
        out<<"\nstringuri:\n";
        for(int i=0;i<listaStringuri.size();i++)
            out<<listaStringuri[i]<<' ';
        return out;
    }

};

// istream &operator>>(istream &is, Rootkit &m){
//     cout<<"\ndataInfectare:\n";
//     int x;
//     while(true){
//         try{
//             cout<<"\nzi:"; is>>x;
//             if(x<1 || x>31)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }

//     while(true){
//         try{
//             cout<<"\nluna:"; cin>>x;
//             if(x<1 || x>12)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }
//     while(true){
//         try{
//             cout<<"\nan:"; is>>x;
//             if(x<1)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }
//     cout<<"\nnume: "; is>>m.nume;
//     cout<<"\nmetodaInfectare: "; is>>m.metodaInfectare;
//     cout<<"\nnumarul de registrii infectati: "; int nr; is>>nr;
//     cout<<"\nregistrii:\n";
//     string aux;
//     for(int i=0;i<=nr;i++){
//         getline(cin,aux);
//         m.registriiInfectati.push_back(aux);
//     }
//     cout<<"\nnumar importuri:"; is>>nr;
//     cout<<"\nimporturi:\n";
//     for(int i=0;i<=nr;i++){
//         getline(cin,aux);
//         m.listaImporturi.push_back(aux);
//     }
//     cout<<"\nnumar stringuri:"; is>>nr;
//     cout<<"\nstringuri:\n";
//     for(int i=0;i<=nr;i++){
//         getline(cin,aux);
//         m.listaStringuri.push_back(aux);
//     }
//     return is;
// }

// ostream &operator<<(ostream &out, const Rootkit &m){
//     out<<"\n\nratingImpact: "<<m.ratingImpact;
//     out<<"\ndataInfectare:\n";
//     out<<"\nzi:"<<m.dataInfectare[0];
//     out<<"\nluna:"<<m.dataInfectare[1];
//     out<<"\nan:"<<m.dataInfectare[2];
//     out<<"\nnume: "<<m.nume;
//     out<<"\nmetodaInfectare: "<<m.metodaInfectare;
//     out<<"\nregistrii:\n";
//     for(int i=0;i<m.registriiInfectati.size();i++)
//         out<<m.registriiInfectati[i]<<' ';
//     out<<"\nimporturi:\n";
//     for(int i=0;i<m.listaImporturi.size();i++)
//         out<<m.listaImporturi[i]<<' ';
//     out<<"\nstringuri:\n";
//     for(int i=0;i<m.listaStringuri.size();i++)
//         out<<m.listaStringuri[i]<<' ';
//     return out;
// }

class Keylogger : virtual public Malware{
protected:
    vector <string> listaFunctii;
    vector <string> listaTaste;
public:
    Keylogger(){}

    Keylogger(float ratingImpact, vector <int> dataInfectare,string nume,string metodaInfectare,vector <string> registriiInfectati,vector <string> listaFunctii,vector <string> listaTaste):
        Malware(ratingImpact,dataInfectare,nume,metodaInfectare,registriiInfectati){
        this->listaFunctii=listaFunctii;
        this->listaTaste=listaTaste;
    }

    Keylogger(const Keylogger &m){
        this->ratingImpact=m.ratingImpact;
        this->dataInfectare=m.dataInfectare;
        this->nume=m.nume;
        this->metodaInfectare=m.metodaInfectare;
        this->registriiInfectati=m.registriiInfectati;
        this->listaFunctii=listaFunctii;
        this->listaTaste=listaTaste;
    }

    virtual ~Keylogger(){
        ratingImpact=0.0;
        dataInfectare.clear();
        nume=metodaInfectare="";
        registriiInfectati.clear();
        listaFunctii.clear();
        listaTaste.clear();
    }

    vector <string> getListaFunctii() const{
        return listaFunctii;
    }

    void setListaFunctii(vector <string> listaFunctii){
        this->listaFunctii=listaFunctii;
    }

    vector <string> getListaTaste() const{
        return listaTaste;
    }

    void setListaTaste(vector <string> listaTaste){
        this->listaTaste=listaTaste;
    }

    Keylogger &operator=(const Keylogger &m){
        this->ratingImpact=m.ratingImpact;
        this->dataInfectare=m.dataInfectare;
        this->nume=m.nume;
        this->metodaInfectare=m.metodaInfectare;
        this->registriiInfectati=m.registriiInfectati;
        this->listaFunctii=listaFunctii;
        this->listaTaste=listaTaste;
        return *this;
    }

    // friend istream &operator>>(istream &is, Keylogger &m);
    // friend ostream &operator<<(ostream &out, const Keylogger &m);

    virtual void calculRatingImpact(){
        for(int i=0;i<registriiInfectati.size();i++)
            if(registriiInfectati[i]=="HKLM-run" || registriiInfectati[i]=="HKCU-run")
                ratingImpact+=20;
        for(int i=0;i<listaTaste.size();i++)
            if(listaTaste[i]=="[Up]" || listaTaste[i]=="[Num Lock]" || listaTaste[i]=="[Down]" || listaTaste[i]=="[Right]" || listaTaste[i]=="[UP]"  || listaTaste[i]=="[Left]" || listaTaste[i]=="[PageDown]")
                ratingImpact+=10;
        for(int i=0;i<listaFunctii.size();i++)
            if(listaFunctii[i]=="CreateFileW" || listaFunctii[i]=="OpenProcess" || listaFunctii[i]=="ReadFile" || listaFunctii[i]=="WriteFile" || listaFunctii[i]=="RegisterHotKey" || listaFunctii[i]=="SetWindowsHookEx")
                ratingImpact+=30;
    }

    virtual istream& citire(istream &is){
        cout<<"\ndataInfectare:\n";
        int x;
        while(true){
            try{
                cout<<"\nzi:"; is>>x;
                if(x<1 || x>31)
                    throw string("\nInvalid!\n");
                dataInfectare.push_back(x);
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        }

        while(true){
            try{
                cout<<"\nluna:"; cin>>x;
                if(x<1 || x>12)
                    throw string("\nInvalid!\n");
                dataInfectare.push_back(x);
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        }
        while(true){
            try{
                cout<<"\nan:"; is>>x;
                if(x<1)
                    throw string("\nInvalid!\n");
                dataInfectare.push_back(x);
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        }
        cout<<"\nnume: "; is>>nume;
        cout<<"\nmetodaInfectare: "; is>>metodaInfectare;
        cout<<"\nnumarul de registrii infectati: "; int nr; is>>nr;
        cout<<"\nregistrii:\n";
        string aux;
        for(int i=0;i<=nr;i++){
            getline(cin,aux);
            registriiInfectati.push_back(aux);
        }
        cout<<"\nnumar functii:"; is>>nr;
        cout<<"\nfunctii:\n";
        for(int i=0;i<=nr;i++){
            getline(cin,aux);
            listaFunctii.push_back(aux);
        }
        cout<<"\nnumar taste:"; is>>nr;
        cout<<"\ntaste:\n";
        for(int i=0;i<=nr;i++){
            getline(cin,aux);
            listaTaste.push_back(aux);
        }
        return is;
    }

    virtual ostream& afisare(ostream &out){
        out<<"\n\nratingImpact: "<<ratingImpact;
        out<<"\ndataInfectare:\n";
        out<<"\nzi:"<<dataInfectare[0];
        out<<"\nluna:"<<dataInfectare[1];
        cout<<"\nan:"<<dataInfectare[2];
        out<<"\nnume: "<<nume;
        out<<"\nmetodaInfectare: "<<metodaInfectare;
        out<<"\nregistrii:\n";
        for(int i=0;i<registriiInfectati.size();i++)
            out<<registriiInfectati[i]<<' ';
        out<<"\nfunctii:\n";
        for(int i=0;i<listaFunctii.size();i++)
            out<<listaFunctii[i]<<' ';
        out<<"\ntaste:\n";
        for(int i=0;i<listaTaste.size();i++)
            out<<listaTaste[i]<<' ';
        return out;
    }
};

// istream &operator>>(istream &is, Keylogger &m){
//     cout<<"\ndataInfectare:\n";
//     int x;
//     while(true){
//         try{
//             cout<<"\nzi:"; is>>x;
//             if(x<1 || x>31)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }

//     while(true){
//         try{
//             cout<<"\nluna:"; cin>>x;
//             if(x<1 || x>12)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }
//     while(true){
//         try{
//             cout<<"\nan:"; is>>x;
//             if(x<1)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }
//     cout<<"\nnume: "; is>>m.nume;
//     cout<<"\nmetodaInfectare: "; is>>m.metodaInfectare;
//     cout<<"\nnumarul de registrii infectati: "; int nr; is>>nr;
//     cout<<"\nregistrii:\n";
//     string aux;
//     for(int i=0;i<=nr;i++){
//         getline(cin,aux);
//         m.registriiInfectati.push_back(aux);
//     }
//     cout<<"\nnumar functii:"; is>>nr;
//     cout<<"\nfunctii:\n";
//     for(int i=0;i<=nr;i++){
//         getline(cin,aux);
//         m.listaFunctii.push_back(aux);
//     }
//     cout<<"\nnumar taste:"; is>>nr;
//     cout<<"\ntaste:\n";
//     for(int i=0;i<=nr;i++){
//         getline(cin,aux);
//         m.listaTaste.push_back(aux);
//     }
//     return is;
// }

// ostream &operator<<(ostream &out, const Keylogger &m){
//     out<<"\n\nratingImpact: "<<m.ratingImpact;
//     out<<"\ndataInfectare:\n";
//     out<<"\nzi:"<<m.dataInfectare[0];
//     out<<"\nluna:"<<m.dataInfectare[1];
//     out<<"\nan:"<<m.dataInfectare[2];
//     out<<"\nnume: "<<m.nume;
//     out<<"\nmetodaInfectare: "<<m.metodaInfectare;
//     out<<"\nregistrii:\n";
//     for(int i=0;i<m.registriiInfectati.size();i++)
//         out<<m.registriiInfectati[i]<<' ';
//     out<<"\nfunctii:\n";
//     for(int i=0;i<m.listaFunctii.size();i++)
//         out<<m.listaFunctii[i]<<' ';
//     out<<"\ntaste:\n";
//     for(int i=0;i<m.listaTaste.size();i++)
//         out<<m.listaTaste[i]<<' ';
//     return out;
// }

class KernelKeylogger : public Rootkit, public Keylogger{
protected:
    bool ascundeFisiere,ascundeRegistrii;
public:
    KernelKeylogger(){}

    KernelKeylogger(float ratingImpact, vector <int> dataInfectare,string nume,string metodaInfectare,vector <string> registriiInfectati,vector <string> listaFunctii,vector <string> listaTaste,vector <string> listaImporturi,vector <string> listaStringuri):
        Rootkit(ratingImpact,dataInfectare,nume,metodaInfectare,registriiInfectati,listaImporturi,listaStringuri)
        ,Keylogger(ratingImpact,dataInfectare,nume,metodaInfectare,registriiInfectati,listaFunctii,listaTaste){
            this->ascundeFisiere=ascundeFisiere;
            this->ascundeRegistrii=ascundeRegistrii;
        }
    KernelKeylogger(const KernelKeylogger &m){
        this->ratingImpact=m.ratingImpact;
        this->dataInfectare=m.dataInfectare;
        this->nume=m.nume;
        this->metodaInfectare=m.metodaInfectare;
        this->registriiInfectati=m.registriiInfectati;
        this->listaImporturi=m.listaImporturi;
        this->listaStringuri=m.listaStringuri;
        this->listaFunctii=m.listaFunctii;
        this->listaTaste=m.listaTaste;
        this->ascundeFisiere=m.ascundeFisiere;
        this->ascundeRegistrii=m.ascundeRegistrii;
    }

    virtual ~KernelKeylogger(){
        ratingImpact=0.0;
        dataInfectare.clear();
        nume=metodaInfectare="";
        registriiInfectati.clear();
        listaFunctii.clear();
        listaTaste.clear();
        ascundeFisiere=false;
        ascundeRegistrii=false;
    }

    bool isAscundeFisiere() const{
        return ascundeFisiere;
    }

    bool isAscundeRegistrii() const{
        return ascundeRegistrii;
    }

    void setAscundeFisiere(bool a){
        ascundeFisiere=a;
    }

    void setAscundeRegistrii(bool a){
        ascundeRegistrii=a;
    }

    KernelKeylogger &operator=(const KernelKeylogger &m){
        this->ratingImpact=m.ratingImpact;
        this->dataInfectare=m.dataInfectare;
        this->nume=m.nume;
        this->metodaInfectare=m.metodaInfectare;
        this->registriiInfectati=m.registriiInfectati;
        this->listaImporturi=m.listaImporturi;
        this->listaStringuri=m.listaStringuri;
        this->listaFunctii=m.listaFunctii;
        this->listaTaste=m.listaTaste;
        this->ascundeFisiere=m.ascundeFisiere;
        this->ascundeRegistrii=m.ascundeRegistrii;
        return *this;
    }

    // friend istream &operator>>(istream &is, KernelKeylogger &m);
    // friend ostream &operator<<(ostream &out, const KernelKeylogger &m);

    virtual void calculRatingImpact(){
        for(int i=0;i<registriiInfectati.size();i++)
            if(registriiInfectati[i]=="HKLM-run" || registriiInfectati[i]=="HKCU-run")
                ratingImpact+=20;
        for(int i=0;i<listaImporturi.size();i++)
            if(listaImporturi[i]=="System Service Descriptor Table" || listaImporturi[i]=="SSDT" || listaImporturi[i]=="NtCreateFile")
                ratingImpact+=100;
        for(int i=0;i<listaStringuri.size();i++)
            if(listaStringuri[i]=="ntoskrnl.exe")
                ratingImpact*=2;
        for(int i=0;i<listaTaste.size();i++)
            if(listaTaste[i]=="[Up]" || listaTaste[i]=="[Num Lock]" || listaTaste[i]=="[Down]" || listaTaste[i]=="[Right]" || listaTaste[i]=="[UP]"  || listaTaste[i]=="[Left]" || listaTaste[i]=="[PageDown]")
                ratingImpact+=10;
        for(int i=0;i<listaFunctii.size();i++)
            if(listaFunctii[i]=="CreateFileW" || listaFunctii[i]=="OpenProcess" || listaFunctii[i]=="ReadFile" || listaFunctii[i]=="WriteFile" || listaFunctii[i]=="RegisterHotKey" || listaFunctii[i]=="SetWindowsHookEx")
                ratingImpact+=30;
        if(ascundeFisiere==1)
            ratingImpact+=20;
        if(ascundeRegistrii==1)
            ratingImpact+=30;
    }

    virtual istream& citire(istream &is){
        cout<<"\ndataInfectare:\n";
        int x;
        while(true){
            try{
                cout<<"\nzi:"; is>>x;
                if(x<1 || x>31)
                    throw string("\nInvalid!\n");
                dataInfectare.push_back(x);
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        }

        while(true){
            try{
                cout<<"\nluna:"; cin>>x;
                if(x<1 || x>12)
                    throw string("\nInvalid!\n");
                dataInfectare.push_back(x);
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        }
        while(true){
            try{
                cout<<"\nan:"; is>>x;
                if(x<1)
                    throw string("\nInvalid!\n");
                dataInfectare.push_back(x);
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        }
        cout<<"\nnume: "; is>>nume;
        cout<<"\nmetodaInfectare: "; is>>metodaInfectare;
        cout<<"\nnumarul de registrii infectati: "; int nr; is>>nr;
        cout<<"\nregistrii:\n";
        string aux;
        for(int i=0;i<=nr;i++){
            getline(cin,aux);
            registriiInfectati.push_back(aux);
        }
        cout<<"\nimporturi:\n";
        for(int i=0;i<=nr;i++){
            getline(cin,aux);
            listaImporturi.push_back(aux);
        }
        cout<<"\nnumar stringuri:"; is>>nr;
        cout<<"\nstringuri:\n";
        for(int i=0;i<=nr;i++){
            getline(cin,aux);
            listaStringuri.push_back(aux);
        }
        cout<<"\nnumar functii:"; is>>nr;
        cout<<"\nfunctii:\n";
        for(int i=0;i<=nr;i++){
            getline(cin,aux);
            listaFunctii.push_back(aux);
        }
        cout<<"\nnumar taste:"; is>>nr;
        cout<<"\ntaste:\n";
        for(int i=0;i<=nr;i++){
            getline(cin,aux);
            listaTaste.push_back(aux);
        }
        cout<<"\nascundeFisiere? : "; is>>ascundeFisiere;
        cout<<"\nascundeRegistrii : "; is>>ascundeRegistrii;
        return is;
    }

    virtual ostream& afisare(ostream &out){
        out<<"\n\nratingImpact: "<<ratingImpact;
        out<<"\ndataInfectare:\n";
        out<<"\nzi:"<<dataInfectare[0];
        out<<"\nluna:"<<dataInfectare[1];
        out<<"\nan:"<<dataInfectare[2];
        out<<"\nnume: "<<nume;
        out<<"\nmetodaInfectare: "<<metodaInfectare;
        out<<"\nregistrii:\n";
        for(int i=0;i<registriiInfectati.size();i++)
            out<<registriiInfectati[i]<<' ';
        out<<"\nimporturi:\n";
        for(int i=0;i<listaImporturi.size();i++)
            out<<listaImporturi[i]<<' ';
        out<<"\nstringuri:\n";
        for(int i=0;i<listaStringuri.size();i++)
            out<<listaStringuri[i]<<' ';
        out<<"\nfunctii:\n";
        for(int i=0;i<listaFunctii.size();i++)
            out<<listaFunctii[i]<<' ';
        out<<"\ntaste:\n";
        for(int i=0;i<listaTaste.size();i++)
            out<<listaTaste[i]<<' ';
        if(ascundeFisiere==1)
            out<<"\nascundeFisiere\n";
        else out<<"\nnu ascundeFisiere\n";
        if(ascundeRegistrii==1)
            out<<"\nascundeRegistrii\n";
        else out<<"\nnu ascundeRegistrii\n";
        return out;
    }

};

// istream &operator>>(istream &is, KernelKeylogger &m){
//     cout<<"\ndataInfectare:\n";
//     int x;
//     while(true){
//         try{
//             cout<<"\nzi:"; is>>x;
//             if(x<1 || x>31)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }

//     while(true){
//         try{
//             cout<<"\nluna:"; cin>>x;
//             if(x<1 || x>12)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }
//     while(true){
//         try{
//             cout<<"\nan:"; is>>x;
//             if(x<1)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }
//     cout<<"\nnume: "; is>>m.nume;
//     cout<<"\nmetodaInfectare: "; is>>m.metodaInfectare;
//     cout<<"\nnumarul de registrii infectati: "; int nr; is>>nr;
//     cout<<"\nregistrii:\n";
//     string aux;
//     for(int i=0;i<=nr;i++){
//         getline(cin,aux);
//         m.registriiInfectati.push_back(aux);
//     }
//     cout<<"\nimporturi:\n";
//     for(int i=0;i<=nr;i++){
//         getline(cin,aux);
//         m.listaImporturi.push_back(aux);
//     }
//     cout<<"\nnumar stringuri:"; is>>nr;
//     cout<<"\nstringuri:\n";
//     for(int i=0;i<=nr;i++){
//         getline(cin,aux);
//         m.listaStringuri.push_back(aux);
//     }
//     cout<<"\nnumar functii:"; is>>nr;
//     cout<<"\nfunctii:\n";
//     for(int i=0;i<=nr;i++){
//         getline(cin,aux);
//         m.listaFunctii.push_back(aux);
//     }
//     cout<<"\nnumar taste:"; is>>nr;
//     cout<<"\ntaste:\n";
//     for(int i=0;i<=nr;i++){
//         getline(cin,aux);
//         m.listaTaste.push_back(aux);
//     }
//     cout<<"\nascundeFisiere? : "; is>>m.ascundeFisiere;
//     cout<<"\nascundeRegistrii : "; is>>m.ascundeRegistrii;
//     return is;
// }

// ostream &operator<<(ostream &out, const KernelKeylogger &m){
//     out<<"\n\nratingImpact: "<<m.ratingImpact;
//     out<<"\ndataInfectare:\n";
//     out<<"\nzi:"<<m.dataInfectare[0];
//     out<<"\nluna:"<<m.dataInfectare[1];
//     out<<"\nan:"<<m.dataInfectare[2];
//     out<<"\nnume: "<<m.nume;
//     out<<"\nmetodaInfectare: "<<m.metodaInfectare;
//     out<<"\nregistrii:\n";
//     for(int i=0;i<m.registriiInfectati.size();i++)
//         out<<m.registriiInfectati[i]<<' ';
//     out<<"\nimporturi:\n";
//     for(int i=0;i<m.listaImporturi.size();i++)
//         out<<m.listaImporturi[i]<<' ';
//     out<<"\nstringuri:\n";
//     for(int i=0;i<m.listaStringuri.size();i++)
//         out<<m.listaStringuri[i]<<' ';
//     out<<"\nfunctii:\n";
//     for(int i=0;i<m.listaFunctii.size();i++)
//         out<<m.listaFunctii[i]<<' ';
//     out<<"\ntaste:\n";
//     for(int i=0;i<m.listaTaste.size();i++)
//         out<<m.listaTaste[i]<<' ';
//     if(m.ascundeFisiere==1)
//         out<<"\nascundeFisiere\n";
//     else out<<"\nnu ascundeFisiere\n";
//     if(m.ascundeRegistrii==1)
//         out<<"\nascundeRegistrii\n";
//     else out<<"\nnu ascundeRegistrii\n";
//     return out;
// }

class Ransomware : public Malware {
protected:
    int ratingCriptare,ratingObfuscare;
public:
    Ransomware(){}

    Ransomware(float ratingImpact, vector <int> dataInfectare,string nume,string metodaInfectare,vector <string> registriiInfectati,int ratingCriptare,int ratingObfuscare):
        Malware(ratingImpact,dataInfectare,nume,metodaInfectare,registriiInfectati){
            this->ratingCriptare=ratingCriptare;
            this->ratingObfuscare=ratingObfuscare;
    }

    Ransomware(const Ransomware &m){
        this->ratingImpact=m.ratingImpact;
        this->dataInfectare=m.dataInfectare;
        this->nume=m.nume;
        this->metodaInfectare=m.metodaInfectare;
        this->registriiInfectati=m.registriiInfectati;
        this->ratingCriptare=ratingCriptare;
        this->ratingObfuscare=ratingObfuscare;
    }

    virtual ~Ransomware(){
        ratingImpact=0.0;
        dataInfectare.clear();
        nume=metodaInfectare="";
        registriiInfectati.clear();
        ratingCriptare=ratingObfuscare=0;
    }

    int get_ratingCriptare() const{
        return ratingCriptare;
    }

    void set_ratingCriptare(int ratingCriptare){
        this->ratingCriptare=ratingCriptare;
    }

    int get_ratingObfuscare() const{
        return ratingObfuscare;
    }

    void set_ratingObfuscare(int ratingObfuscare){
        this->ratingObfuscare=ratingObfuscare;
    }

    Ransomware &operator=(const Ransomware &m){
        this->ratingImpact=m.ratingImpact;
        this->dataInfectare=m.dataInfectare;
        this->nume=m.nume;
        this->metodaInfectare=m.metodaInfectare;
        this->registriiInfectati=m.registriiInfectati;
        this->ratingCriptare=ratingCriptare;
        this->ratingObfuscare=ratingObfuscare;
        return *this;
    }

    // friend istream &operator>>(istream &is, Ransomware &m);
    // friend ostream &operator<<(ostream &out, const Ransomware &m);

    virtual void calculRatingImpact(){
        for(int i=0;i<registriiInfectati.size();i++)
            if(registriiInfectati[i]=="HKLM-run" || registriiInfectati[i]=="HKCU-run")
                ratingImpact+=20;
        ratingImpact+=ratingCriptare+ratingObfuscare;
    }

    virtual istream& citire(istream &is){
        cout<<"\ndataInfectare:\n";
        int x;
        while(true){
            try{
                cout<<"\nzi:"; is>>x;
                if(x<1 || x>31)
                    throw string("\nInvalid!\n");
                dataInfectare.push_back(x);
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        }

        while(true){
            try{
                cout<<"\nluna:"; cin>>x;
                if(x<1 || x>12)
                    throw string("\nInvalid!\n");
                dataInfectare.push_back(x);
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        }
        while(true){
            try{
                cout<<"\nan:"; is>>x;
                if(x<1)
                    throw string("\nInvalid!\n");
                dataInfectare.push_back(x);
                break;
            }
            catch(string s){
                cout<<s<<endl;
            }
        }
        cout<<"\nnume: "; is>>nume;
        cout<<"\nmetodaInfectare: "; is>>metodaInfectare;
        cout<<"\nnumarul de registrii infectati: "; int nr; is>>nr;
        cout<<"\nregistrii:\n";
        string aux;
        for(int i=0;i<=nr;i++){
            getline(cin,aux);
            registriiInfectati.push_back(aux);
        }
        cout<<"\nratingCriptare: "; is>>ratingCriptare;
        cout<<"\nratingObfuscare: " ; is>>ratingObfuscare;
        return is;
    }

    virtual ostream& afisare(ostream &out){
        out<<"\n\nratingImpact: "<<ratingImpact;
        out<<"\ndataInfectare:\n";
        out<<"\nzi:"<<dataInfectare[0];
        out<<"\nluna:"<<dataInfectare[1];
        out<<"\nan:"<<dataInfectare[2];
        out<<"\nnume: "<<nume;
        out<<"\nmetodaInfectare: "<<metodaInfectare;
        out<<"\nregistrii:\n";
        for(int i=0;i<registriiInfectati.size();i++)
            out<<registriiInfectati[i]<<' ';
        out<<"\nratingCriptare: "<<ratingCriptare;
        out<<"\nratingObfuscare: "<<ratingObfuscare;
        out<<endl;
        return out;
    }
};
// istream &operator>>(istream &is, Ransomware &m){
//     cout<<"\ndataInfectare:\n";
//     int x;
//     while(true){
//         try{
//             cout<<"\nzi:"; is>>x;
//             if(x<1 || x>31)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }

//     while(true){
//         try{
//             cout<<"\nluna:"; cin>>x;
//             if(x<1 || x>12)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }
//     while(true){
//         try{
//             cout<<"\nan:"; is>>x;
//             if(x<1)
//                 throw string("\nInvalid!\n");
//             m.dataInfectare.push_back(x);
//             break;
//         }
//         catch(string s){
//             cout<<s<<endl;
//         }
//     }
//     cout<<"\nnume: "; is>>m.nume;
//     cout<<"\nmetodaInfectare: "; is>>m.metodaInfectare;
//     cout<<"\nnumarul de registrii infectati: "; int nr; is>>nr;
//     cout<<"\nregistrii:\n";
//     for(int i=0;i<nr;i++)
//         is>>m.registriiInfectati[i];
//     cout<<"\nratingCriptare: "; is>>m.ratingCriptare;
//     cout<<"\nratingObfuscare: " ; is>>m.ratingObfuscare;
//     return is;
// }

// ostream &operator<<(ostream &out, const Ransomware &m){
//     out<<"\n\nratingImpact: "<<m.ratingImpact;
//     out<<"\ndataInfectare:\n";
//     out<<"\nzi:"<<m.dataInfectare[0];
//     out<<"\nluna:"<<m.dataInfectare[1];
//     out<<"\nan:"<<m.dataInfectare[2];
//     out<<"\nnume: "<<m.nume;
//     out<<"\nmetodaInfectare: "<<m.metodaInfectare;
//     out<<"\nregistrii:\n";
//     for(int i=0;i<m.registriiInfectati.size();i++)
//         out<<m.registriiInfectati[i]<<' ';
//     out<<"\nratingCriptare: "<<m.ratingCriptare;
//     out<<"\nratingObfuscare: "<<m.ratingObfuscare;
//     out<<endl;
//     return out;
// }

class Computer{
protected:
    static int ID;
    vector <Malware *> malware;
    float ratingFinal=0.0;
public:

    void calcul_ratingFinal(){
        for(int i=0;i<malware.size();i++)
            ratingFinal+=malware[i]->getRatingImpact();
    }

    Computer(){
        ID++;
    }

    Computer(int ID,vector <Malware* > malware){
        this->ID=ID;
        this->malware=malware;
        calcul_ratingFinal();
    }

    Computer(const Computer &c){
        this->ID=c.ID;
        this->malware=c.malware;
        this->ratingFinal=c.ratingFinal;
    }

    ~Computer(){
        ID--;
        malware.clear();
        ratingFinal=0.0;
    }

    int getID() const{
        return ID;
    }

    vector <Malware*> getMalware(){
        return malware;
    }

    void setMalware(vector <Malware*> m){
        malware=m;
    }

    float getRatingFinal() const{
        return ratingFinal;
    }

    Computer &operator=(const Computer &c){
        this->ID=c.ID;
        this->malware=c.malware;
        this->ratingFinal=c.ratingFinal;
        return *this;
    }

    friend istream &operator>>(istream &is,Computer &c);
    friend ostream &operator<<(ostream &out, const Computer &c);
};

int Computer::ID=1;

istream &operator>>(istream &is,Computer &c){
    cout<<"\nDati numarul de malware: "; int nr; is>>nr;
    for(int i=0;i<nr;){
        Malware *m=nullptr;
        try{
            string tip;
            cout<<"\nDati tipuri malware-ului: "; is>>tip;
            if(tip=="Rootkit"){
                m=new Rootkit;
            }
            else
                if(tip=="Keylogger"){
                    m=new Keylogger;
                }
                else
                    if(tip=="KernelKeylogger"){
                        m=new KernelKeylogger;
                    }
                    else
                        if(tip=="Ransomware"){
                            m=new Ransomware;
                        }
                        else throw string("\nInvalid!\n");
            is>>*m;
            c.malware.push_back(m);
            i++;
        }
        catch(string s){
            cout<<s<<endl;
        }
    }
    c.calcul_ratingFinal();
    return is;
}

ostream &operator<<(ostream &out, const Computer &c){
    out<<"\nmalware:\n";
    for(int i=0;i<c.malware.size();i++)
        out<<*c.malware[i];
    out<<"\n\nrating final: "<<c.ratingFinal<<endl;
    return out;
}

// class Meniu{
// private:

//     vector <Computer *> calculatoare;
//     static Meniu* instanta;
//     Meniu()=default;
//     Meniu(const Meniu&m)=default;
//     Meniu &operator=(Meniu &m)=default;

// public:
//     static Meniu* getInstanta(){
//         if(instanta==NULL)
//             instanta=new Meniu();
//         return instanta;
//     }

//     static void deleteInstanta(){
//         if(instanta!=NULL)
//             delete instanta;
//         instanta=NULL;
//     }

//     ~Meniu(){
//         for(int i=0;i<calculatoare.size();i++)
//             delete calculatoare[i];
//         calculatoare.clear();
//     }

//     void adaugareCalculatorNou(){
//         Computer *c=new Computer;
//         cin>>*c;
//         calculatoare.push_back(c);
//     }

//     void cerinta1(){
//         for(int i=0;i<calculatoare.size();i++)
//             cout<<*calculatoare[i]<<endl;
//     }

//     void cerinta2(){
//         Computer *aux; int i,j;
//         for(i=0;i<calculatoare.size()-1;i++)
//             for(j=i+1;j<calculatoare.size();j++)
//                 if(calculatoare[j]->getRatingFinal()<calculatoare[i]->getRatingFinal()){
//                     aux=calculatoare[j];
//                     calculatoare[i]=calculatoare[j];
//                     calculatoare[j]=aux;
//                 }
//         cerinta1();
//     }

//     void cerinta3(int k){
//         Computer *aux; int i,j;
//         for(i=0;i<calculatoare.size()-1;i++)
//             for(j=i+1;j<calculatoare.size();j++)
//                 if(calculatoare[j]->getRatingFinal()<calculatoare[i]->getRatingFinal()){
//                     aux=calculatoare[j];
//                     calculatoare[i]=calculatoare[j];
//                     calculatoare[j]=aux;
//         for(int i=0;i<k;i++)
//             cout<<*calculatoare[i]<<endl;
//     }

//     void cerinta4(){
//         int procent;

//     }
// };

class Meniu{
    //ceva;
    static Meniu* instanta;
    Meniu()=default;
    Meniu(const Meniu& m)=default;
    Meniu &operator=(const Meniu &m)=default;
public:
    static Meniu * getInstanta(){
        if(instanta==nullptr)
            instanta=new Meniu;
        return instanta;
    }

    static Meniu* deleteInstanta(){
        if(instanta!=nullptr)
            delete instanta;
        instanta=nullptr;
    }

};

Meniu * Meniu::instanta=nullptr;

int main(){
    Meniu *m=m->getInstanta();
    Computer c;
    cin>>c;
    cout<<c;
    return 0;
}