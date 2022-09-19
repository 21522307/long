#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> s;
    int n;
    cin >> n;
    int a[1000], b[1000] = {0};
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k ;
    cin >> k;
    int m = a[0];
    for (int i = 1; i < n; i++){
        if ( m < a[i]){
            m = a[i];
        }
    }
    for (int i = 0; i <= m; i++){
        b[a[i]]++;
    }
    for (int i = 0; i <= m; i++){
        if (b[i] > 0){
            s.push(i);
        }
    }
    int x = s.size() - k;
    for (int  i = 0; i < x; i++){
        s.pop();
    }
    while(!s.empty()){
        cout << s.front() << " ";
        s.pop();
    }
    return 0;
}