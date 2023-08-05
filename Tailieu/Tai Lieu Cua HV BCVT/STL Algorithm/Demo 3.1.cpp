#include <iostream>
#include <algorithm>
using namespace std;
int a[6]={3,2,1,1,4,4};
int b[10]={9,8};
int main() {
    copy(a,a+6,b+2);
    for (int i=0;i<8;i++) cout << b[i] << " ";
    return 0;
}
