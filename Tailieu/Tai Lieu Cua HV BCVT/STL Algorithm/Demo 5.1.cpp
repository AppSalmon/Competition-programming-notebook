#include <iostream>
#include <algorithm>
using namespace std;
int a[6]={3,2,1,1,4,5};
bool comp(int a,int b) {
    return a>b;
}
int main() {
    /* Sap xep giam dan */
    sort(a,a+6);
    int key = 1;
    if (binary_search(a,a+6,key)) cout << key <<" ton tai !!!"; else cout << key << " khong ton tai!!!" ; cout << endl;
    /* Sap xep tang dan */
    sort(a,a+6,comp);
    key = 0;
    if (binary_search(a,a+6,key,comp)) cout << key << " ton tai !!!"; else cout << key << " khong ton tai!!!";
    return 0;
}
