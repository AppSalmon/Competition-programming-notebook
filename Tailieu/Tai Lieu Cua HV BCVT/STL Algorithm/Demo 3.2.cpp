#include <iostream>
#include <algorithm>
using namespace std;
int a[]={1,2,3},b[]={4,5,6};
int x=1,y=2;
int main() {
    swap(x,y);  //doi cho 2 bien int
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    swap(a,b);  // doi cho 2 mang int
    cout << "a = { ";
    for (int i=0;i<3;i++) cout << a[i] << " "; cout << "}";
    cout << endl;
    cout << "b = { ";
    for (int i=0;i<3;i++) cout << b[i] << " "; cout << "}";
    return 0;
}
