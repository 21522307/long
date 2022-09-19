#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

bool isprime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    queue<int> st;
    if (n == 1)
    {
        cout << "-1";
    }
    if (n <= 10)
    {
        for (int i = 2; i <= n; i++)
        {
            if (isprime(i))
                st.push(i);
        }
    }
    else
    {
        for (int i = 2; i < 10; i++)
        {
            if (isprime(i))
                st.push(i);
        }
    }
    while (!st.empty())
    {
        for (int i = 1; i <= 9; i++)
        {
            int x = st.front() * 10 + i;
            if (x <= n && isprime(x))
            {
                st.push(x);
            }
        }
        cout << st.front() << " ";
        st.pop();
    }
    return 0;
}