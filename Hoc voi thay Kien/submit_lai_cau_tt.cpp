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
const int INF = 1e9+5;
 
	/* --- Code ---- */
 
ll pc = 0;
ll zero = 0;
ll sum = 0;
ll k;
ll test;
 
bool check()
{
	if(sum - pc < k)
	{
		zero += (sum - pc);
		return 0;
	}
	return 1;
}
 
int main()
{
	Hello_i_am_Salmon
	ll n, t; cin >> n >> t;
	vector<pair<ll, ll>> two_ans;
	cin >> k;
	ll l = 1, r = n;
	test = 1;
	while(true)
	{
		ll mid = (l + r) / 2;
		if(test == 1)
		{
			two_ans.pb({l, mid});
			if(sz(two_ans) > 1 && two_ans[sz(two_ans)-1] == two_ans[sz(two_ans)-2])
			{
				// show1
				cout << '?' << _ << two_ans[sz(two_ans)-1].fi << _ << two_ans[sz(two_ans)-1].fi << endl;
				// cout.flush();
				cin >> pc;
				if(!pc)
				{
					cout << '!' << _ << two_ans[sz(two_ans)-1].fi << endl;
				}
				else cout << '!' << _ << two_ans[sz(two_ans)-1].se << endl;
				break;
			}	
			cout << '?' << _ << l << _ << mid << endl;
			// cout.flush();
			cin >> pc;
			sum = mid - l + 1;
		}
		else
		{
			two_ans.pb({mid, r});
			if(sz(two_ans) > 1 && two_ans[sz(two_ans)-1] == two_ans[sz(two_ans)-2])
			{
				// show1
				cout << '?' << _ << two_ans[sz(two_ans)-1].fi << _ << two_ans[sz(two_ans)-1].fi << endl;
				// cout.flush();
				cin >> pc;
				if(!pc)
				{
					cout << '!' << _ << two_ans[sz(two_ans)-1].fi << endl;
				}
				else cout << '!' << _ << two_ans[sz(two_ans)-1].se << endl;
				break;
			}	
			cout << '?' << _ << mid << _ << r << endl;
			// cout.flush();
			cin >> pc;
			sum = r - mid + 1;
		}
 
 
 
		if(check())
		{
			test = 1;
			r = mid;
		}
		else
		{
			test = 0;
			l = mid;
		}
	}
}
/* Test case 
 
 
 
 
*/