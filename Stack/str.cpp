#include<iostream>
#include<stack>

using namespace std; 
int main(){
    string s;
    getline(cin,s);
    stack<char> st;
    for (int i = s.length() - 1; i >= 0; i--){
        st.push(s[i]);
    }
    int k = 1;
    int i = 1;
    while(!st.empty()){
        if (s[i] == st.top()){
            k++;
            st.pop();
            i++;
        }else{
            cout << s[i-1] << k;
            st.pop();
            k = 1;
            i++;
        }
    }
    return 0;
}