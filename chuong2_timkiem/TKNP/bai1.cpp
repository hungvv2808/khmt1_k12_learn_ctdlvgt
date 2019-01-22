#include <iostream>

using namespace std;

void input(int *&a, int &n){
    cout << "Nhap n = "; cin >> n;
    while(n<0 || n>100){
        cout << "Nhap vao n thoa man dieu kien 0 < n < 100, moi nhap lai." << endl;
        cout << "n = "; cin >> n;
    }
    cout << endl << "Nhap mang: " << endl;
    a = new int[n];
    for(int i=0; i<n; i++){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void output(int*a, int n){
    for(int i=0; i<n; i++)  cout << a[i] << ", ";
    cout << endl;
}

// sap noi bot
/*void sort_noi_bot(int *a, int n){
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            if(a[j]>a[j+1]){
                int tg=a[j];    a[j]=a[j+1];    a[j+1]=tg;
            }
        }
    }
}*/

//sap chon
void select_sort(int *a, int n){
    for(int i=0; i<n-1; i++){
        int Min = i;
        for(int j=i+1; j<n; j++){
            if(a[Min]>a[j])     Min = j;
            if(Min != i){
                int tg = a[Min];    a[Min] = a[i];  a[i] = tg;
            }
        }
    }
}

//sap chen
void insert_sort(int *a, int n){
    for(int i=1; i<n; i++){
        int cache = a[i];
        j = i -1;
        while(j>-1 && a[j]>cache){
            a[j+1] = a[j];
            j--;
        }
    }
}

//sap phan doan
void quick_sort(int *a, int left, int right){
    if(left < right){
        int k = (left)
    }
}

int bit_search(int *a, int left, int right, int search){
    if(left > right)    return -1;
    else{
        int mid=(left+right)/2;
        if(a[mid]==search)  return mid;
        else{
            if(a[mid]<search)   return bit_search(a, mid+1, right, search);
            else    return bit_search(a, left, mid-1, search);
        }
    }
}

int main(){
    int *a; int n;
    input(a, n);
    //sort_noi_bot(a, n);
    select_sort(a, n);
    cout << "Mang sau khi sap xep: ";   output(a, n);
    int search;     cout << endl << "Nhap vao gia tri can tim: ";   cin >> search;
    int local = bit_search(a, 0, n-1, search);
    if(local==-1)   cout << "Phan tu khong co trong mang." << endl;
    else    cout << "Phan tu " << search << " nam o vi tri thu " << local+1 << " trong mang." << endl;
    return 0;
}
