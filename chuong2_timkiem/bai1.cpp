#include <iostream>
using namespace std;

void nhap(int &n, int *&a){
    cout << "Nhap n = ";    cin >> n;
    while(n<0 || n>100){
        cout << "Vui long nhap n thoa man 0 < n < 100. moi nhap lai!" << endl;
        cout << "n = ";    cin >> n;
    }
    a = new int[n];
    cout << "Nhap mang: " << endl;
    for(int i=0; i<n; i++){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

int TKTTCT(int n, int *a, int k){
    int i=0;    a[n] = k;
    while(a[i]!=k)  i++;
    if(i<n) return i;
    else return -1;
}

int main(){
    int n;  int *a;    nhap(n, a);
    int k;     cout << "Nhap so can tim: ";    cin >> k;
    int search = TKTTCT(n, a, k);
    if(search == -1)    cout << "Phan tu khong co trong mang." << endl;
    else    cout << "Phan tu " << k << " nam o vi tri thu " << search+1 << " trong mang." << endl;
    return 0;
}
