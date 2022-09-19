#include<bits/stdc++.h>

using namespace std;

bool uoc(int n){
    int k = 0;
    for (int i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
            if ( i*i == n){
                k++;
            }else{
                k += 2;
            }
        }
    }
    if (k % 2 == 1){
        return true;
    }else{
        return false;
    }
}
int main(){
    int a,b;
    cin >> a >> b;
    int count = 0;
    for (int i = a + 1; i < b; i++){
        if (uoc(i)){
            count++;
        }
    }
    cout << count;
    return 0;
}