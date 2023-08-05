#include <iostream>
#include <algorithm>
using namespace std;
int a[6]={3,2,1,1,4,5};
int main() {
    replace(a,a+6,1,100);
    for (int i=0;i<6;i++) cout << a[i] << " ";
    return 0;
}
