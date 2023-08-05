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
string st;
string en = "1238004765";
ll ans = INF;
map<string, ll> visit;
map<string, ll> visit2;
map<string, ll> dp1;
map<string, ll> dp2;
queue<string> q;
queue<string> q2;

int bfs1()
{
	q.push(st);
	visit[st]++;
	while(!q.empty())
	{
		string x = q.front();
		q.pop();
		if(x == en) return dp1[x];
		if(dp1[x] > 14) break;

			string x1 = "";
			x1 += x[3];
			x1 += x[0];
			x1 += x[2];
			x1 += x[7];
			x1 += x[4];
			x1 += x[1];
			x1 += x[6];
			x1 += x[8];
			x1 += x[5];
			x1 += x[9];

			string x2 = "";
			x2 += x[0];
			x2 += x[4];
			x2 += x[1];
			x2 += x[3];
			x2 += x[8];
			x2 += x[5];
			x2 += x[2];
			x2 += x[7];
			x2 += x[9];
			x2 += x[6];
			if(!visit[x1])
			{
				q.push(x1);
				dp1[x1] = dp1[x] + 1;
				visit[x1]++;
			}
			if(!visit[x2])
			{
				q.push(x2);
				visit[x2]++;
				dp1[x2] = dp1[x] + 1;
			}


	}
	return INF;
}

void bfs2()
{
	q2.push(en);
	visit2[en]++;
	while(!q2.empty())
	{
		string x = q2.front();
		q2.pop();

			string x1 = "";
			x1 += x[1];
			x1 += x[5];
			x1 += x[2];
			x1 += x[0];
			x1 += x[4];
			x1 += x[8];
			x1 += x[6];
			x1 += x[3];
			x1 += x[7];
			x1 += x[9];
			string x2 = "";
			x2 += x[0];
			x2 += x[2];
			x2 += x[6];
			x2 += x[3];
			x2 += x[1];
			x2 += x[5];
			x2 += x[9];
			x2 += x[7];
			x2 += x[4];
			x2 += x[8];
			if(!visit2[x1])
			{
				q2.push(x1);
				dp2[x1] = dp2[x] + 1;
				visit2[x1]++;
				if(visit[x1])
				{
					ans = min(ans, dp1[x1] + dp2[x1]);
				}
			}
			if(!visit2[x2])
			{
				q2.push(x2);
				visit2[x2]++;
				dp2[x2] = dp2[x] + 1;
				if(visit[x2])
				{
					ans = min(ans, dp1[x2] + dp2[x2]);
				}
			}
			if(dp2[x1] > 14 && dp2[x2] > 14) break;

	}
}

int main()
{
	Hello_i_am_Salmon
	for(int i=1; i<=10; i++)
	{
		int x; cin >> x;
		st += (char) ('0' + x);
	}
	ans = bfs1();
	if(ans == INF) 
		bfs2();
	cout << ans << endl;
}
