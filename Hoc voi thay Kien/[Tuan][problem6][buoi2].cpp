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
const long long maxN = 1000;
const double PI = atan(1)*4;
const int INF = 2e9+5;
const int MOD = 100;
struct matran
{
	ll a[3][3];
};

matran tich(matran a, matran b)
{
	matran ans;
	ans.a[1][1] = 0;
	ans.a[1][2] = 0;
	ans.a[2][1] = 0;
	ans.a[2][2] = 0;
	for(int i=1; i<=2; i++)
	{
		for(int j=1; j<=2; j++)
		{
			for(int k=1; k<=2; k++)
			{
				ans.a[i][j] += (a.a[i][k]%MOD * b.a[k][j]%MOD) % MOD;
				ans.a[i][j] %= MOD;
			}
		}
	}
	return ans;
}

matran binpow(matran a, ll b)
{
	matran res;
	res.a[1][1] = 1;
	res.a[1][2] = 0;
	res.a[2][1] = 0;
	res.a[2][2] = 1;
	if(b == 0) return res;
	if(b == 1) return a;
	matran t = binpow(a, b/2);
	if(b % 2 == 0)
	{
		return tich(t, t);
	}
	return tich(tich(t, t), a);
}

int main()
{
	Hello_i_am_Salmon
	int t; cin >> t;
	while(t--)
	{
		ll n; cin >> n;
		matran A;
		A.a[1][1] = 2;
		A.a[1][2] = 3;
		A.a[2][1] = 1;
		A.a[2][2] = 2;
		matran endgame;
		endgame = binpow(A, n);
		// for(int i=1; i<=2; i++)
		// {
		// 	for(int j=1; j<=2; j++)
		// 	{
		// 		cout << endgame.a[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		ll ans = (endgame.a[1][1] * 2 - 1) % MOD;
		if(ans < 10)
		{
			string ans_str = "0";
			ans_str += (char) (ans + '0');
			cout << ans_str << '\n';
		}
		else cout << ans << '\n';
	}
}
