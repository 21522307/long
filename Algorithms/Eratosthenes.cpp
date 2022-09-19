#include<bits/stdc++.h>

using namespace std;

int main() {
    const int N = 1000000;
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
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++){
        if (prime[i]){
            cout << i << " ";
        }
    }
    return 0;
}