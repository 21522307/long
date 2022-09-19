#include <bits/stdc++.h>

using namespace std;

int calc(int n)
{
    int k = 2, sum = 0;
    while (n > 1)
    {
        while (n % k == 0)
        {
            sum += k;
            n /= k;
        }
        k++;
    }
    return sum;
}

int factorSum(int n)
{
    while (n != calc(n))
        n = calc(n);
    return n;
}

int main()
{
    int n;
    cin >> n;
    cout << factorSum(n);
    return 0;
}