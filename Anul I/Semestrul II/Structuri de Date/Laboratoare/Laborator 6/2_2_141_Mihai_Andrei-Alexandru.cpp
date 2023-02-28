#include <iostream>
#include <string>
using namespace std;

//implementarea unei liste dublu inlantuite
class DoubleLinkedList{
public:

    int data;
    DoubleLinkedList *next,*prev;

    //adaugare la inceputul listei
    void addFirst(DoubleLinkedList **head, int data)
    {
        DoubleLinkedList *nou = new DoubleLinkedList;
        nou->data = data;
        nou->next = *head;
        nou->prev = NULL;
        *head = nou;
    }

    //adaugare la finalul listei
    void addLast(DoubleLinkedList **head, int data)
    {
        DoubleLinkedList *nou = new DoubleLinkedList, *last = *head;
        nou->data = data;
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

    DoubleLinkedList* deleteValue(DoubleLinkedList* head,int data){
        DoubleLinkedList* p,*q,*l;
        p=head;
        if(head->data==data){
            head=head->next;
            delete p;
        }
        else{
            while(p->next->data!=data)
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
            cout<<head->data<<" --> ";
            head=head->next;
        }
        cout<<endl;
    }

    int search(DoubleLinkedList *head,int data){
        while(head!=NULL){
            if(head->data==data)
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
    int getHashKey(int data){
        return data%size;
    }

    //inseram unde este gol
    void insertData(int data){
        int poz=getHashKey(data);
        while(table[poz]!=NULL)
            poz++;
        table[poz]->addFirst(&table[poz],data);
    }

    void print(){
        cout<<endl;
        for(int i=0;i<size;i++){
            cout<<i<<" : ";
            table[i]->print(table[i]);
        }
    }

    void deleteData(int data){
        int poz=getHashKey(data);
        while(table[poz]->search(table[poz],data)==0){
            poz++;
            if(poz==size) break;
        }
        if(poz==size)
            cout<<"\nNu exista  numarul: "<<data<<endl;
        else{
            cout<<"\nSe va sterge numarul "<<data<<" de pe pozitia "<<poz<<endl;
            table[poz]=table[poz]->deleteValue(table[poz],data);
        }
    }

    void searchData(int data){
        int poz=getHashKey(data);
        while(table[poz]->search(table[poz],data)==0){
            poz++;
            if(poz==size) break;
        }
        if(poz==size)
            cout<<"\nNu exista numarul "<<data<<endl;
        else
            cout<<"\nExista numarul "<<data<<" si se afla pe pozitia "<<poz<<endl;
    }
};

int main(){
    HashTable table(11);
    table.insertData(24);
    table.insertData(60);
    table.insertData(35);
    table.insertData(15);
    table.insertData(70);
    table.insertData(13);
    table.insertData(49);
    table.insertData(59);
    table.insertData(68);
    table.print();
    table.deleteData(15);
    table.print();
    table.searchData(68);
    return 0;
}