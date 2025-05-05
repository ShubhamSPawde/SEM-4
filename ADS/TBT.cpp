#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    bool lthread, rthread;
};

node *CreateNode(int val)
{
    node *temp = new node();
    temp->data = val;
    temp->left = temp->right = NULL;
    temp->lthread = temp->rthread = true;
    return temp;
}

node *InsertNode(node *root, int val)
{
    node *ptr = root, *par = NULL;
    while (ptr != NULL)
    {
        if (val == ptr->data)
        {
            cout << "Duplicate key\n";
            return root;
        }
        par = ptr;
        if (val < ptr->data)
        {
            if (!ptr->lthread)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (!ptr->rthread)
                ptr = ptr->right;
            else
                break;
        }
    }
    node *temp = CreateNode(val);
    if (par == NULL)
        root = temp;
    else if (val < par->data)
    {
        temp->left = par->left;
        temp->right = par;
        par->lthread = false;
        par->left = temp;
    }
    else
    {
        temp->left = par;
        temp->right = par->right;
        par->rthread = false;
        par->right = temp;
    }
    return root;
}

bool search(node *root, int val)
{
    node *temp = root;
    while (temp != NULL)
    {
        if (val < temp->data)
        {
            if (temp->lthread)
                return false;
            temp = temp->left;
        }
        else if (val > temp->data)
        {
            if (temp->rthread)
                return false;
            temp = temp->right;
        }
        else
            return true;
    }
    return false;
}

void InOrder(node *root)
{
    if (!root)
        return;
    if (!root->lthread)
        InOrder(root->left);
    cout << root->data << " ";
    if (!root->rthread)
        InOrder(root->right);
}

void PreOrder(node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    if (!root->lthread)
        PreOrder(root->left);
    if (!root->rthread)
        PreOrder(root->right);
}

void PostOrder(node *root)
{
    if (!root)
        return;
    if (!root->lthread)
        PostOrder(root->left);
    if (!root->rthread)
        PostOrder(root->right);
    cout << root->data << " ";
}

node *leftmost(node *n)
{
    if (!n)
        return NULL;
    while (!n->lthread)
        n = n->left;
    return n;
}

void NonRecursiveInOrder(node *root)
{
    node *curr = leftmost(root);
    while (curr != NULL)
    {
        cout << curr->data << " ";
        if (curr->rthread)
            curr = curr->right;
        else
        {
            curr = curr->right;
            curr = leftmost(curr);
        }
    }
}

void NonRecursivePreOrder(node *root)
{
    if (!root)
        return;
    node *ptr = root;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        if (!ptr->lthread)
            ptr = ptr->left;
        else if (!ptr->rthread)
            ptr = ptr->right;
        else
        {
            while (ptr && ptr->rthread)
                ptr = ptr->right;
            if (ptr)
                ptr = ptr->right;
        }
    }
}

void NonRecursivePostOrder(node *root)
{
    if (!root)
        return;
    stack<node *> s;
    node *curr = root, *last = NULL;
    while (!s.empty() || curr)
    {
        if (curr)
        {
            s.push(curr);
            curr = curr->lthread ? NULL : curr->left;
        }
        else
        {
            node *temp = s.top();
            if (temp->rthread || temp->right == last)
            {
                cout << temp->data << " ";
                s.pop();
                last = temp;
            }
            else
            {
                curr = temp->right;
            }
        }
    }
}

node *InOrderPredecessor(node *ptr)
{
    if (ptr->lthread)
        return ptr->left;
    ptr = ptr->left;
    while (!ptr->rthread)
        ptr = ptr->right;
    return ptr;
}

node *InOrderSuccessor(node *ptr)
{
    if (ptr->rthread)
        return ptr->right;
    ptr = ptr->right;
    while (!ptr->lthread)
        ptr = ptr->left;
    return ptr;
}

node *CaseA(node *root, node *par, node *ptr)
{
    if (!par)
        root = NULL;
    else if (ptr == par->left)
    {
        par->lthread = true;
        par->left = ptr->left;
    }
    else
    {
        par->rthread = true;
        par->right = ptr->right;
    }
    delete ptr;
    return root;
}

node *CaseB(node *root, node *par, node *ptr)
{
    node *child = ptr->lthread ? ptr->right : ptr->left;
    if (!par)
        root = child;
    else if (ptr == par->left)
        par->left = child;
    else
        par->right = child;

    node *succ = InOrderSuccessor(ptr);
    node *pred = InOrderPredecessor(ptr);

    if (!ptr->lthread)
        pred->right = succ;
    else if (!ptr->rthread)
        succ->left = pred;

    delete ptr;
    return root;
}

node *CaseC(node *root, node *par, node *ptr)
{
    node *ParSucc = ptr, *Succ = ptr->right;
    while (!Succ->lthread)
    {
        ParSucc = Succ;
        Succ = Succ->left;
    }
    ptr->data = Succ->data;
    if (Succ->lthread && Succ->rthread)
        root = CaseA(root, ParSucc, Succ);
    else
        root = CaseB(root, ParSucc, Succ);
    return root;
}

node *delNode(node *root, int val)
{
    node *ptr = root, *par = NULL;
    bool found = false;
    while (ptr != NULL)
    {
        if (val == ptr->data)
        {
            found = true;
            break;
        }
        par = ptr;
        if (val < ptr->data)
        {
            if (!ptr->lthread)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (!ptr->rthread)
                ptr = ptr->right;
            else
                break;
        }
    }
    if (!found)
    {
        cout << "Value not present in tree\n";
        return root;
    }
    if (!ptr->lthread && !ptr->rthread)
        return CaseC(root, par, ptr);
    else if (!ptr->lthread)
        return CaseB(root, par, ptr);
    else
        return CaseA(root, par, ptr);
}

int main()
{
    node *root = NULL;
    int num, choice, x;
    do
    {
        cout << "\n1.Insertion\n2.Search\n3.Recursive Inorder\n4.Recursive Preorder\n5.Recursive Postorder\n";
        cout << "6.Non Recursive Inorder\n7.Non Recursive Preorder\n8.Non Recursive Postorder\n9.Deletion\n0.Exit\nChoice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number of nodes: ";
            cin >> x;
            cout << "Enter nodes: ";
            for (int i = 0; i < x; i++)
            {
                cin >> num;
                root = InsertNode(root, num);
            }
            break;
        case 2:
            cout << "Enter element to search: ";
            cin >> num;
            cout << (search(root, num) ? "Found\n" : "Not Found\n");
            break;
        case 3:
            cout << "Recursive Inorder: ";
            InOrder(root);
            cout << endl;
            break;
        case 4:
            cout << "Recursive Preorder: ";
            PreOrder(root);
            cout << endl;
            break;
        case 5:
            cout << "Recursive Postorder: ";
            PostOrder(root);
            cout << endl;
            break;
        case 6:
            cout << "Non Recursive Inorder: ";
            NonRecursiveInOrder(root);
            cout << endl;
            break;
        case 7:
            cout << "Non Recursive Preorder: ";
            NonRecursivePreOrder(root);
            cout << endl;
            break;
        case 8:
            cout << "Non Recursive Postorder: ";
            NonRecursivePostOrder(root);
            cout << endl;
            break;
        case 9:
            cout << "Enter node to delete: ";
            cin >> num;
            root = delNode(root, num);
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}
