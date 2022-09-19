#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if (n < 10){
        cout << n;
    }else{
        int m = n;
        while (m >= 10){
        int s = 0;
        while (m > 0){
            s += m%10;
            m /= 10;
        }
        m = s;
    }
        cout << m ;
    }
    return 0;
}