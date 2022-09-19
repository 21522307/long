#include <iostream>

using namespace std;

int a[50][50];
void drawSpiral(int n){
    int value = 1;
    int T = 0, B = n - 1, L = 0, R = n - 1; // T: top, B: bottom, L: left, R: right
    while(T <= B && L <= R){
        for(int i = L; i <= R; i++) // draw top side
        {
            a[T][i] = value++;
        }
    T++;
        for(int i = T; i <= B; i++) // draw right side
        {
            a[i][R] = value++;
        }
    R--;
        for(int i = R; i >= L; i--) // draw bottom side
        {
            a[B][i] = value++;
        }
    B--;
        for(int i = B; i >= T; i--) // draw left side
        {
        a[i][L] = value++;
        }
    L++;
    }
   for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int n;
    cin >> n;
    drawSpiral(n);
    return 0;
}