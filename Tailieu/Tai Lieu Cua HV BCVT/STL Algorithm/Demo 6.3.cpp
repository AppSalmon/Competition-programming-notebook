#include <iostream>
#include <algorithm>
using namespace std;
int a[4]={1,2,3,4};
int main() {
    while (next_permutation(a,a+4)) {
        for (int i=0;i<4;i++) cout << a[i];
        cout << endl;
    }
    return 0;
}
