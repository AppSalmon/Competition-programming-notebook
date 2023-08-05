/*--------------------------------------------
			Competitive programing
		   Name: Đào Xuân Hoàng Tuấn (Salmon)
	Nothing is impossible, as you as you believe you can do it
			 You can do it!!!
	----------------------------------------------*/
 
#include <bits/stdc++.h>
using namespace std;
#define ll 						long long
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
 
const long long N = 1e6+10;
const long long Nn = 1e3+10;
const double PI = atan(1)*4;
const int MOD = 1e9 + 7;
const int INF = 2e9+5;
 
	/* --- Code ---- */
 
set<pair<ll, ll>> ok;
ll moveX[] = {0, 0, 1, 1, -1, -1, 1, -1};
ll moveY[] = {1, -1, 0, -1, 1, 0, 1, -1};
map<pair<ll, ll>, ll> dp;
ll x1, y1, x2, y2;
 
ll bfs()
{
	queue<pair<ll, ll>> Q;
	Q.push({x1, y1});
	dp[{x1, y1}] = 1;
	while(!Q.empty())
	{
		pair<ll, ll> x = Q.front();
		Q.pop();
		if(x.fi == x2 && x.se == y2) return dp[x] - 1;
		pair<ll, ll> temp;
		for(int i=0; i<8; i++)
		{
			temp.fi = x.fi + moveX[i];
			temp.se = x.se + moveY[i];
			if(ok.find(temp) != ok.end())
			{
				if(dp[temp] == 0)
				{
					dp[temp] = dp[x] + 1;
					Q.push(temp);
				}
			}
		}
	}
	return -1;
}
 
int main()
{
	Hello_i_am_Salmon
	int t; cin >> t;
	while(t--)
	{	
		cin >> x1 >> y1 >> x2 >> y2;
		ll m; cin >> m;
		while(m--)
		{
			ll r, a, b; cin >> r >> a >> b;
			for(int i=a; i<=b; i++)
			{
				ok.insert({r, i});
			}
		}
		ll ans = bfs();
		cout << ans << ed;
		dp.clear();
		ok.clear();
	}
}
 
/* Test case 

2
0 6 2 2
3
0 6 6
1 6 10
2 2 5
1 1 2 10
2
1 1 4
2 8 10

	
 
 
*/