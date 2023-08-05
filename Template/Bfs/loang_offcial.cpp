	/*--------------------------------------------
			Competitive programing
		   Name: Đào Xuân Hoàng Tuấn (Salmon)
	Nothing is impossible, as you as you believe you can do it
			 You can do it!!!
	----------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define Hello_i_am_Salmon       ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define print_fix           cout << fixed << setprecision(20);
#define show(x)             cerr << #x << " -> " << x << endl;
#define show3               cerr << "***" << endl;
#define show2               cerr << "**" << endl;
#define show1               cerr << "*" << endl;
#define all(v)              v.begin(), v.end()
#define sz(t)               (int) t.size()
#define pb              push_back
#define se              second
#define fi              first
#define el              endl
#define ed              '\n'
#define _               " "

void debug_out() {cout << '\n';}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
	cout << H << ' ';
	debug_out(T...);
}
#define fix(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)

const long long N = 1e6+10;
const long long Nn = 1e3+10;
const double PI = atan(1)*4;
const int MOD = 1e9 + 7;
const ll INF = 2e15+5;

	/* --- Code ---- */

ll moveX[] = {0, 1, -1, 0, 1, -1, -1, 1};
ll moveY[] = {1, 0, 0, -1, 1, -1, 1, -1};
bool vis[Nn][Nn];
char a[Nn][Nn];
ll n, m;
bool check_id(ll x, ll y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}

vector<pair<ll, ll>> lo;

void bfs(ll sx, ll sy)
{
	queue<pair<ll, ll>> Q;
	vis[sx][sy] = true;
	Q.push({sx, sy});
	while(!Q.empty())
	{
		ll x = Q.front().fi;
		ll y = Q.front().se;
		lo.pb({x, y});
		// fix(sz(lo));
		Q.pop();
		for(int i=0; i<8; i++)
		{
			ll u = x + moveX[i];
			ll v = y + moveY[i];
			if(!check_id(u, v))
			{
				// show2
				continue;
			}
			if(a[u][v] == '*' && !vis[u][v])
			{
				// show1

				vis[u][v] = true;
				Q.push({u, v});
				// a[u][v] = '.';
			}
		}
	}

}

int main()
{
	Hello_i_am_Salmon
	int t; cin >> t;
	while(t--)
	{
		cin >> n >> m;
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				cin >> a[i][j];
			}
		}
		ll endgame = 1;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(a[i][j] == '*' && !vis[i][j])
				{
					bfs(i, j);
					if(sz(lo) != 3) endgame = 0;
					else
					{
						sort(all(lo));
						ll x1 = lo[0].fi;
						ll y1 = lo[0].se;
						ll x2 = lo[1].fi;
						ll y2 = lo[1].se; 
						ll x3 = lo[2].fi;
						ll y3 = lo[2].se;
						ll f = 0;
						if(x2 == x1+1 && y2 == y1 && x3 == x1+1 && y3 == y1+1) f = 1; 
						if(x2 == x1+1 && y2 == y1-1 && x3 == x1+1 && y3 == y1) f = 1; 
						if(x2 == x1 && y2 == y1+1 && x3 == x1+1 && y3 == y1+1) f = 1; 
						if(x2 == x1 && y2 == y1+1 && x3 == x1+1 && y3 == y1) f = 1; 
						if(!f) endgame = 0;
					}
					lo.clear();
				}
			}
		}
		cout << (endgame ? "YES" : "NO") << ed;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				vis[i][j] = 0;
			}
		}

	}
}

/* Test case 

1
2 3
*..
.**

*/