#include <iostream>
#include <algorithm>
using namespace std;
int a[6]={3,2,1,1,4,5};
bool comp(int a,int b) {
    return a>b;
}
int main() {
    sort(a,a+6);
    cout << "Sap xep tang dan:" << endl;
    for (int i=0;i<6;i++) cout << a[i] << " "; cout << endl;

    sort(a,a+6,comp);
    cout << "Sap xep giam dan:" << endl;
    for (int i=0;i<6;i++) cout << a[i] << " "; cout << endl;
    return 0;
}
