#include <iostream>
using namespace std;

void nhap(int *&a, int &n){
    cout << "Tong so phan tu trong mang: "; cin >> n;
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

void sort(int *a, int left, int right){
    if(left < right){
        int local_mid = (left+right)/2;
        int mid = a[local_mid];
        int l = left;   int r = right;
        do{
            while(a[l]<mid) l++;
            while(a[r]>mid) r--;
            if(l<=r){
                int tg = a[l];
                a[l] = a[r];
                a[r] = tg;
                l++;    r--;
            }
        }
        while(l<=r);
        sort(a, left, r);
        sort(a, l, right);
    }
}

int main(){
    int *a; int n;
    nhap(a, n);
    sort(a, 0, 4);
    cout << "Mang vua nhap sau khi sap tang la: ";  xuat(a, n);
    return 0;
}