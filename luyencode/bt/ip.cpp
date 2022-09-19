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
    int n, a[500000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if (n == 0)
        cout << "1";
    else
    {
        if (a[0] >= 2)
            cout << "1";
        else
        {
            int t = a[0];
            while (a[0] <= t && binary(a, 0, n - 1, t) != -1)
            {
                t++;
            }
            cout << t;
        }
    }
}