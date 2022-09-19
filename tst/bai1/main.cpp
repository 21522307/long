#include <bits/stdc++.h>

using namespace std;

ifstream FileData;
ofstream FileOut;
const int N = 1e5 + 10;
int a[N];
long long p[N] = {0};
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
        printTree(t->right);
        FileOut << t->data << " ";
        printTree(t->left);
    }
}
int DemXY(node *t, int x, int y)
{
    if (t == NULL)
        return 0;
    int a = DemXY(t->left, x, y);
    int b = DemXY(t->right, x, y);
    if (t->data > x && t->data < y)
        return a + b + 1;
    return a + b;
}
node *NodeTraiNhat(node *t)
{
    if (t->left)
        return NodeTraiNhat(t->left);
    node *temp = t;
    return temp;
}
int TimTraiNhat(node *tree, int t)
{
    if (tree == NULL)
        return 0;
    if (tree->data > t)
        return TimTraiNhat(tree->left, t);
    if (tree->data < t)
        return TimTraiNhat(tree->right, t);
    // Tìm thấy phần tử t
    node *temp = NodeTraiNhat(tree);
    return temp->data;
}
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
void Solution(node *t)
{
    if (t != NULL)
    {
        Solution(t->left);
        if (isPrime(t->data))
        {
            FileOut << t->data << " ";
        }
        Solution(t->right);
    }
}
bool Search(node *t, int x)
{
    if (t != NULL)
    {
        if (t->data == x)
        {
            return true;
        }
        else
        {
            if (x > t->data)
            {
                return Search(t->right, x);
            }
            else
            {
                return Search(t->left, x);
            }
        }
    }
    return false;
}

int main()
{
    FileData.open("data.txt", ios_base::in);
    FileOut.open("output.txt", ios_base::out);

    int n, x;
    FileData >> n;
    node *t = NULL;
    for (int i = 0; i < n; i++)
    {
        FileData >> x;
        t = insert(t, x);
    }
    printTree(t);
    FileOut << endl;
    Solution(t);
    FileOut << endl;

    int k, a, b, z;
    ifstream FileIn;
    FileIn.open("input.txt", ios_base::in);

    FileIn >> a >> b;
    FileIn >> k;
    FileIn >> z;

    FileOut << Search(t, k);
    FileOut << DemXY(t, a, b) << endl;
    FileOut << TimTraiNhat(t, z) << endl;

    FileOut.close();
    FileIn.close();
    FileData.close();
    return 0;
}