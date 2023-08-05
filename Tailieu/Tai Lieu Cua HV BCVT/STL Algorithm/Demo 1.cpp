#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int a[5]={3,2,1,5,4};
void quick_sort(int l,int h) {
    if (l>=h) return;
    int i=l,j=h,p=a[(l+h)/2];
    while (i<=j) {
        while (a[i]<p) i++;
        while (a[j]>p) j--;
        if (i<=j) {
            swap(a[i],a[j]);
            i++;j--;
        }
    }
    quick_sort(l,j);
    quick_sort(i,h);
}
int main() {
    //quick_sort(0,4); // Su dung ham quick_sort
	//sort(a,a+5);  //Sap xep tang dan
	//sort(a,a+5,greater<int>());  // Sap xep giam dan
	for (int i=0;i<5;i++) cout << a[i] << " ";
	return 0;
}
