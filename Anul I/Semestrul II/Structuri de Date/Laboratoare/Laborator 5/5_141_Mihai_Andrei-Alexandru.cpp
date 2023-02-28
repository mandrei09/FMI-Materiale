#include <iostream>
using namespace std;

//structura nodului
struct tree{
    int data;
    tree* left, *right;
};

//inserare
tree* add_first(int data){
    tree* newnode=new tree;
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

tree* insert(tree* root, int data){
    if(root==NULL)
        return add_first(data);
    else
        if(data<root->data)
            root->left=insert(root->left,data);
        else
            root->right=insert(root->right,data);
    return root;
}

//afisare
void inorder(tree* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<' ';
        inorder(root->right);
    }
}

//cautare nod in arbore + memorare cale pana la el + lungimea acesteia
int search(tree* root,int node,int path[],int poz){
    path[poz]=root->data;
    if(node==root->data)
        return poz+1;
    else
        if(node<root->data)
            search(root->left,node,path,poz+1);
        else
            search(root->right,node,path,poz+1);
}

//ultima valoare comuna de la pozitia i din cei 2 vectori este LCA
int LCA(tree* root,int p,int q){
    int path1[101],path2[101],i,len1,len2;
    len1=search(root,p,path1,0);
    len2=search(root,q,path2,0);
    int len=(len1<len2) ? len1 : len2 ; 
    for(i=len-1;i>=0;i--)
        if(path1[i]==path2[i])
            return path1[i];
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
    arbore=insert(arbore,9);
    arbore=insert(arbore,0);

    cout<<"Cel mai apropiat stramos comun este: "<<LCA(arbore,10,6);
    return 0;
}