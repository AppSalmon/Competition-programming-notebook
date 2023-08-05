/*-------------------------------------------------------
		Competitive programing
	   Name: Đào Xuân Hoàng Tuấn (Salmon)
Nothing is impossible, as you as you believe you can do it
		 You can do it!!!
-------------------------------------------------------*/
#include <bits/stdc++.h>
// #include "Salmon_debug_with_tourist.h"
using namespace std;
#define ll long long
#define Hello_i_am_Salmon ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define show1 cerr << "*" << endl;
#define show2 cerr << "**" << endl;
#define show3 cerr << "***" << endl;
const int INF = 1e9+5;
const long long maxN = 110;
int n;
char a[maxN][maxN];
int dp[maxN][maxN];
bool visit[maxN][maxN];
queue<pair<int, int>> q;


int inside(int x, int y)
{
	if(x >= 1 && x <= n && y >= 1 && y <= n) return 1;
	return 0;
}
int bfs(int sx, int sy, int tx, int ty)
{
	q.push({sx, sy});
	visit[sx][sy] = true;
	while(!q.empty())
	{
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();
		if(dx == tx && dy == ty) return dp[tx][ty];
		// {
		// 	return;
		// }
		// di chuyen
		for(int i=dy; i<=n; i++)
		{
			int nx = dx, ny = i;
			if(inside(nx, ny) && a[nx][ny] == 'X') break;
			else if(inside(nx, ny) && a[nx][ny] == '.' && !visit[nx][ny])
			{
				q.push({nx, ny});
				visit[nx][ny] = true;
				dp[nx][ny] = dp[dx][dy] + 1;
			}
		}

		for(int i=dy; i>0; i--)
		{
			int nx = dx, ny = i;
			if(inside(nx, ny) && a[nx][ny] == 'X') break;
			else if(inside(nx, ny) && a[nx][ny] == '.' && !visit[nx][ny])
			{
				q.push({nx, ny});
				visit[nx][ny] = true;
				dp[nx][ny] = dp[dx][dy] + 1;
			}
		}

		for(int i=dx; i<=n; i++)
		{
			int nx = i, ny = dy;
			if(inside(nx, ny) && a[nx][ny] == 'X') break;
			else if(inside(nx, ny) && a[nx][ny] == '.' && !visit[nx][ny])
			{
				q.push({nx, ny});
				visit[nx][ny] = true;
				dp[nx][ny] = dp[dx][dy] + 1;
			}
		}

		for(int i=dx; i>0; i--)
		{
			int nx = i, ny = dy;
			if(inside(nx, ny) && a[nx][ny] == 'X') break;
			else if(inside(nx, ny) && a[nx][ny] == '.' && !visit[nx][ny])
			{
				q.push({nx, ny});
				visit[nx][ny] = true;
				dp[nx][ny] = dp[dx][dy] + 1;
			}
		}
		
	}
}
int main()
{
	Hello_i_am_Salmon
	cin >> n;
	int sx, sy, tx, ty;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i=0; i<maxN; i++)
	memset(visit, false, sizeof(visit));
	cin >> sx >> sy >> tx >> ty;
	sx++; sy++; tx++; ty++;
	bfs(sx, sy, tx, ty);
	// show1
	cout << dp[tx][ty] << endl;
}
