#include<bits/stdc++.h>
using namespace std;

class node{
    node *left;
    node *right;
    int data;
    public
        node(int a){
            this->data = a;
            node *left = NULL;
            node *right = NULL;
        }

        friend class binary_tree;
};

class binary_tree{
    node *root;

    public :
        binary_tree(){
            this->root = NULL:
        }

        node *getroot(){
            return root;
        };


        void insert(int a);


        
        void insert_bst(node * , int);
        void preorder(node *);
        void postorder(node *);
        void inorder(node* );

        
        void iter_insert_bst(int);
        void iter_preorder();
        void iter_postorder();
        void iter_inorder();
        void iter_levelorder();

        void clone(node *);
        void mirror(node *);
        void check_equal(node * , node *);
        void height(node *);

        void search(int);
        void delete_node(int);
};


void binary_tree :: insert(){
    node *ptr = new node(data);
    if(root == NULL){
        root = ptr;
        cout << "Inserted succesfully :)" << endl;
        return;
    }
    int choice;
    node *temp = root;

    while(1){
        cout << "Press 0 for inserting on the left suntree of : " << temp->data << endl; 
        cout << "Press 1 for inserting on the right subtree of : " << temp->data << endl; 
        cin >> choice;

        if(choice == 0){
            if(temp->left == NULL){
                temp->left = ptr;
                cout << "Inserted succesfully :)" << endl;
                return; 
            }
            else temp = temp->left;
        }
        if(choice == 1){
            if(temp->right == NULL){
                temp->right = ptr;
                cout << "Inserted succesfully :)" << endl;
                return;
            }
            else temp = temp->right;
        }
    }
}

void binary_tree :: iter_insert_bst(int key){
    node *ptr = new node(key);
    if(root->data == key){
        cout << "Key already present" << endl;
        return;
    }
    if(root == NULL){
        root = ptr;
        cout << "Inserted succesfully :)" << endl;
        return;
    }

    node *temp = root;
    while(true){
        if(temp->data == key){
            cout << "Key already present" << endl;
            return;          
        }

        if(key < temp->data){
            if(temp->left == NULL){
                temp->left == ptr;
                cout << "Inserted succesfully :)" << endl;
                return;
            }
            temp = temp->left;
        }
        if(key > temp->data){
            if(temp->right == NULL){
                temp->right == ptr;
                cout << "Inserted succesfully :)" << endl;
                return;
            }
            temp = temp->right;
        }
    }

}


void binary_tree :: insert_bst(node *temp , int key){
    
    if(temp->data == key){
        cout << "Key already present" << endl;
        return;
    }
    if(temp == NULL){
        root = ptr;
        cout << "Inserted succesfully :)" << endl;
        return;
    }

    if(key < temp->data) insert_bst(temp->left , key);
    if(key > temp->data) insert_bst(temp->right , key);

}

void binary_tree :: preorder(node *temp){
    if(temp != NULL){
        if(temp->data != NULL) cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
    return;
}
void binary_tree :: postorder(node *temp){
    if(temp != NULL){
        preorder(temp->left);
        preorder(temp->right);
        if(temp->data != NULL) cout << temp->data << " ";
    }
    return;
}
void binary_tree :: inorder(node *temp){
    if(temp != NULL){
        preorder(temp->left);
        if(temp->data != NULL) cout << temp->data << " ";
        preorder(temp->right);
    }
    return;
}


void binary_tree :: preorder(){
    node *curr = root;
    stack<node *> s;
    s.push(curr);

    while(s.empty()){
        curr = s.top();
        s.pop();

        cout << curr->data << " ";
        if(curr->right != NULL) s.push(curr->right);
        if(curr->left != NULL) s.push(curr->left);
    }
    return;
}

void binary_tree :: inorder(){
    node *curr = root;
    stack<node *> st;
    st.push(curr);

    while(curr != NULL or st.empty == false){
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();

        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
    return;
}

void binary_tree :: postorder(){
    node *curr = root;
    stack<node *> st1;
    stack<node *> st2;

    st1.push(curr);


    while(st1.empty()){
        curr = st1.top();
        st1.pop();
        st2.push(curr);
        if(curr->left != NULL) st1.push(curr->left);
        if(curr->right != NULL) st1.push(curr->right);
    }
    while(st2.empty()){
        curr = st2.top();
        st2.pop();
        cout << curr->data << " ";
    }
    cout << endl;
    return;
}

void binary_tree :: levelorder(){
    node *curr = root;
    queue<node *> st;
    st.push(curr);
    while(st.empty()){
        curr = st.front();
        st.pop();
        cout << curr->data << " ";
        if(curr->left != NULL) st.push(curr->left);
        if(curr->right != NULL) st.push(curr->right);
    }
    cout << endl;
    return;
}

void binary_tree :: deleted_node(node *temp , int key){
    if(temp == NULL){
        cout << "Element not present !" << endl;
        return;
    }
    else if(temp->data < key){
        deleted_node(temp->right , key);
    }
    else if(temp->data > key){
        deleted_node(temp->left , key);
    }
    else{
        if(temp->left == NULL){
            
        }
    }
}