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
int treeLevel(TREE &t)

{
    if (!t)
        return 0;
    int a = treeLevel(t->left);
    int b = treeLevel(t->right);
    if (a > b)
        return (a + 1);
    return (b + 1);
}
int Sum(TREE &t)
{
    if (t != NULL)
    {
        int a = Sum(t->left);
        int b = Sum(t->right);
        return t->data + a + b;
    }
    return 0;
}
void Solution(TREE &t)
{
    if (t != NULL)
    {
        if (t->left != NULL && t->right != NULL)
        {
            Solution(t->left);
            if (Sum(t->left) == Sum(t->right))
            {
                FileOut << t->data << " ";
            }
            Solution(t->right);
        }
    }
}
int isPerfect(int n)
{
    int s = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
            s += i;
    }
    if (s == n)
        return 1;
    return 0;
}
void printPerfectNumber(TREE &t)
{
    if (t != NULL)
    {
        printPerfectNumber(t->right);
        if (isPerfect(t->data))
        {
            FileOut << t->data << " ";
        }
        printPerfectNumber(t->left);
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
void DeletePerfectNumber(TREE &t)
{
    if (!t)
        return;
    DeletePerfectNumber(t->left);
    DeletePerfectNumber(t->right);
    if (isPerfect(t->data))
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
    printTree(t); //
    FileOut << endl;

    FileOut << treeLevel(t); // chieu cao cua cay
    FileOut << endl;

    Solution(t); //
    FileOut << endl;

    printPerfectNumber(t); // in so hoan thien
    FileOut << endl;

    DeletePerfectNumber(t); // xoa so hoan thien
    printTree1(t);

    FileOut.close();
    FileData.close();
    return 0;
}