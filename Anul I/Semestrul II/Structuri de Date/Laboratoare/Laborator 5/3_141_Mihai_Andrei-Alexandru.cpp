#include <iostream>
using namespace std;

//structura arborelui
struct tree{
    int data;
    tree* left,*right;
};

//inserare
tree* Root(int data){
    tree* newnode=new tree;
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

tree* insert(tree* root,int data){
    if(root==NULL) return Root(data);
    else
        if(data<root->data) root->left=insert(root->left,data);
        else
            root->right=insert(root->right,data);
    return root;
}

//afisarea nodorilor cu proprietatea ca k1 <= root->data <=k2, in preordine
void preorder(tree* root,int k1,int k2){
    if(root){
        cout<<root->data<<' ';
        if(root->left)
            //daca se respecta conditia, afisezi ce e pe stanga
            if(k1<=root->left->data && root->left->data<=k2)
                preorder(root->left,k1,k2);
        else
            //dar daca nu, e posibil sa fie rezultate pe dreapta
            if(root->left->right)
                if(k1<=root->left->right->data && root->left->right->data<=k2)
                    preorder(root->left->right,k1,k2);
        if(root->right)
            //analog pentru dreapta
            if(k1<=root->right->data && root->right->data<=k2)
                preorder(root->right,k1,k2);
        else
            //daca nu gasesti e posibil sa fie rezultate pe stanga
            if(root->right->left)
                if(k1<=root->right->left->data && root->right->left->data<=k2)
                    preorder(root->right->left,k1,k2);
    }
}

int main(){

    tree* arbore=NULL; int k1,k2;

    cout<<"\nDati cei 2 intregi k1 si k2:\n";
    cin>>k1>>k2;

    arbore=insert(arbore,8);
    arbore=insert(arbore,3);
    arbore=insert(arbore,1);
    arbore=insert(arbore,6);
    arbore=insert(arbore,7);
    arbore=insert(arbore,14);
    arbore=insert(arbore,10);
    arbore=insert(arbore,9);
    arbore=insert(arbore,0);

    cout<<"\nCheile cautate sunt: ";

    //incepem din radacina, stanga sau dreapta pe nivelul 1
    if(arbore->data>=k1 && arbore->data<=k2)
        preorder(arbore,k1,k2);
    else
        if(arbore->data<k1)
            preorder(arbore->right,k1,k2);
        else
            preorder(arbore->left,k1,k2);

    cout<<endl;
    return 0;
}