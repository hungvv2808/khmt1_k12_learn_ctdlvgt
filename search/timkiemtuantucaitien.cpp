#include <iostream>
using namespace std;

void nhap(int *&a, int &n){
    cout << "So phan tu mang: ";    cin >> n;
    a = new int [n];
    for(int i=0; i<n; i++){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

int TKTTCT(int *a, int n, int key){
    int i=0;
    a[n]=key;
    while(a[i]!=key)    i++;
    if(i<n) return i;
    else    return 1;
}

int main(){
    int *a; int n;
    nhap(a, n);
    int key;
    cout << "Phan tu can tim: ";    cin >> key;
    int check = TKTTCT(a, n, key);
    if(check == 1)   cout << "Phan tu khong co trong mang." << endl;
    else    cout << "Phan tu nam o vi tri thu " << check+1 << " trong mang." << endl;
    return 0;
}