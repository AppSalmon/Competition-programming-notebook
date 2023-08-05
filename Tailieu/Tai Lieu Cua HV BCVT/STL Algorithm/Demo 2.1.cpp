#include <iostream>
#include <algorithm>
using namespace std;
int a[5]={3,2,1,4,5};
void func(int x) {
    cout << x*x << endl;
}
int main() {
    for_each(a,a+5,func);
    return 0;
}
