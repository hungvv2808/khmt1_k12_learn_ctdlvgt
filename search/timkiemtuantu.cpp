#include <iostream>
using namespace std;
void nhap(int *&a, int &n){
    cout << "Tong so phan tu: ";    cin >> n;
    a = new int [n];
    for(int i=0; i<n; i++){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

int TKTT(int *a, int n, int key){
    int i=0;
    while(a[i]!=key && i<n) i++;
    if(i<n) return i;
    else    return 1;
}

int main(){
    int *a;
    int n;
    nhap(a, n);
    int key;
    cout << "Gia tri can tim: ";    cin >> key;
    int check=TKTT(a, n, key);
    if(check==1)    cout << "Phan tu khong co trong mang." << endl;
    else    cout << "Phan tu o vi tri thu " << check+1 << " trong mang." << endl;
    return 0;
}