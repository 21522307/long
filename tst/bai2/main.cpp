#include <bits/stdc++.h>

using namespace std;

ifstream FileData;
ofstream FileOut;
const int n = 1e5 + 10;
struct node
{
    int data;
    node *left;
    node *right;
};
typedef node *TREE;
void Init(TREE &t)
{
    t = NULL;
}
node *insert(TREE &t, int x)
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
void printTree(TREE &t)
{
    if (t != NULL)
    {
        printTree(t->left);
        FileOut << t->data << " ";
        printTree(t->right);
    }
}
void printTree1(TREE &t)
{
    if (t != NULL)
    {
        printTree1(t->right);
        FileOut << t->data << " ";
        printTree1(t->left);
    }
}
int isSquare(int n)
{
    double temp = sqrt(n);
    if (temp - (int)temp == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int CountNode(TREE &t)
{
    if (!t)
        return 0;
    else
        return 1 + CountNode(t->left) + CountNode(t->right);
}
void GetNodeWithCondition(TREE &t)
{
    if (!t)
        return;
    GetNodeWithCondition(t->left);
    if (CountNode(t->left) == CountNode(t->right))
    {
        FileOut << t->data << " ";
    }
    GetNodeWithCondition(t->right);
}
void Solution(TREE &t)
{
    if (t != NULL)
    {
        Solution(t->right);
        if (isSquare(t->data))
        {
            FileOut << t->data << " ";
        }
        Solution(t->left);
    }
}
node *SearchStandFor(TREE &p, TREE &q)
{
    if (p->left)
        return SearchStandFor(p->left, q);
    node *temp = p;
    q->data = p->data;
    p = p->right;
    return temp;
}
void DeleteNode(TREE &t)
{
    node *temp = t;
    if (!t->left && !t->right)
        t = NULL;
    else if (t->left && !t->right)
        t = t->left;
    else if (!t->left && t->right)
        t = t->right;
    else
        temp = SearchStandFor(t->left, t);
    delete temp;
}
void DeleteSquareNumber(TREE &t)
{
    if (!t)
        return;
    DeleteSquareNumber(t->left);
    DeleteSquareNumber(t->right);
    if (isSquare(t->data))
        DeleteNode(t);
}
int main()
{
    FileData.open("data.txt", ios_base::in);
    FileOut.open("output.txt", ios_base::out);

    int n, x;
    FileData >> n;
    TREE t;
    Init(t);
    for (int i = 0; i < n; i++)
    {
        FileData >> x;
        t = insert(t, x);
    }
    printTree(t);

    FileOut << endl;

    Solution(t);
    FileOut << endl;

    GetNodeWithCondition(t);
    FileOut << endl;

    DeleteSquareNumber(t);
    printTree1(t);

    FileOut.close();
    FileData.close();
    return 0;
}