#include <iostream>
#include <string>
using namespace std;

//structura arborelui
struct tree{
    string data;
    tree* left, *right;
};

//inserare
tree* add_first(string data){
    tree *newnode=new tree;
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

//se insereaza in mod opus celui obisnuit
tree* insert(tree* root,string data){
    if(root==NULL)
        return add_first(data);
    else
        if(data>root->data)
            root->left=insert(root->left,data);
        else
            root->right=insert(root->right,data);
    return root;
}

//afisare
void SRD(tree* root){
    //inordine
    if(root){
        SRD(root->left);
        cout<<root->data<<endl;
        SRD(root->right);
    }
}

int main(){

    tree* arbore=NULL;
    int n,i; string cuvant;
    cout<<"Dati numarul de cuvinte:"; cin>>n;
    cout<<"Dati cuvintele:\n";
    for(i=1;i<=n;i++){
        cin>>cuvant;
        arbore=insert(arbore,cuvant);
    }
    cout<<endl;
    SRD(arbore);

    return 0;
}