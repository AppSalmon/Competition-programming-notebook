	/*--------------------------------------------
			Competitive programing
		   Name: Đào Xuân Hoàng Tuấn (Salmon)
	Nothing is impossible, as you as you believe you can do it
			 You can do it!!!
	----------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
#define ll 	long long
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

ll n;
int parent[N], sz[N], ans[N];
bool vis[N];

void make_set(int v)
{
	parent[v] = v;
	sz[v] = 1;
}

int find(int v)
{
	return (parent[v] == v ? v : parent[v] = find(parent[v]));
}

int check(int x, int y)
{
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void bfs_loang(int sx, int sy)
{
	queue<pair<int, int>> q;
	q.push({sx, sy});
	vis[sx][sy] = true;
	while(!q.empty())
	{
		int x = q.front().fi;
		int y = q.front().se;
		q.pop();
		for(int i=0; i<4; i++)
		{
			int u = x + moveX[i];
			int v = y + moveY[i];
			if(check(u, v))
			{
				if(a[u][v] == '.' && !vis[u][v])
				{
					vis[u][v] = true;
					q.push({u, v});
				}
			}
		}
	}
}

int main()
{
	Hello_i_am_Salmon
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++) cin >> a[i][j];
	}
	int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
	int ans = 0;
	if(r1 == r2 && c1 == c2)
	{
		if(check(r2+1, c2) && a[r2+1][c2] == '.') ans = 1;
		if(check(r2-1, c2) && a[r2-1][c2] == '.') ans = 1;
		if(check(r2, c2+1) && a[r2][c2+1] == '.') ans = 1;
		if(check(r2, c2-1) && a[r2][c2-1] == '.') ans = 1;
	}
	else if((r1 == r2 && abs(c1 - c2) == 1) || (abs(r1 - r2) == 1 && c1 == c2))
	{
		// show1
		if(a[r2][c2] == 'X') ans = 1;
		else
		{
			if(check(r2+1, c2) && a[r2+1][c2] == '.') ans = 1;
			else if(check(r2-1, c2) && a[r2-1][c2] == '.') ans = 1;
			else if(check(r2, c2+1) && a[r2][c2+1] == '.') ans = 1;
			else if(check(r2, c2-1) && a[r2][c2-1] == '.') ans = 1;
			else ans = 0;
		}
	}
	else
	{
		show2
		bfs_loang(r1, c1);
		if(!vis[r2][c2])
		{
			if(a[r2][c2] == 'X')
			{
				show1
				if(check(r2+1, c2) && vis[r2+1][c2]) ans = 1;
				else if(check(r2-1, c2) && vis[r2-1][c2]) ans = 1;
				else if(check(r2, c2+1) && vis[r2][c2+1]) ans = 1;
				else if(check(r2, c2-1) && vis[r2][c2-1]) ans = 1;
				else ans = 0;
			}
			else ans = 0;
		}
		else
		{
			int cnt = 0;
			if(check(r2+1, c2) && a[r2+1][c2] == '.') cnt += 1;
			if(check(r2-1, c2) && a[r2-1][c2] == '.') cnt += 1;
			if(check(r2, c2+1) && a[r2][c2+1] == '.') cnt += 1;
			if(check(r2, c2-1) && a[r2][c2-1] == '.') cnt += 1;
			else ans = 0;

			if(cnt >= 2) ans = 1;
			else ans = 0;
		}
	}
	cout << (ans ? "YES" : "NO") << ed;
}

/* Test case 

	


*/