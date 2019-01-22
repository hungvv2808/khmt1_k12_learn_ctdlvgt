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

void xuat(int *a, int n){
    for(int i=0; i<n; i++)  cout << a[i] << " ";
    cout << endl;
}

void sort(int *a, int n){
    for(int i=1; i<n; i++){
        int temp = a[i];
        int j = i - 1;
        while(j>-1 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
    }
}

int main(){
    int *a; int n;
    nhap(a, n);
    sort(a, n);
    cout << "Mang vua nhap sau khi sap tang la: ";  xuat(a, n);
    return 0;
}