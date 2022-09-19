#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    if (k == 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << i << " ";
        }
    }
    else
    {
        if (n % (2 * k) != 0)
        {
            cout << -1;
        }
        else
        {
            int sz = n / (2 * k);
            int start = 1, finish = 2 * k;
            while (sz--)
            {
                int y = (start + finish) / 2;
                for (int i = y + 1; i <= finish; ++i)
                {
                    cout << i << " ";
                }
                for (int i = start; i <= y; ++i)
                {
                    cout << i << " ";
                }
                start += 2 * k;
                finish += 2 * k;
            }
        }
    }
    return 0;
}