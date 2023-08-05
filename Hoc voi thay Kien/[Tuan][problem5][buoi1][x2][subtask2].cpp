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
const long long Nn = 2500;
const double PI = atan(1)*4;
const int MOD = 1e9 + 7;
const int INF = 2e9+5;
 
	/* --- Code ---- */
set<ll> nen;
struct rao
{
	ll x1, y1, x2, y2;
};

struct cow
{
	ll x, y;
};
rao arr[Nn];
cow c[Nn];

map<ll, ll> check_nen;
ll n, m;
ll a[Nn][Nn];
ll vis[Nn][Nn];
// ll check_huong[Nn][Nn];

ll moveX[] = {0, 0, 1, -1};
ll moveY[] = {1, -1, 0, 0};

ll check_vitri(ll x, ll y)
{
	return (x < Nn && x >= 0) && (y < Nn && y >= 0);
}

ll bfs(ll x1, ll y1, ll cnt)
{
	queue<pair<ll, ll>> Q;
	Q.push({x1, y1});
	// if(a[x1][y1] == 2) cnt++;
	while(!Q.empty())
	{
		ll x = Q.front().fi;
		ll y = Q.front().se;
		Q.pop();
		if(a[x][y] == 2) cnt++;
		vis[x][y] = true;
		for(int i=0; i<4; i++)
		{
			ll u = x + moveX[i];
			ll v = y + moveY[i];
			
			if(check_vitri(u, v) && !vis[u][v] && a[u][v] != 1)
			{
				vis[u][v] = true;
				Q.push({u, v});
			}
		}
	}
	return cnt;
}
 
int main()
{
	Hello_i_am_Salmon
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i].x1 >> arr[i].y1 >> arr[i].x2 >> arr[i].y2;
		nen.insert(arr[i].x1);
		nen.insert(arr[i].y1);
		nen.insert(arr[i].x2);
		nen.insert(arr[i].y2);
	}
	for(int i=0; i<m; i++)
	{
		cin >> c[i].x >> c[i].y;
		nen.insert(c[i].x);
		nen.insert(c[i].y);
	}
	ll it = 1;
	for(auto i : nen)
	{
		check_nen[i] = it;
		it++;
	}

	for(int i=0; i<n; i++)
	{
		ll x1, y1, x2, y2;
		x1 = check_nen[arr[i].x1] * 2;
		y1 = check_nen[arr[i].y1] * 2;
		x2 = check_nen[arr[i].x2] * 2;
		y2 = check_nen[arr[i].y2] * 2;
		if(x1 == x2)
		{
			for(int i=min(y1, y2); i<=max(y2, y1); i++)
			{
				if(check_vitri(x1, i))
					a[x1][i] = 1;
			}
		}
		else if(y1 == y2)
		{
			for(int i=min(x1, x2); i<=max(x1, x2); i++)
			{
				if(check_vitri(i, y1))
					a[i][y1] = 1;
			}
		}
		// check_huong[x1][y1] = !check_huong[x1][y1];
		// check_huong[x2][y2] = !check_huong[x2][y2];
	}
	for(int i=0; i<m; i++)
	{
		ll cx, cy;
		cx = check_nen[c[i].x];
		cy = check_nen[c[i].y];
		a[cx*2][cy*2] = 2;
	}
	vector<ll> ans;
	for(int i=0; i<Nn; i++)
	{
		for(int j=0; j<Nn; j++)
		{
			if(a[i][j] == 2 && !vis[i][j])
			{
				// show1
				ans.pb(bfs(i, j, 0));
			}
		}
	}
	ll endgame = 0;
	for(auto i : ans) endgame = max(endgame, i);
	cout << endgame << ed;
	for(int i=0; i<40; i++)
	{
		for(int j=0; j<40; j++)
		{
			cout << a[i][j];
		}
		cout << ed;
	}
	cout << ed;
	for(int i=0; i<40; i++)
	{
		for(int j=0; j<40; j++)
		{
			cout << vis[i][j];
		}
		cout << ed;
	}
	cout << ed;
	for(auto i : ans) cout << i << _;

}
 
/* Test case 

7 3
0 0 10 0
10 0 10 5
12 5 10 5
10 5 1 5
12 5 12 7
0 7 12 7
0 7 0 0
4 3
6 6
15 3

*/