#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    long long s = 0;
    while (n >= k && k >= 2){
        n = n - k + 1;
        s += k;
    
    }    
    if ( n < k){
        s += n;
    }
    cout << s;
    return 0;
}