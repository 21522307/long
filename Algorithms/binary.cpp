#include <bits/stdc++.h>

using namespace std;

int binary(int a[], int l, int r, int x)
{ // binary search
    if (r >= l)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return m;
        if (a[m] > x)
            return binary(a, l, m - 1, x);
        return binary(a, m + 1, r, x);
    }
    return -1;
}
int main()
{
    int n, x;
    cin >> n >> x;
    int a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << binary(a, 0, n - 1, x);
    return 0;
}