#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    cout << "Max(1,2)=" << max(1,2);
    cout << endl;
    cout << "Max(\"acm\",\"acnm\") = " << max((string)"acm",(string)"acnm");
    return 0;
}
