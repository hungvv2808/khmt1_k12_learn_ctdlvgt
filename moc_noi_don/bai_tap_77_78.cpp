//masv, hoten, namsinh, diemtk

#include <iostream>
#include "string.h"
#include "iomanip"
#include "stdio.h"
using namespace std;

#define MAX 100;
struct SV{
    char maSV[30], hoDem[30], ten[30];
    int namSinh;
    float diem;
};
struct Node{
    SV infor;
    Node *next;
};
typedef Node *TRO;

void khoiTao(TRO &L){
    L=NULL;
}

int check(TRO L){
    return L==NULL;
}

void nhapDS(TRO &L){
    khoiTao(L);
    SV X;
    TRO Q, P;
    int i=1;

    do{
        cout << "STT " << i << endl;
        cout << "Ma sinh vien: ";   cin.getline(X.maSV, 30);
        if(strcmp(X.maSV, "***")==0){
            cout << "program stop !!!" << endl;
            return;
        }
        cout << "Ho dem: "; cin.getline(X.hoDem, 30);
        cout << "Ten: ";    cin.getline(X.ten, 30);
        cout << "Nam sinh: ";   cin >> X.namSinh;
        cout << "Diem tong ket: ";  cin >> X.diem;
        cin.ignore(1);
        P = new(Node);
        P->infor = X;
        P->next = NULL;
        if(L == NULL)    L = P;
        else    Q->next = P;
        Q = P;
        i++;
    }   while(1);

/*int n = MAX)
for(int i=0;i<n;i++){
    cout << "STT " << i << endl;
    cout << "Ma sinh vien: ";   cin.getline(X.maSV, 30);
    cout << "Ho dem: "; cin.getline(X.hoDem, 30);
    cout << "Ten: ";    cin.getline(X.ten, 30);
    cout << "Nam sinh: ";   cin >> X.namSinh;
    cout << "Diem tong ket: ";  cin >> X.diem;
    cin.ignore(1);
    P = new(Node);
    P->infor = X;
    P->next = NULL;
    if(L = NULL)    L = P;
    else    Q->next = P;
    Q = P;
  }*/
}

void xuatDS(TRO L){
    if(L != NULL){
        cout << setw(15) << "MA SV" << setw(15) << "HO DEM" << setw(15) << "TEN" << setw(15) << "NAM SINH" << setw(15) << "DIEM" << endl;
        TRO Q = L;
        while(Q != NULL){
            SV X = Q->infor;
            cout << setw(15) << X.maSV << setw(15) << X.hoDem << setw(15) << X.ten << setw(15) << X.namSinh << setw(15) << X.diem << endl;
            Q = Q->next;
        }
    }
    else{
        cout << "Danh sach rong ..." << endl;
        return;
    }
}

int doDai(TRO L){
    int n = 0;
    TRO Q = L;
    while(Q != NULL){
        Q = Q->next;
        n++;
    }
    return n;
}

void xoaSV1(TRO &L){
    if(L != NULL){
        TRO Q = L;
        L = L->next;
        delete Q;
        cout << "Danh sach sau khi xoa SV dau tien" << endl;    xuatDS(L);
        return;
    }
    cout << "Danh sach rong, khong the thuc hien xoa." << endl;
}

TRO timSV(TRO L, char *ma){
    TRO Q = L;
    while(Q!=NULL && strcmp(Q->infor.maSV, ma)!=0)  Q = Q->next;
    return Q;
}

void xoaSV(TRO &L, TRO T){
    TRO Q;
    if(T == L)  L = T->next;
    else{
        Q = L;
        while(Q->next != T) Q = Q->next;
        Q->next = T->next;
    }
    delete T;
}

void xoa_sv8089(TRO &L){
    TRO T = timSV(L, "sv8089");
    if(T == NULL){
        cout << "Khong co ma sinh vien sv8089." << endl;
        return;
    }
    xoaSV(L, T);
    cout << "Danh sach sau khi xoa sinh vien 8089" << endl;
    xuatDS(L);
}

void firstAdd(TRO &L, SV X){
    TRO P;
    P = new(Node);
    P->infor = X;
    P->next = L;
    L = P;
}

void insert(TRO &L, TRO Q, SV X){
    TRO P;
    P = new(Node);
    P->infor = X;
    P->next = Q->next;
    Q->next = P;
}

