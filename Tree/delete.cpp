#include <iostream>
#include <math.h>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
node *insert(node *t, int x)
{
    if (t == NULL)
    {
        node *temp = new node;
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else
    {
        if (x < t->data)
        {
            t->left = insert(t->left, x);
        }
        else
        {
            t->right = insert(t->right, x);
        }
    }
    return t;
}
void printTree(node *t)
{
    if (t != NULL)
    {
        printTree(t->left);
        cout << t->data << " ";
        printTree(t->right);
    }
}
void deleteNode(node *t)
{
    if (t != NULL)
    {
        if (t->left != NULL)
            deleteNode(t->left);
        if (t->right != NULL)
            deleteNode(t->right);
        delete (t);
    }
}
node *deleteNumber(node *t, int x)
{
    if (t != NULL)
    {
        if (t->data == x)
        {
            deleteNode(t->left);
            deleteNode(t->right);
            t = NULL;
        }
        else if (t->data > x)
            t->left = deleteNumber(t->left, x);
        else
            t->right = deleteNumber(t->right, x);
    }
    return t;
}
int main()
{
    int n, x, temp;
    cin >> n;
    node *t = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        t = insert(t, temp);
    }
    cin >> x;
    t = deleteNumber(t, x);
    if (t == NULL)
        cout << "NULL";
    else
        printTree(t);
    return 0;
}