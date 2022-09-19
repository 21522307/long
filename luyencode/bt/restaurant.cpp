#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i].first;
        if (i % 2 == 0)
        {
            a[i].second = 1;
        }
        else
        {
            a[i].second = -1;
        }
    }
    sort(a.begin(), a.end());
    int cnt = 0, Max = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        cnt += a[i].second;
        Max = max(Max, cnt);
    }
    cout << Max;
    return 0;
}