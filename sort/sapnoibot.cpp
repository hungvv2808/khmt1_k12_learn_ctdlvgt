#include <iostream>
using namespace std;

void nhap(int *&a, int &n){
    cout << "Tong so phan tu mang: ";   cin >> n;
    a = new int [n];
    for(int i=0; i<n; i++){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void sort(int *a, int n){
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(a[j]>a[j+1]){
                int tg = a[j];  a[j] = a[j+1];  a[j+1] = tg;
            }
        }
    }
}

void xuat(int *a, int n){
    for(int i=0; i<n; i++)  cout << a[i] << " ";
    cout << endl;
}

int main(){
    int *a; int n;
    nhap(a, n);
    sort(a, n);
    cout << "Mang sau khi sap tang la: ";   xuat(a, n);
    return 0;
}