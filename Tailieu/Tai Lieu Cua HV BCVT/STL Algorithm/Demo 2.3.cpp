#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a[6]={3,2,1,1,4,4};
    cout << count(a,a+6,3);
    return 0;
}
