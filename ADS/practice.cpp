#include<bits/stdc++.h>
using namespace std;

class Tree{
    public:
    int data;
    Tree* left;
    Tree* right;
};

Tree* createNode(int data){
    Tree* newNode = new Tree();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Tree* insert(Tree *root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(root->data < data){
        root->right = insert(root->right, data);
    }
    else{
        root->left = insert(root->left, data);
    }
    return root;
}

void inorder(Tree *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preoder(Tree *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Tree *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void NR_inorder(Tree *root){
    Tree *curr = root;
    stack<Tree *> s;
    while(s.empty() == false || curr!= NULL){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top(); s.pop();
        cout<<curr->data;
        curr = curr->right;
    }
}   

void NR_preorder(Tree *root){
    Tree *curr = root;
    stack<Tree*> s;
    s.push(curr);
    while(!s.empty()){
        curr = s.top(); s.pop();
        cout<<curr->data<<" ";
        if(curr->right != NULL){
            s.push(curr->right);
        }
        if(curr->left != NULL){
            s.push(curr->left);
        }
    }
}

void NR_postorder(Tree *root){
    Tree *curr = root;
    stack<Tree*> s1, s2;
    while(!s1.empty()){
        curr = s1.top(); s1.pop();
        s2.push(curr);
        if(curr->left != NULL){
            s1.push(curr->left);
        }
        if(curr->right != NULL){
            s1.push(curr->right);
        }
    }
    while(!s2.empty){
        curr = s2.top(); s2.pop();
        cout<<curr->data<<" ";
    }
}

int tree_height(Tree *curr){
    if(curr == NULL) return 0;

    int left_height = tree_height(curr->left);
    int right_height = tree_height(curr->right);
    return max(left_height, right_height) + 1;
}

void print_level(Tree *curr, int level){
    if(curr == NULL) return;
    if(level == 0){
        cout<<curr->data<<" ";
    }
    else{
        print_level(curr->left, level-1);
        print_level(curr->right, level-1);
    }
}

void levelorder(Tree *root){
    if(root == NULL){
        cout<<"Tree is empty";
        return;
    }
    int height = tree_height(root);
    for(int i = 0; i<height; i++){
        print_level(root, i);
        cout<<endl;
    }
}

Tree *search(Tree *root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    else if(root->data < data){
        return search(root->right, data);
    }
    else {
        return search(root->left, data);
    }
}

Tree *deletenode(Tree *root, int x){
    if(root == NULL){
        return root;
    }
    if(root->data < x){
        root->right = deletenode(root->right, x);
    }
    else if(root->data > x){
        root->left = deletenode(root->left, x);
    }
    else{
        if(root->left == NULL){
            Tree *curr = root->right;
            delete root;
            return curr;
        }
        if(root->right == NULL){
            Tree *curr = root->left;
            delete root;
            return curr;
        }

        Tree* succ = getSucc(root);
        root->data = succ->data;
        root->right = deletenode(root->right, succ->data);
    }
    return root;
}

Tree *getSucc(Tree *root){
    root = root->right;
    while(root!=NULL && root->left!=NULL){
        root = root->left;
    }
    return root;
}

int main(){

}