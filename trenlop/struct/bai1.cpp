#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

#define MAX n
struct SV{
    char maSV[30], hoTen[30];
    int namSinh;
    float diem;
};
struct List{
    int dem;
    SV *a = new SV[n];
}

bool checkFull(SV *a, int n){
    if()
}

void nhap(SV *&a, int n){
    for(int i=0; i<n; i++){
        cout << endl << "STT" << i+1 << endl;
        cout << "Ma sinh vien: ";   cin.getline(a->maSV, 30);
        cout << "Ho ten: ";         cin.getline(a->hoTen, 30);
        cout << "Nam sinh: ";       cin >> a->namSinh;
        cout << "Diem: ";           cin >> a->diem;
        cin.ignore(1);
    }
}

void xuat(SV *a, int n){
    cout << setw(20) << "MaSV" << setw(15) << "HoTen" << setw(15) << "NamSinh" << setw(15) << "Diem" << endl;
    for(int i=0; i<n; i++){
        cout << setw(20) << a->maSV << setw(15) << a->hoTen << setw(15) << a->namSinh << setw(15) << a->diem << endl;
    }
}

int main(){
    int n;  cout << "Tong so sinh vien: ";  cin >> n;
    SV *a = new SV[n];  cin.ignore(1);
    nhap(a, n);
    cout << "Danh sach vua nhap la" << endl;
    xuat(a, n);
    return 0;
}