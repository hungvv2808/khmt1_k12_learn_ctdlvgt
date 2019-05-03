#include <iostream>
using namespace std;

/*Cau1: De Quy*/

//dem so lan x xuat hien trong day

//dinh nghia tinh 2^n voi n>=0
int luyThua(int n){
  if(n==0)  return 1;
  else      return 2*luyThua(n-1);
}

//uoc chung lon nhat cua 2 so
int ucln(int a, int b){
  if(a==b)  return a;
  else{
    if(a>b) return ucln(a-b, b);
    else    return ucln(a, b-a);
  }
}

//dem so chu so cua n
int demChuSo(int n){
  if(n<10)  return 1;
  else      return 1+demChuSo(n/10);
}

//giai thua
int giaiThua(int n){
  if(n==0)  return 1;
  else      return n*giaiThua(n-1);
}

//tong n phan tu trong day x
int tongPhanTu(int *a, int n){
  if(n==1)  return a[0];
  else      return tongPhanTu(a, n-1)+a[n-1];
}

// phan tu Fibonaci
int phanTuFibonaci(int n){
  if(n<=0)  return 0;
  else      return 2*n+phanTuFibonaci(n-1);
}

/*Cau4: Sap Xep*/

//sap noi bot
void sapNoiBot(int *a, int n){
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(a[j]>a[j+1]){
                int tg = a[j];  a[j] = a[j+1];  a[j+1] = tg;
            }
        }
    }
}

//sap chon
void sapChon(int *a, int n){
    for(int i=0; i<n-1; i++){
        int Min = i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[Min]) Min = j;
        }
        if(Min != i){
            int tg = a[Min];    a[Min] = a[i];  a[i] = tg;
        }
    }
}

//sap chen
void sapChen(int *a, int n){
    for(int i=1; i<n; i++){
        int temp = a[i];
        int j = i - 1;
        while(j>-1 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

// quick sort
void sapPhanDoan(int *a, int left, int right){
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
        sapPhanDoan(a, left, r);
        sapPhanDoan(a, l, right);
    }
}
