#include <iostream>
using namespace std;

//structura nodului
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

//stergerea unui nod din arbore
void node_delete(tree* root,int data){
    if(root==NULL) cout<<"\nNu am gasit nodul.\n";
    else
        if(data==root->data){
            //nu este frunza
            cout<<"\nAm gasit nodul "<<data<<",urmeaza sa fie sters.\n";
            //se merge pana la penultimul nod apoi se sterge ultimul dupa ce s-au facut modificarile
            if(root->right!=NULL){
                while(root->right->right!=NULL){
                    root->data=root->right->data;
                    root=root->right;
                }
                root->data=root->right->data;
                root->right=NULL;
                delete root->right;
            }
            else{
                while(root->left->left!=NULL){
                    root->data=root->left->data;
                    root=root->left;
                }
                root->data=root->left->data;
                root->left=NULL;
                delete root->left;
            }
        }
        else
            //daca l-am gasit, este frunza
            if(data<root->data)
                if(root->left->data==data && root->left->left==NULL && root->left->right==NULL)
                {
                    cout<<"\nAm gasit nodul "<<data<<",urmeaza sa fie sters.\n";
                    root->left=NULL;
                    delete root->left;
                }
                //daca nu, il cautam in continuare
                else
                    node_delete(root->left,data);
            else
                if(root->right->data==data && root->right->left==NULL && root->right->right==NULL)
                {
                    cout<<"\nAm gasit nodul "<<data<<",urmeaza sa fie sters.\n";
                    root->right=NULL;
                    delete root->right;
                }
                else
                    node_delete(root->right,data);
}

//afisare
void inorder(tree* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<' ';
        inorder(root->right);
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
    arbore=insert(arbore,0);
    node_delete(arbore,8);
    inorder(arbore);
    
    return 0;
}