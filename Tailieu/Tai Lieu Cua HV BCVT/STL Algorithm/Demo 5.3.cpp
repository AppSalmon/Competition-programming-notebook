#include <iostream>
#include <algorithm>
using namespace std;
int a[6]={2,1,1,4,4,6};
int main() {
    sort(a,a+6); //a[]={1,1,2,4,4,6}
    int *p = upper_bound(a,a+6,4);
    if (p-a<6) cout << p-a; else cout << "Khong ton tai";
    return 0;
}
