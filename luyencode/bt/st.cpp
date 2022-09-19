#include<iostream>
#include<string>

using namespace std;
int main(){
    int n ,k;
    int a[1000];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;
    int x;
    while(k--){
        x = a[0];
        for (int i = 0; i < n - 1; i++){
            a[i] = a[i + 1];
            if(i + 1 == n - 1){
                a[i + 1] = x;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}