#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n ,t ,k ;
    cin >> n;
    queue<int> st;
    for (int i = 0; i < n; i++){
        cin >> t;
        st.push(t);
    }
    cin >> k;
    while(k--){
        int x = st.front();
        st.pop();
        st.push(x);
   }
   while(!st.empty()){
       cout << st.front() << " ";
       st.pop();
   }
   return 0;
}