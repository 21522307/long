#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    long long a[n + 2];
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    long long Max=0;
    for(long long i = 1; i <= n - k + 1; i++){
        Max = max(Max,a[i + k - 1] - a[i - 1]);
    }
    cout << Max;
}