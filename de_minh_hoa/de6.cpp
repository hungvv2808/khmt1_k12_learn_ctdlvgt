#include <iostream>
using namespace std;

void select_sort(int *a, int n){
    for(int i=0; i<n-1; i++){
        int Max = i;
        for(int j=i+1; j<n; j++){
            if(a[j] > a[Max])   Max = j;
        }
        if(Max != i){
            int tg = a[Max];
            a[Max] = a[i];
            a[i] = tg;
        }
    }
}

int squence_search(int *a, int n, int key){
    int i = 0;
    while(i<n && a[i] != key)    i++;
    if(i<n) return i;
    else    return 1;
}

int main(){
    int a[] = {30, 18, 15, 27, 46, 50, 32};
    int n = 7;
    select_sort(a, n);
    cout << "Day so X sau khi sap xep giam dan la: ";
    for(int i=0; i<n; i++)  cout << a[i] << " ";
    cout << endl;
    int check = squence_search(a, n, 27);
    if(check == 1)  cout << "Phan tu 27 khong xuat hien trong day X." << endl;
    else    cout << "Phan tu 27 nam o vi tri thu " << check+1 << " trong day X." << endl;
    return 0;
}