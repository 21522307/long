#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a = n;
    int s = 0;
    while (n > 0){
        s += n%10;
        n /=10;
    }
    if (a % s == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }    
    return 0;
}