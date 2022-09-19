#include<iostream>

using namespace std;
void nhap(int arr[], int &n){
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void del(int arr[], int &n){
    int k;
    cin >> k ;
    for (int i = k; i < n; i++){
        arr[i] = arr[i+1];
    }
    n--;
}
void xuat(int arr[], int &n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
int main(){
    int n;
    cin >> n;
    int a[10000];
    nhap(a,n);
    del(a,n);
    xuat(a,n);
    return 0;
}
