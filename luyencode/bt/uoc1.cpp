#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long a, b, t = 0;
   cin >> a >> b;
   for (int i = 1; i <= sqrt(a); i++) {
      if (a % i == 0) {
        if (a/i == i) {
            if (b % i != 0) t = t + i;
        }
        else {
            if (b % i != 0) t = t + i;
            if (b % (a / i) != 0) t = t + a/i;
        }
      }
   }
   cout << t;
}