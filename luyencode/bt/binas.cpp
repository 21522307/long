#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n] = {0};
    bool check;
    do
    {
        for (int i = 0; i < n; ++i)
        {
            cout << a[i];
        }
        cout << endl;
        check = false;
        for (int i = n - 1; i >= 0; --i)
        {
            a[i] = !a[i];
            if (a[i] == 1)
            {
                check = true;
                break;
            }
        }
    } while (check == true);
    return 0;
}