#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, m, k;
    cin >> n >> m >> k;
    bool a[n + 1] = {false}, b[n + 1] = {false};
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        a[x] = true;
        b[y] = true;
    }
    long long temp_n = n;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == false)
        {
            temp_n--;
        }
    }
    long long cnt = (n - temp_n) * m;
    for (int i = 1; i <= m; ++i)
    {
        if (b[i] == false)
        {
            cnt += temp_n;
        }
    }
    cout << (n * m) - cnt;
    return 0;
}