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
#define show(x)				cerr << #x << " -> " << x << endl;
#define show3 				cerr << "***" << endl;
#define show2 				cerr << "**" << endl;
#define show1 				cerr << "*" << endl;
#define all(v) 				v.begin(), v.end()
#define sz(t) 				(int) t.size()
#define pb 				push_back
#define se 				second
#define fi 				first
#define el 				endl
#define ed 				'\n'
#define _ 				" "

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

vector<pair<ll, ll>> adj[N];
ll pre[N];
ll n, m;

void dijkstra(ll s)
{
	vector<ll> d(n+1, INF); // mang luu khoang cach duong di
	d[s] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
	// {khoang cach, dinh}
	Q.push({0, s});
	while(!Q.empty())
	{
		// show1
		pair<ll, ll> temp = Q.top(); Q.pop();
		ll u = temp.se, kc = temp.fi;
		if(kc > d[u]) continue;
		for(auto it : adj[u])
		{
			ll v = it.fi, w = it.se;
			if(d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				Q.push({d[v], v});
				pre[v] = u;
			}
		}
	}
	vector<ll> path;
	ll endd = n;
	if(d[endd] == INF) cout << -1 << ed;
	else
	{
		while(1)
		{
			path.pb(endd);
			if(endd == 1) break;
			endd = pre[endd];
		}
		reverse(all(path));
		for(auto it : path) cout << it << _;
		cout << ed;
	}
}

int main()
{
	Hello_i_am_Salmon
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		ll x, y, z; cin >> x >> y >> z;
		adj[x].pb({y, z});
		adj[y].pb({x, z});
	}
	dijkstra(1);
}

/* Nhan xet 



*/
