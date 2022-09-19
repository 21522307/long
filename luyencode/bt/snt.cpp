#include<bits/stdc++.h>

using namespace std;
const int N = 100000;

int main(){
    bool prime[N + 1]; // Sàng nguyên tố 
    memset(prime, true, sizeof(prime)); 
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    int nto[N + 1] = {0};      // prefix sum
    nto[1] = 0;
    nto[2] = 1;
    for (int i = 3; i<= N; i++) {
        if (prime[i])
            nto[i] = nto[i-1] + 1;
        else
            nto[i] = nto[i-1];
    }
    int t;
    cin >> t;
    int l,r;
    while (t--) {
        cin >> l >> r;
        cout << nto[r] - nto[l-1] << endl;
    }
    return 0;
}