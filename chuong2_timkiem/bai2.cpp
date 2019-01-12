#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class HS{
    string mahs, hoten;
    int namsinh;
    float diemtb;
public:
    void nhap(){
        cout << "Ma hoc sinh: ";        getline(cin, mahs);
        cout << "Ho ten: ";             getline(cin, hoten);
        cout << "Nam sinh: ";           cin >> namsinh;
        cout << "Diem trung binh: ";    cin >> diemtb;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << mahs << setw(20) << hoten << setw(10) << namsinh << setw(10) << diemtb << endl;
    }
    friend int searchname(int n, HS *a, string name);
};

int searchname(int n, HS *a, string name){
    int i=0;    a[n-1].hoten = name;
    while(a[i].hoten != name) i++;
    if(i<n) return i;
    else    return -1;
}

int main(){
    int n;     cout << "Nhap vao tong so hoc sinh: ";   cin >> n;
    while(n<0 || n>100){
        cout << "Yeu cau nhap vao tong so hoc sinh thoa man dieu kien 0 < n < 100, moi nhap lai!" << endl;
        cout << "n = ";    cin >> n;
    }
    cin.ignore(1);
    HS *a = new HS[n];
    cout << "Nhap danh sach:" << endl;
    for(int i=0; i<n; i++){
        cout << "STT" << i+1 << endl;
        a[i].nhap();
    }
    cout << setw(40) << "DANH SACH BAN VUA NHAP" << endl;
    cout << setw(20) << "MAHOCSINH" << setw(20) << "HOTEN" << setw(10) << "NAMSINH" << setw(10) << "DIEMTB" << endl;
    for(int i=0; i<n; i++){
        a[i].xuat();
    }

    string name;
    cout << "Nhap vao ten can tim: ";   getline(cin, name);
    int timkiem = searchname(n, a, name);
    if(timkiem == -1)   cout << "Ten ban vua nhap khong co trong danh sach." << endl;
    else{
        cout << endl << setw(40) << "KET QUA TIM KIEM" << endl;
        cout << setw(20) << "MAHOCSINH" << setw(20) << "HOTEN" << setw(10) << "NAMSINH" << setw(10) << "DIEMTB" << endl;
        a[timkiem].xuat();
    }
    return 0;
}
