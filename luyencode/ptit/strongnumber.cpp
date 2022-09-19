#include<bits/stdc++.h>

using namespace std;

bool isprime(int n){
    if (n < 2) return false;
    for (int i = 2; i  <= sqrt(n); i++)
        if (n % i == 0) return false;
        return true;
}
int main(){
    int a, b;
    cin >> a >> b;
    int k = 0;
    for (int i = a + 1; i <= b; i++){
        int s = 0;
        int m = i;
        while (m > 0){
        s += m%10;
        m /=10;
        }   
        if (isprime(s)){
            k++;
        }
        }
    
    cout << k;
   
    return 0;
}