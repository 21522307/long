#include <iostream>

using namespace std;

int main()
{
    long long n,k = 0,t1 = 0,t2 = 0,d = 0,k2 = 1;
    cin >> n;
    while (n > t1) {
        t1 = t1 + k;
        k++;
    }
    while (n > t2){
        t2 = t2 + k2;
        k2 = k2 + 2;
    }
    if (t1 == n && k >= 3|| n == t2 && k2 >= 4) cout << "YES";
    else cout << "NO";
}