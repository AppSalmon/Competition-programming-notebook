	/*--------------------------------------------
			Competitive programing
		   Name: Đào Xuân Hoàng Tuấn (Salmon)
	Nothing is impossible, as you as you believe you can do it
			 You can do it!!!
	----------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
#define ll 				long long
#define Hello_i_am_Salmon 		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define print_fix 			cout << fixed << setprecision(20);
#define show3 				cerr << "***" << endl;
#define show2 				cerr << "**" << endl;
#define show1 				cerr << "*" << endl;
#define all(v) 				v.begin(), v.end()
#define sz(t) 				(int) t.size()
#define pb 				push_back
#define se 				second
#define fi 				first
#define ed 				'\n'
#define _ 				" "

const long long N = 1e7+10;
const long long Nn = 1e3+10;
const double PI = atan(1)*4;
const int MOD = 1e9 + 7;
const int INF = 2e9+5;

	/* --- Code ---- */

string sinhbit(string x)
{
	for(int i=sz(x); i>=0; i--)
	{
		if(x[i] == '0')
		{
			x[i] = '1';
			return x;
		}
		else x[i] = '0';
	}
	return "";
}

int main()
{
	Hello_i_am_Salmon
	int n; cin >> n;
	string a = "";
	for(int i=0; i<n; i++)
	{
		a += '0';
	}
	for(int i=0; i<pow(2, n); i++)
	{
		cout << a << ed;
		a = sinhbit(a);
	}
}

/* Test case 

	


*/