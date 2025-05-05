#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int key) {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

int height(Node* N) {
    return (N == NULL) ? 0 : N->height;
}

int getBalance(Node* N) {
    return (N == NULL) ? 0 : height(N->left) - height(N->right);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* InsertNode(Node* node, int key) {
    if (node == NULL)
        return new Node(key);

    if (key < node->key)
        node->left = InsertNode(node->left, key);
    else if (key > node->key)
        node->right = InsertNode(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* DeleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = DeleteNode(root->left, key);
    else if (key > root->key)
        root->right = DeleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = DeleteNode(root->right, temp->key);
        }
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

bool search(Node* root, int key) {
    if (root == NULL)
        return false;
    if (root->key == key)
        return true;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

int main() {
    Node* root = NULL;
    int choice, key, x, num;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert nodes\n";
        cout << "2. Recursive Inorder Traversal\n";
        cout << "3. Recursive Preorder Traversal\n";
        cout << "4. Recursive Postorder Traversal\n";
        cout << "5. Search a node\n";
        cout << "6. Delete a node\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of nodes to insert: ";
                cin >> x;
                cout << "Enter numbers: " << endl;
                for (int i = 0; i < x; i++) {
                    cin >> num;
                    root = InsertNode(root, num);
                }
                cout << "Nodes inserted successfully!\n";
                break;

            case 2:
                if (root == NULL) {
                    cout << "Tree is empty.\n";
                } else {
                    cout << "Inorder Traversal: ";
                    inOrder(root);
                    cout << endl;
                }
                break;

            case 3:
                if (root == NULL) {
                    cout << "Tree is empty.\n";
                } else {
                    cout << "Preorder Traversal: ";
                    preOrder(root);
                    cout << endl;
                }
                break;

            case 4:
                if (root == NULL) {
                    cout << "Tree is empty.\n";
                } else {
                    cout << "Postorder Traversal: ";
                    postOrder(root);
                    cout << endl;
                }
                break;

            case 5:
                cout << "Enter key to search: ";
                cin >> key;
                if (search(root, key))
                    cout << "Node found in the AVL tree.\n";
                else
                    cout << "Node not found in the AVL tree.\n";
                break;

            case 6:
                cout << "Enter key to delete: ";
                cin >> key;
                root = DeleteNode(root, key);
                cout << "Node deleted successfully!\n";
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
