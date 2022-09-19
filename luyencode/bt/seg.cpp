#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n], sum = 0, x, Max = -1;
    for(int i = 0; i < n; ++i){
        cin >> x;
        sum += x;
        a[i] = sum;
    }
    for(int i = 0; i < n; ++i){
        int cnt = 1, j = i, check = 1;
        x = 2 * a[i];
        while(j + 1 < n){
            j = lower_bound(a + j + 1, a + n, x) - a;
            if(j != n && a[j] == x){
                cnt++;
                x += a[i];
            }
            else{
                check = 0;
                break;
            }
        }
        if(check == 1){
            Max = max(Max, cnt);
            break;
        }
    }
    cout << Max;
    return 0;
}