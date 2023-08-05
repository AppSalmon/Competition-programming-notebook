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
#define show1 cerr << "*" << endl;
#define show2 cerr << "**" << endl;
#define show3 cerr << "***" << endl;
const int INF = 1e9+5;
const long long maxN = 1000;
string st = "";
string en = "";

map<string, ll> visit;
map<string, ll> dp;
queue<string> q;

void bfs()
{
	q.push(st);
	visit[st]++;
	while(!q.empty())
	{
		string x = q.front();
		q.pop();
		if(x == en) return;
		else
		{

			string x1 = "";
			x1 += x[3];
			x1 += x[0];
			x1 += x[2];
			x1 += x[4];
			x1 += x[1];
			x1 += x[5];
			string x2 = "";
			x2 += x[0];
			x2 += x[4];
			x2 += x[1];
			x2 += x[3];
			x2 += x[5];
			x2 += x[2];
			if(!visit[x1])
			{
				q.push(x1);
				dp[x1] = dp[x] + 1;
				visit[x1]++;
			}
			if(!visit[x2])
			{
				q.push(x2);
				visit[x2]++;
				dp[x2] = dp[x] + 1;
			}
		}
	}
}

int main()
{
	Hello_i_am_Salmon
	for(int i=1; i<=6; i++)
	{
		int x; cin >> x;
		st += (char) ('0' + x);
	}
	for(int i=1; i<=6; i++)
	{
		int x; cin >> x;
		en += (char) ('0' + x);
	}
	bfs();
	cout << dp[en] << endl;
}