void boSung(TRO &L){
    int k;
    SV X;
    do{
        cout << "Nhap vi tri bo sung: ";    cin >> k;
    }   while(k<1 || k>doDai(L));
    cout << "Nhap thong tin sinh vien can bo sung: " << endl;
    do{
        cin.ignore(1);
        cout << "Ma sinh vien: ";   cin.getline(X.maSV, 30);
        cin.ignore(1);
        cout << "Ho dem: "; cin.getline(X.hoDem, 30);
        cin.ignore(1);
        cout << "Ten: ";    cin.getline(X.ten, 30);
        cin.ignore(1);
        cout << "Nam sinh: ";   cin >> X.namSinh;
        cout << "Diem tong ket: ";  cin >> X.diem;
        cin.ignore(1);
        if(strcmp(X.maSV, "***")==0)    cout << "Ma sinh vien phai khac '***', moi nhap lai: " << endl;
    }   while(strcmp(X.maSV, "***")==0);
    if(k==1)    firstAdd(L, X);
    else{
        TRO Q = L;
        int d = 1;
        while(d < k-1){
            d++;
            Q = Q->next;
        }
        insert(L, Q, X);
    }
    cout << "Danh sach vua bo sung: " << endl;
    xuatDS(L);
}

void hienThiSvTenDoanh(TRO L){
    if(L == NULL){
        cout << "Danh sach rong." << endl;
        return;
    }
    TRO Q = L;
    int i = 0;
    cout << setw(15) << "MA SV" << setw(15) << "HO DEM" << setw(15) << "TEN" << setw(15) << "NAM SINH" << setw(15) << "DIEM" << endl;
    while(Q != NULL){
    SV X = Q->infor;
    if(strcmp(X.ten, "Doanh") == 0){
        cout << setw(15) << X.maSV << setw(15) << X.hoDem << setw(15) << X.ten << setw(15) << X.namSinh << setw(15) << X.diem << endl;
        i++;
    }
    Q = Q->next;
  }
  if(i==0)  cout << "Khong co sinh vien ten Doanh trong danh sach." << endl;
}

void sapXepGiam(TRO &L){
    TRO P, Q, R;
    P = L;
    while(P->next != NULL){
        R = P;
        Q = P->next;
        while(Q != NULL){
        if(Q->infor.diem > R->infor.diem)   R =Q;
        Q = Q->next;
        }
        SV tg = P->infor;
        P->infor = R->infor;
        R->infor = tg;
        P = P->next;
    }
    cout << "Danh sach sau khi duoc sap xem giam dan." << endl;
    xuatDS(L);
}

void boSungTratTu(TRO &L){
    SV X;
    cout << "Nhap thong tin sinh vien can bo sung" << endl;
    do{
        cin.ignore(1);
        cout << "Ma sinh vien: ";   cin.getline(X.maSV, 30);
        cin.ignore(1);
        cout << "Ho dem: "; cin.getline(X.hoDem, 30);
        cin.ignore(1);
        cout << "Ten: ";    cin.getline(X.ten, 30);
        cin.ignore(1);
        cout << "Nam sinh: ";   cin >> X.namSinh;
        cout << "Diem tong ket: ";  cin >> X.diem;
        cin.ignore(1);
        if(strcmp(X.maSV, "***")==0)    cout << "Ma sinh vien phai khac '***', moi nhap lai: " << endl;
    }   while(strcmp(X.maSV, "***")==0);
    if(X.diem >= L->infor.diem) firstAdd(L, X);
    else{
        TRO Q = L;
        TRO T = Q->next;
        while(T != NULL && T->infor.diem > X.diem){
            Q = Q->next;
            T = T->next;
        }
        insert(L, Q, X);
    }
    cout << "Danh sach sau khi bo sung" << endl;
    xuatDS(L);
}

int main()
{
    TRO L;
    cout << "DANH SACH SINH VIEN" << endl;
    nhapDS(L);
    cout << "--------------------------------------------------------------------------" << endl;
    cout << endl << setw(50) << "DANH SACH VUA NHAP" << endl << endl;
    xuatDS(L);
    cout << "--------------------------------------------------------------------------" << endl;
    cout << endl << "Do dai danh sach la: " << doDai(L) << endl << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    xoaSV1(L);
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    xoa_sv8089(L);
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    boSung(L);
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    hienThiSvTenDoanh(L);
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    sapXepGiam(L);
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    boSungTratTu(L);
    cout << endl;
    return 0;
}
