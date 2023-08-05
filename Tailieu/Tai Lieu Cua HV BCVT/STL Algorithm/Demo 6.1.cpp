#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    cout << "Min(1,2)=" << min(1,2);
    cout << endl;
    cout << "Min(\"acm\",\"acnm\") = " << min((string)"acm",(string)"acnm");
    return 0;
}
