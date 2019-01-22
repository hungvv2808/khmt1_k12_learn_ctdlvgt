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

void xuat(int*a, int n){
    for(int i=0; i<n; i++)  cout << a[i] << " ";
    cout << endl;
}

void sort(int *a, int n){
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(a[j]>a[j+1]){
                int tg=a[j];    a[j]=a[j+1];    a[j+1]=tg;
            }
        }
    }
}

int TKNP(int *a, int left, int right, int key){
    if(left>right)  return 1;
    else{
        int mid=(left+right)/2;
        if(a[mid]==key) return mid;
        else{
            if(key < a[mid])    return TKNP(a, left, mid-1, key);
            else                return TKNP(a, mid+1, right, key);
        }
    }
}

int main(){
    int *a; int n;
    nhap(a, n);
    sort(a, n);
    cout << "Mang vua nhap sau khi sap tang dan: "; xuat(a, n);
    int key;
    cout << "Phan tu can tim: ";    cin >> key;
    int check = TKNP(a, 0, n-1, key);
    if(check == 1)  cout << "Phan tu khong co trong mang." << endl;
    else    cout << "Phan tu can tim nam o vi tri thu " << check+1 << " trong mang." << endl;
    return 0;
}