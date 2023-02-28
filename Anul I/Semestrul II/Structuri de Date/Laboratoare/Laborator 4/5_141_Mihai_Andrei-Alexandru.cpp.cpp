#include <iostream>
using namespace std;

//structura cozii
struct nod{
    int data;
    nod* next;
};

//afisarea cozii
void print(nod* head){
    while(head!=NULL){
        cout<<head->data<<' ';
        head=head->next;
    }
    cout<<endl;
}

//functii de adaugare in coada
void add_first(nod **cap, int data)
{
    nod *nod_nou = new nod;
    nod_nou->data = data;
    nod_nou->next = *cap;
    *cap = nod_nou;
}

void add_last(nod** head,int data){
    nod* nod_nou=new nod,*aux=*head;
    nod_nou->data=data;
    nod_nou->next=NULL;
    while(aux->next!=NULL)
        aux=aux->next;
    aux->next=nod_nou;
}

nod* push(nod* head,int data){
    if(head==NULL)
        add_first(&head,data);
    else add_last(&head,data);
    return head;
}

//functie de eliminare din coada
nod* pop(nod* head)
{
    nod *p = head;
    head=head->next;
    delete p;
    return head;
}

//calcul maxim
int Maxim3(int d1,int d2,int d3){
    int Max=d1;
    if(d2>Max) Max=d2;
    if(d3>Max) Max=d3;
    return Max;
}

int Maxim2(int a,int b){
    if(a>b) return a;
    return b;
}

int main(){
    nod* intrare=NULL,*iesire=NULL,*aux1=NULL,*aux2=NULL,*aux3=NULL;
    int n,v[15],i;
    cout<<"Dati numarul de vagoane:";
    cin>>n;
    cout<<"Dati ordinea vagoanelor:\n";
    for(i=1;i<=n;i++){
        cin>>v[i];
        intrare=push(intrare,v[i]);
    }
    //pentru cazul cand avem minim 3 vagoane
    if(n>2){
        //se adauga primul vagon in prima linie aux, al doilea vagon in a doua linie, al treilea vagon pe a treia linie
        aux1=push(aux1,intrare->data); 
        intrare=pop(intrare);
        aux2=push(aux2,intrare->data); 
        intrare=pop(intrare);
        aux3=push(aux3,intrare->data); 
        intrare=pop(intrare);

        nod*p1=aux1,*p2=aux2,*p3=aux3;

        //pentru celelalte vagoane cautam sa formam 3 subsiruri descrescatoaree pe cele 3 linii aux
        //adaugam fiecare vagon pe linia corespunzatoare
        while(intrare!=NULL){
            if(intrare->data<=p1->data){
                aux1=push(aux1,intrare->data);
                p1=p1->next;
            }
            else
                if(intrare->data<=p2->data){
                    aux2=push(aux2,intrare->data);
                    p2=p2->next;
                }
                else
                    if(intrare->data<=p3->data){
                        aux3=push(aux3,intrare->data);
                        p3=p3->next;
                    }
                    else 
                        iesire=push(iesire,intrare->data);
            intrare=pop(intrare);
        }
        //se va calcula maximul dintre primul vagon de pe fiecare linie la fiecare pas si se va adauga pe linia de iesire
        if(intrare==NULL){
            int Max,nr=1;
            while(nr<n){
                if(aux1==NULL)
                    if(aux2==NULL)
                        Max=aux3->data;
                    else
                        if(aux3==NULL)
                            Max=aux2->data;
                        else
                            Max=Maxim2(aux2->data,aux3->data);
                else
                    if(aux2==NULL)
                        if(aux1==NULL)
                            Max=aux3->data;
                        else
                            if(aux3==NULL)
                                Max=aux1->data;
                            else
                                Max=Maxim2(aux1->data,aux3->data);
                    else
                        if(aux3==NULL)
                            if(aux1==NULL)
                                Max=aux2->data;
                            else
                                if(aux2==NULL)
                                    Max=aux1->data;
                            else
                                Max=Maxim2(aux1->data,aux2->data);
                        else
                            Max=Maxim3(aux1->data,aux2->data,aux3->data);
                if(aux1!=NULL && aux1->data==Max){
                    iesire=push(iesire,aux1->data);
                    aux1=pop(aux1);
                }
                else
                    if(aux2!=NULL && aux2->data==Max){
                        iesire=push(iesire,aux2->data);
                        aux2=pop(aux2);
                    }
                    else
                        if(aux3!=NULL && aux3->data==Max){
                            iesire=push(iesire,aux3->data);
                            aux3=pop(aux3);
                        }
                nr++;
            }
            print(iesire);
        }
        else cout<<"Nu se poate realiza ordonarea vagoanelor!";
    }
    else{
        //pentru cazul cand sunt 2 vagoane ==>2 posibilitati
        if(n==2){
            aux1=push(aux1,intrare->data); 
            intrare=pop(intrare);
            aux2=push(aux2,intrare->data); 
            intrare=pop(intrare);
            if(aux1->data>aux2->data)
                cout<<aux1->data<<' '<<aux2->data;
            else cout<<aux2->data<<' '<<aux1->data;
            aux1=pop(aux1); aux2=pop(aux2);
        }
        else{
            //pentru cazul cand exista un vagon exista o posibilitate
            aux1=push(aux1,intrare->data); 
            intrare=pop(intrare);
            cout<<aux1->data;
            aux1=pop(aux1);
        }
    }
    //5 8 1 7 4 2 9 6 3
    return 0;
}