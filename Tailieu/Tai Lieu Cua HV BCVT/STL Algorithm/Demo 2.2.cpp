#include <iostream>
#include <algorithm>
using namespace std;
int a[6]={3,2,1,1,4,5};
int main() {
    int key;
    cout << "Nhap phan tu can tim: "; cin >> key;
    int *x = find(a,a+6,key);
    if (x!=a+6) cout << "Phan tu can tim xuat hien o vi tri thu " << x - a;
    else cout << "Khong tim thay";
    return 0;
}
