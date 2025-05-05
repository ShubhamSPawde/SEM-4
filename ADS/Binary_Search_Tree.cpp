// Create Menu driven program with following options of Binary Search tree.

// Insertion
// Recursive inorder
// Recursive Preorder
// Recursive postorder
// Non Recursive inorder
// Non Recursive Preorder
// Non Recursive Postorder
// Level wise Printing
// Search the node
// Delete the node
// Exit


#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
};

Tree *createNode(int data)
{
    Tree *newNode = new Tree();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Tree *insert(Tree *root, int data)
{
    if (root == NULL)
        return createNode(data);
    else if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void inorder(Tree *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Tree *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Tree *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Tree *search(Tree *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    else if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

void NR_inorder(Tree *root)
{
    stack<Tree *> s;
    Tree *curr = root;
    while (curr != nullptr || s.empty() == false)
    {
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void NR_preorder(Tree *root)
{
    if (root == NULL)
        return;

    stack<Tree *> st;
    Tree *curr = root;
    st.push(curr);

    while (!st.empty())
    {
        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        if (curr->right != NULL)
        {
            st.push(curr->right);
        }

        if (curr->left != NULL)
        {
            st.push(curr->left);
        }
    }
}

void NR_postorder(Tree *root)
{
    stack<Tree *> s1, s2;
    Tree *curr = root;
    s1.push(curr);
    while (s1.empty() == false)
    {
        curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left != NULL)
        {
            s1.push(curr->left);
        }
        if (curr->right != NULL)
        {
            s1.push(curr->right);
        }
    }

    while (s2.empty() == false)
    {
        root = s2.top();
        s2.pop();
        cout << root->data << " ";
    }
}

int tree_height(Tree *root)
{
    if (!root)
    {
        return 0;
    }
    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);
    return max(left_height, right_height) + 1;
}

void print_level(Tree *root, int level_no)
{
    if (!root)
    {
        return;
    }
    if (level_no == 0)
    {
        cout << root->data << " ";
    }
    else
    {
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }
}

void LevelwisePrinting(Tree *root)
{
    if (!root)
    {
        cout << "Tree is empty!" << endl;
        return;
    }
    int height = tree_height(root);
    for (int i = 0; i < height; i++)
    {
        print_level(root, i);
        cout << endl;
    }
}

Tree *getSuccessor(Tree *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}


Tree *DeleteNode(Tree *root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data > x)
    {
        root->left = DeleteNode(root->left, x);
    }
    else if (root->data < x)
    {
        root->right = DeleteNode(root->right, x);
    }
    else
    {
        if (root->left == NULL)
        {
            Tree *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL)
        {
            Tree *temp = root->left;
            delete root;
            return temp;
        }

        Tree *succ = getSuccessor(root);
        root->data = succ->data;
        root->right = DeleteNode(root->right, succ->data);
    }
    return root;
}


int main()
{
    char c;
    int ch, n, element;
    Tree *root = NULL;
    Tree *result = NULL;  
    do
    {
        cout << "1.Insert" << endl;
        cout << "2.Search" << endl;
        cout << "3.Inorder Recurive" << endl;
        cout << "4.Preorder Recurive" << endl;
        cout << "5.Postorder Recurive" << endl;
        cout << "6.Inorder Non Recurive" << endl;
        cout << "7.Preorder Non Recurive" << endl;
        cout << "8.Postorder Non Recurive" << endl;
        cout << "9.Level-wise printing" << endl;
        cout << "10.Delete Node in Tree" << endl;
        cout << "11.Exit" << endl;
        cout << endl;

        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter number of nodes to insert: ";
            cin >> n;
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++)
            {
                cin >> element;
                root = insert(root, element);
            }
            break;
        case 2:
            cout << "Enter element to search: ";
            cin >> element;
            result = search(root, element);
            if (result != NULL)
            {
                cout << "Element Found!" << endl;
            }
            else
            {
                cout << "Element Not Found!" << endl;
            }
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            NR_inorder(root);
            break;
        case 7:
            NR_preorder(root);
            break;
        case 8:
            NR_postorder(root);
            break;
        case 9:
            LevelwisePrinting(root);
            break;
        case 10:
            cout << "Enter element to delete: ";
            cin >> element;
            root = DeleteNode(root, element);
            cout << "Node deleted." << endl;
            break;
       case 11:
           cout << "Exited" << endl;
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
            break;
        }

        cout << endl;
        cout << "Do you want to continue? (Y/N): ";
        cin >> c;
    } while (c == 'Y' || c == 'y');
}
