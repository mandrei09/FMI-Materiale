#include <iostream>
#include <cstdlib>
using namespace std;

// afisare array
void afisare_array(int x[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << x[i];

    cout << "\n";
}

// structura unui nod
struct MinHeap_node
{
    char litera;
    int frecventa;
    MinHeap_node *stanga, *dreapta;
};

// crearea unui nod nou
MinHeap_node *nod_nou(char litera, int frecventa)
{
    MinHeap_node *aux = new MinHeap_node;
    aux->litera = litera;
    aux->frecventa = frecventa;
    aux->stanga = aux->dreapta = NULL;
    return aux;
}

// strucura pentru MinHeap
struct MinHeap
{
    int marime, capacitate;
    MinHeap_node **array;
};

// functie pentru crearea unui MinHeap
MinHeap *alocare_MinHeap(int capacitate)
{
    MinHeap *minheap = new MinHeap;
    minheap->marime = 0;
    minheap->capacitate = capacitate;
    minheap->array = new MinHeap_node *[101];
    return minheap;
}

// interschimbarea a 2 noduri minheap
void inter_MinHeap(MinHeap_node **a, MinHeap_node **b)
{
    MinHeap_node *c = *a;
    *a = *b;
    *b = c;
}

//heap==>MinHeap
void heapify(MinHeap *minheap, int index)
{
    int radacina = index, fiu_stanga = 2 * index + 1, fiu_dreapta = 2 * index + 2;
    if (fiu_stanga < minheap->marime && minheap->array[fiu_stanga]->frecventa < minheap->array[radacina]->frecventa)
        radacina = fiu_stanga;
    if (fiu_dreapta < minheap->marime && minheap->array[fiu_dreapta]->frecventa < minheap->array[radacina]->frecventa)
        radacina = fiu_dreapta;
    if (radacina != index)
    {
        inter_MinHeap(&minheap->array[radacina], &minheap->array[index]);
        heapify(minheap, radacina);
    }
}

//
void creare_MinHeap(MinHeap *minheap)
{
    int n = minheap->marime - 1;
    for (int i = (n - 1) / 2; i >= 0; i--)
        heapify(minheap, i);
}

//se creaza un MinHeap care contine fiecare tip de caracter + frecventa sa
MinHeap *creare_constructie_MinHeap(char alfabet[], int frecventa[], int marime)
{
    //se aloca MinHeap-ul
    MinHeap *minheap = alocare_MinHeap(marime);
    for (int i = 0; i < marime; i++)
        minheap->array[i] = nod_nou(alfabet[i], frecventa[i]);
    minheap->marime = marime;
    creare_MinHeap(minheap);
    return minheap;
}

// extrage minumul dintr-un heap
MinHeap_node *minim(MinHeap *minheap)
{
    MinHeap_node *aux = minheap->array[0];
    minheap->array[0] = minheap->array[minheap->marime - 1];
    minheap->marime--;
    heapify(minheap, 0);
    return aux;
}

// insereaza un nod nou in MinHeap
void inserare_Nod_MinHeap(MinHeap *minheap, MinHeap_node *aux)
{
    minheap->marime++;
    int i = minheap->marime - 1;
    while (i && aux->frecventa < minheap->array[(i - 1) / 2]->frecventa)
    {
        minheap->array[i] = minheap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minheap->array[i] = aux;
}

// constructie arbore huffman
MinHeap_node *consturctie_arbore_Huffman(char alfabet[], int frecventa[], int marime)
{
    MinHeap_node *stanga, *dreapta, *nou;
    MinHeap *minheap = creare_constructie_MinHeap(alfabet, frecventa, marime);

    //ne oprim cand ramane doar radacina in MinHeap
    while (minheap->marime != 1)
    {
        stanga = minim(minheap);
        dreapta = minim(minheap);
        //se creaza un nod nou care contine un caracter random si suma frecventelor celor 2 minime in MinHeap 
        //la momentul curent.
        nou = nod_nou('&', stanga->frecventa + dreapta->frecventa);
        nou->stanga = stanga;
        nou->dreapta = dreapta;
        //se insereaza nodul nou in MinHeap
        inserare_Nod_MinHeap(minheap, nou);
    }
    return minim(minheap);
}

struct dictionar
{
    char litera;
    string cod="";
};

string array_to_string(int array[],int len){
    string code="";  char c[1];
    for(int i=0;i<len;i++){
        itoa(array[i],c,10);
        code.push_back(c[0]);
    }
    return code;
}

void afisare_coduri(MinHeap_node *radacina, int traseu[], int index,dictionar alfabet[],int &indice)
{
    //se creaza codificarea pentru o anumita litera
    if (radacina->stanga)
    {
        //pentru stanga avem 1 
        traseu[index] = 0;
        afisare_coduri(radacina->stanga, traseu, index + 1,alfabet,indice);
    }
    if (radacina->dreapta)
    {
        //iar pentru dreapta 0
        traseu[index] = 1;
        afisare_coduri(radacina->dreapta, traseu, index + 1,alfabet,indice);
    }

    //daca am ajuns la o frunza, s-a terminat procesul si putem afisa codul pentru litera respectiva
    if (radacina->stanga == NULL && radacina->dreapta == NULL)
    {
        cout << radacina->litera << ":  ";
        alfabet[indice].litera=radacina->litera;
        alfabet[indice++].cod=array_to_string(traseu,index);
        afisare_array(traseu, index);
    }
}

//subprogramul principal ==> creeaza arborele Huffman si afiseaza codurile pentru fiecare caracter
void codificare(char alfabet[], int frecventa[], int marime, dictionar dict[],int &indice)
{
    MinHeap_node *radacina = consturctie_arbore_Huffman(alfabet, frecventa, marime);
    int traseu[101], index = 0;    
    afisare_coduri(radacina, traseu, index,dict,indice);
}

string codificare_text(string text,char alfabet[],int frecventa[],int &lungime,dictionar dict[],int indice){

    string aux=text,codificat="";
    lungime=0; indice=0; int ok,i,j;
    while(text.length()!=0){
        ok=1;
        for(i=0;i<lungime;i++)
            if(alfabet[i]==text.back()){
                ok=0;
                frecventa[i]++;
            }
        if(ok==1){
            frecventa[lungime]++;
            alfabet[lungime++]=text.back();
        }
        text.pop_back();
    }

    codificare(alfabet,frecventa,lungime,dict,indice);

    for(i=0;i<aux.length();i++)
        for(j=0;j<lungime;j++)
            if(aux[i]==dict[j].litera)
                codificat+=dict[j].cod;

    return codificat;
}

string decodificare_text(string text,dictionar dict[],int lungime){
    int i,j;
    string decodificat="";
    while(text.length())
        for(i=0;i<lungime;i++)
            if(text.find(dict[i].cod)==0){
                decodificat+=dict[i].litera;
                text.erase(0,dict[i].cod.length());
                break;
            }
    return decodificat;
}

int main()
{
    char alfabet[26]; int frecventa[26]={0},lungime,indice; dictionar dict[26];
    string text; 
    cout<<"Dati textul ce urmeaza sa fie codificat: "; cin>>text;
    cout<<"\nCodurile caracterelor sunt: \n\n";
    string codificat=codificare_text(text,alfabet,frecventa,lungime,dict,indice);
    cout<<"\nTextul codificat este: "<<codificat<<endl;
    string decodificat=decodificare_text(codificat,dict,lungime);
    cout<<"\nTextul decodificat este: "<<decodificat<<endl;
    return 0;
}