#include<iostream>
#include<stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> st;
    while (n > 0){
        st.push(n % 2);
        n /= 2;
    }
    while(!st.empty()){
        cout << st.top() ;
        st.pop();
    }
    return 0;
}