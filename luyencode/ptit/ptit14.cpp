#include<bits/stdc++.h>

using namespace std;

int main(){
   int n ;
   cin >> n;
   if (n < 0){
       cout << "5";
   }else{
   long long a = pow(2,n);
   int s = a%10;
   cout << s;
   }
   return 0;
}