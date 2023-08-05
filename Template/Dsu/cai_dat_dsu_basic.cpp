/*-------------------------------------------------------
		Competitive programing
	   Name: Đào Xuân Hoàng Tuấn (Salmon)
Nothing is impossible, as you as you believe you can do it
		 You can do it!!!
-------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Hello_i_am_Salmon ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define print_fix cout << fixed << setprecision(20);
#define show3 cerr << "***" << endl;
#define show2 cerr << "**" << endl;
#define show1 cerr << "*" << endl;
const long long maxN = 2e5+7;
const double PI = atan(1)*4;
const int INF = 2e9+5;

//https://codeforces.com/contest/1249/problem/B1
//https://codeforces.com/contest/1249/problem/B2

ll parent[maxN];
ll sz[maxN];

void make_set(ll v)
{
	parent[v] = v;
	sz[v] = 1;
}

ll find_set(ll v)
{
	if(v == parent[v]) return v;
	ll p = find_set(parent[v]);
	parent[v] = p;
	return p;
}

void union_sets(ll a, ll b)
{
	a = find_set(a);
	b = find_set(b);
	if(a != b)
	{
		if(sz[a] < sz[b]) swap(a, b);
		parent[b] = a;
		sz[a] += sz[b];
	}
}

int main()
{
	Hello_i_am_Salmon
	int t; cin >> t;
	while(t--)
	{
		ll n; cin >> n;
		ll a[n+1];
		for(int i=1; i<=n; i++) cin >> a[i];
		for(int i=1; i<=n; i++)
		{
			make_set(i);
		}
		for(int i=1; i<=n; i++)
		{
			union_sets(i, a[i]);
		}
		for(int i=1; i<=n; i++)
		{
			find_set(i);
		}
		cout << endl;
		for(int i=1; i<=n; i++)
		{
			cout << sz[parent[i]] << " "; 
		}
		cout << endl;
	}
	
}