#include <iostream>

using namespace std;

//strucura pentru stiva
struct nod{
    int i,j;
    nod* next;
};

//afisare stiva
void print_stack(nod* head){
    while(head!=NULL){
        cout<< head->i<<' '<<head->j<<endl;
        head=head->next;
    }
    cout<<endl;
}

//eliminare de pe stiva
nod* pop(nod *head)
{
    nod *p = head;
    head=head->next;
    delete p;
    return head;
}

//adaugare pe stiva
void push(nod **cap, int i,int j)
{
    nod *nod_nou = new nod;
    nod_nou->i = i;
    nod_nou->j=j;
    nod_nou->next = *cap;
    *cap = nod_nou;
}

//functie de umplere a unei zone 
void etichetare_pixeli(int matrice[][101],int i,int j,int &zona){
    nod* stack=NULL; int x,y;
    //se adauga un "pixel" pe stiva (oricare pixel dintr-o forma)
    push(&stack,i,j);
    while(stack!=NULL){
        x=stack->i; y=stack->j;
        stack=pop(stack);
        matrice[x][y]=zona;
        //se adauga pixelii vecini == 1
        if(matrice[x][y-1]==1) push(&stack,x,y-1);
        if(matrice[x][y+1]==1) push(&stack,x,y+1);
        if(matrice[x-1][y]==1) push(&stack,x-1,y);
        if(matrice[x+1][y]==1) push(&stack,x+1,y);
    }
    //dupa ce am umplut o zona, marim contorul pentru urmatoarea zona care trebuie umpluta
    zona++;
}

void print_matrice(int matrice[][101],int n){
    cout<<endl;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout<<matrice[i][j]<<' ';
        cout<<endl;
    }
}

int main(){
    int n,matrice[101][101]=
    {
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0, 1},
        {1, 1, 1, 0, 0, 0, 1},
        {1, 1, 1, 0, 0, 1, 1}
    },i,j,zona=2;
    
    for(i=0;i<7;i++)
        for(j=0;j<7;j++)
            if(matrice[i][j]==1)
                etichetare_pixeli(matrice,i,j,zona);
    print_matrice(matrice,7);
    
    /*
    0 0 1 0 0 0 0
    0 0 1 1 0 0 0
    0 0 0 0 1 0 0
    0 0 0 1 1 0 0
    0 1 0 0 1 0 1
    1 1 1 0 0 0 1
    1 1 1 0 0 1 1
    */
    return 0;
}