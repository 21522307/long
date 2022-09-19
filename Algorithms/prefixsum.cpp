#include <iostream>

using namespace std;

const int N = 1e5+10;
int a[N];
long long p[N] = {0};
 
int main() {
  int n,q;
  cin >> n >> q;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    p[i+1] = p[i] + a[i];
  }

  while(q--){
    int l, r;
    cin >> l >> r;
    cout << p[r] - p[l-1] << " ";     
  }
   return 0;
}