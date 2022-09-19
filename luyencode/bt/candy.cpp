#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long a[n+2];
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    long long m = a[n] - a[1];
    int k = 1;
    while(k < n){
        m = min(m,abs(a[n] - a[k]*2));
        k++;
    }
    cout << m;
    return 0;
}