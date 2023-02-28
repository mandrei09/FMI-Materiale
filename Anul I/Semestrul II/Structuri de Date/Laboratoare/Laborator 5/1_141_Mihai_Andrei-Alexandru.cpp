#include <iostream>
using namespace std;

//strucutra pentru arborele binar de cautare
struct tree{
    int data;
    tree* left, *right;
};

//inserarea nodurilor in arbore
tree* add_first(int data){
    tree *newnode=new tree;
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

tree* insert(tree* root,int data){
    if(root==NULL)
        return add_first(data);
    else
        if(data<root->data)
            root->left=insert(root->left,data);
        else
            root->right=insert(root->right,data);
    return root;
}

void RSD(tree* root){
    //preordine
    if(root){
        cout<<root->data<<' ';
        RSD(root->left);
        RSD(root->right);
    }
}

void SRD(tree* root){
    //inordine
    if(root){
        SRD(root->left);
        cout<<root->data<<' ';
        SRD(root->right);
    }
}

void SDR(tree* root){
    //postordine
    if(root){
        SDR(root->left);
        SDR(root->right);
        cout<<root->data<<' ';
    }
}

int main(){
    tree* arbore=NULL;

    arbore=insert(arbore,8);
    arbore=insert(arbore,3);
    arbore=insert(arbore,1);
    arbore=insert(arbore,6);
    arbore=insert(arbore,7);
    arbore=insert(arbore,14);
    arbore=insert(arbore,10);

    cout<<"Preordine: " ; RSD(arbore); cout<<endl;
    cout<<"Inordine: " ; SRD(arbore); cout<<endl;
    cout<<"Postordine: " ; SDR(arbore); cout<<endl;
    
    return 0;
}