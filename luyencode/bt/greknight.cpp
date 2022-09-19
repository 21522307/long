#include <bits/stdc++.h>
using namespace std;
struct Data
{
    long long Money;
    int Power, ID;
};
bool cmp(const Data &a, const Data &b)
{
    return a.Power < b.Power;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    Data a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].Power;
        a[i].ID = i;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].Money;
    }
    sort(a, a + n, cmp);
    int c[k], idx = 0;
    long long sum = 0, res[n];
    for (int i = 0; i < n; ++i)
    {
        int temp = a[i].Money;
        a[i].Money += sum;
        res[a[i].ID] = a[i].Money;
        if (idx < k)
        {
            c[idx++] = temp;
            sum += temp;
            if (idx == k)
            {
                sort(c, c + k, greater<int>());
            }
        }
        else
        {
            if (temp > c[k - 1])
            {
                sum += temp - c[k - 1];
                int j;
                for (j = k - 2; j >= 0; --j)
                {
                    if (temp > c[j])
                    {
                        c[j + 1] = c[j];
                    }
                    else
                    {
                        c[j + 1] = temp;
                        break;
                    }
                }
                if (j == -1)
                {
                    c[0] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << res[i] << " ";
    }
    return 0;
}