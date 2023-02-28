#include <iostream>
#include <string>
using namespace std;

//implementarea unei liste dublu inlantuite
class DoubleLinkedList{
public:

    string numePrenume;
    DoubleLinkedList *next,*prev;

    void addFirst(DoubleLinkedList **head, string data)
    {
        DoubleLinkedList *nou = new DoubleLinkedList;
        nou->numePrenume = data;
        nou->next = *head;
        nou->prev = NULL;
        *head = nou;
    }

    void addLast(DoubleLinkedList **head, string data)
    {
        DoubleLinkedList *nou = new DoubleLinkedList, *last = *head;
        nou->numePrenume = data;
        nou->next = NULL;
        while (last->next != NULL)
            last = last->next;
        last->next = nou;
        nou->prev = last;
    }

    DoubleLinkedList* deleteFirst(DoubleLinkedList *head)
    {
        DoubleLinkedList *p = head;
        head=head->next;
        delete p;
        return head;
    }

    DoubleLinkedList* deleteValue(DoubleLinkedList* head,string numePrenume){
        DoubleLinkedList* p,*q,*l;
        p=head;
        if(head->numePrenume==numePrenume){
            head=head->next;
            delete p;
        }
        else{
            while(p->next->numePrenume!=numePrenume)
                p=p->next;
            if(p->next==NULL)
                return NULL;
            else
            { 
                q=p->next;
                l=q;
                q=q->next;
                delete l;
                p->next=q;
            }
        }
        return head;
    }

    void print(DoubleLinkedList *head){
        while(head!=NULL){
            cout<<head->numePrenume<<" --> ";
            head=head->next;
        }
        cout<<endl;
    }

    int search(DoubleLinkedList *head,string nume){
        while(head!=NULL){
            if(head->numePrenume==nume)
                return 1;
            head=head->next;
        }
        return 0;
    }
};

class HashTable{
    DoubleLinkedList **table;
    int size=0;
public:

    //initializarea unui hashtable
    HashTable(int size){
        this->size=size;
        table=new DoubleLinkedList*[size];
        for(int i=0;i<size;i++)
            *(table+i)=nullptr;
    }

    //functie de hash
    int getHashKey(string data){
        return data.length()%size;
    }

    //inseram oriunde, in functie de poz
    void insertData(string nume){
        int poz=getHashKey(nume);
        if(table[poz]==NULL)
            table[poz]->addFirst(&table[poz],nume);
        else
            table[poz]->addLast(&table[poz],nume);
    }

    void print(){
        cout<<endl;
        for(int i=0;i<size;i++){
            cout<<i<<" : ";
            table[i]->print(table[i]);
        }
    }

    void deleteData(string nume){
        int poz=getHashKey(nume);
        if(table[poz]->search(table[poz],nume)==1){
            cout<<"\nSe va sterge persoana "<<nume<<" de pe pozitia "<<poz<<endl;
            table[poz]=table[poz]->deleteValue(table[poz],nume);
        }
        else cout<<"\nNu exista in baza de date persoana cu numele "<<nume;
    }

    void searchData(string nume){
        int poz=getHashKey(nume);
        if(table[poz]->search(table[poz],nume)==1)
            cout<<"\nExista persoana cu numele "<<nume<<" si se afla pe pozitia "<<poz<<endl;
        else
            cout<<"\nNu exista persoana cu numele :"<<nume<<endl;
    }
};

int main(){
    HashTable table(5);
    table.insertData("Andrei");
    table.insertData("Guta");
    table.insertData("Ana");
    table.insertData("Sarah");
    table.insertData("Mara");
    table.print();
    table.deleteData("Guta");
    table.print();
    table.searchData("Ana");
    return 0;
}