#include <iostream>
#include <algorithm>
using namespace std;
int a[4]={4,3,2,1};
int main() {
    while (prev_permutation(a,a+4)) {
        for (int i=0;i<4;i++) cout << a[i];
        cout << endl;
    }
    return 0;
}
