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
const long long maxN = 2e5+5;
const double PI = atan(1)*4;
const int INF = 2e9+5;

ll n, ans;
ll a[maxN];

struct DSU
{
	vector<int> parent, sz;
	DSU(int n) : parent(n), sz(n) {};
	void make_set(int v)
	{
		parent[v] = v;
		sz[v] = 1;
	}
	ll find_set(int v)
	{
		return v == parent[v] ? v : parent[v] = find_set(parent[v]);
	}
	void union_set(ll a, ll b)
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
};

int main()
{
	Hello_i_am_Salmon
}