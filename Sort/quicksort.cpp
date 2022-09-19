#include<iostream>

using namespace std;

void nhap(int a[], int n){
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}
void quicksort(int a[], int l ,int r){
    int m = a[(l+r)/2];
    int i = l, j = r;
    while (i < j){
        while (a[i] < m){
            i++;
        }
        while  (a[j] > m){
            j--;
        }
        if (i <= j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if (i < r){
        quicksort(a, i, r);
    }
    if (j > l){
        quicksort(a, l, j);
    }
}
void xuat(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int a[1000];
    int n;
    cin >> n;  
    nhap(a, n);
    quicksort(a, 0, n-1);
    xuat(a, n);
    return 0;
}
