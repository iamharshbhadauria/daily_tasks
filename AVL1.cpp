#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    int height = 1;
    node(int key){
        data = key;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVLTree{
private:
    node* root; 

    //AVLTree(){root = NULL;}
    int getheight(node* root){
        if(root==NULL) return 0;

        return root->height;
    }

    int getBalanceFactor(node* root){
        if(root==NULL) return 0;

        return getheight(root->left)- getheight(root->right);
    }

    node* rotateLeft(node* root){
        node* newroot = root->right;
        node* temp = newroot->left;

        newroot->left = root;
        root->right = temp;

        root->height = 1 + max(getheight(root->left), getheight(root->right));
        newroot->height = 1 + max(getheight(newroot->right), getheight(newroot->left));

        return newroot;
    }

    node* rotateRight(node* root){
        node* newroot = root->left;
        node* temp = newroot->right;

        newroot->right = root;
        root->left = temp;

        root->height = 1+max(getheight(root->left), getheight(root->right));
        newroot->height = 1+ max(getheight(newroot->left), getheight(newroot->right));

        return newroot;
    }

    node* insert(node* root, int key){
        if(root==NULL) return new node(key);

        if(key < root->data){
            root->left = insert(root->left, key);
        } else if(key > root->data){
            root->right = insert(root->right, key);
        } else{
            return root;
        }

        root->height= 1+max(getheight(root->left), getheight(root->right));

        int balance = getBalanceFactor(root);

        if(balance > 1 and key < root->left->data){
            return rotateRight(root);
        }
        if(balance < -1 and key > root->right->data){
            return rotateLeft(root);
        }
        if(balance > 1 and key > root->left->data){
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        if(balance < -1 and key < root->right->data){
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void levelOrder(node* root){
        if(root==NULL) return;

        queue<node*> q;

        q.push(root);

        while(!q.empty()){
            node* curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if(curr->left!=NULL){q.push(curr->left);}
            if(curr->right!=NULL){q.push(curr->right);}
        }
    }

    int heightofTree(node* root){
        if(root==NULL){return 0;}
        return root->height;
    }

public:
    AVLTree(){root=NULL;}

    void insertnode(int key){
        root = insert(root, key);
    }
    void levelOrderTraversal(){
        levelOrder(root);
    }

    int getheightOfTree(){
        return heightofTree(root);
    }
};

int main(){
    AVLTree tree;
    int n;
    cout << "Enter the no. of elements you want to insert" << endl;
    cin >> n;

    cout << "Enter the elements " << endl;
    for(int i = 0; i <n;i++){
        int key;
        cin >> key;
        tree.insertnode(key);
    }

    cout << "Level order traversal is "<< endl;
    tree.levelOrderTraversal();
    cout << endl;
    cout << "Height of tree is " << tree.getheightOfTree() << endl;
}