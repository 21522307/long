#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i].second < a[i - 1].second)
        {
            res++;
        }
    }
    cout << res;
    return 0;
}