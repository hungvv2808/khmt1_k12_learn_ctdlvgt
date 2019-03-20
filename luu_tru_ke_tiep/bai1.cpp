#include <iostream>
#include "string.h"
#include "iomanip"
#define MAX 100
using namespace std;

struct canBo{
    char maCanBo[30];
    char hoTen[30];
    float tuoiDoi, luong;
};

struct list{
    int cout;
    canBo E[MAX];
};

canBo L;

void nhap(list &L){
    for(int i=0; i<MAX; i++){
        cout << "STT " << i+1 << endl;
        cout << "Ma can bo: ";  cin.getline(L.E[i].maCanBo, 100);
        if(strcmp(L.E[i].maCanBo, "stop")==0){
            cout << "Dung chuong trinh..." << endl;
            return;
        }
        cout << "Ho ten: "; cin.getline(L.E[i].hoTen, 100);
        cout << "Tuoi doi: ";   cin >> L.E[i].tuoiDoi;  cin.ignore(1);
        cout << "Luong: ";  cin >> L.E[i].luong;    cin.ignore(1);
        L.cout++;
    }
}

void xuat(list L){
    cout << setw(20) << "MA CAN BO" << setw(20) << "HO TEN" << setw(20) << "TUOI DOI" << setw(20) << "LUONG" << endl;
    for(int i=0; i<L.cout; i++){
        cout << setw(20) << L.E[i].maCanBo << setw(20) << L.E[i].hoTen << setw(20) << L.E[i].tuoiDoi << setw(20) << L.E[i].luong << endl;
    }
    cout << endl;
}

int search456(list L, char *ma){
    for(int i=0; i<L.cout; i++){
        if(strcmp(L.E[i].maCanBo, ma)==0)  return i+1;
    }
    return 0;
}

void xoaCanBo(list &L){
    int viTri = search456(L, "456");    cout << "i = " << viTri << endl;
    for(int i=viTri-1; i<=L.cout; i++)     L.E[i] = L.E[i+1];
    L.cout--;
}

int main(){
    list L;
    nhap(L);
    xuat(L);
    xoaCanBo(L);    cout << "Mang sau khi xoa can bo co ma 456" << endl << endl;    xuat(L);
    cout << "Cac can bo co tuoi doi nho hon 40" << endl;
    cout << setw(20) << "MA CAN BO" << setw(20) << "HO TEN" << setw(20) << "TUOI DOI" << setw(20) << "LUONG" << endl;
    for(int i=0; i<L.cout; i++){
        if(L.E[i].tuoiDoi <= 40)
            cout << setw(20) << L.E[i].maCanBo << setw(20) << L.E[i].hoTen << setw(20) << L.E[i].tuoiDoi << setw(20) << L.E[i].luong << endl;
    }
    return 0;
}