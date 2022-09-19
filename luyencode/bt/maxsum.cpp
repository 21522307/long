#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n + 2];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    long long m = 0;
    int k = 1;
    while (k <= n)
    {
        for (long long i = 1; i <= n - k + 1; i++)
        {
            m = max(m, a[i + k - 1] - a[i - 1]);
        }
        k++;
    }
    cout << m;
    return 0;
}