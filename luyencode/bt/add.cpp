#include <iostream>

using namespace std;
void nhap(int arr[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void add(int arr[], int &n)
{
    int k, x;
    cin >> k >> x;
    for (int i = n; i >= k + 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    n++;
}
void xuat(int arr[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int a[10000];
    nhap(a, n);
    add(a, n);
    xuat(a, n);
    return 0;
}