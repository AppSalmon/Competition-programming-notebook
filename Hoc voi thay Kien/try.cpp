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
const long long MOD = 1000000000000007LL;
struct matran
{
	ll a[4][4];
};

matran A;
matran I;

ll binnul(ll a, ll b)
{
	if(b == 0) return 0;
	if(b == 1) return a;
	ll res = binnul(a, b/2);
	if(b & 1)
	{
		return (res%MOD + res%MOD + a%MOD)%MOD;
	}
	return (res%MOD + res%MOD)%MOD;
}

matran tich(matran a, matran b)
{
	matran ans;
	for(int i=1; i<=3; i++)
	{
		for(int j=1; j<=3; j++) ans.a[i][j] = 0;
	}

	for(int i=1; i<=3; i++)
	{
		for(int j=1; j<=3; j++)
		{
			for(int k=1; k<=3; k++)
			{
				ans.a[i][j] += binnul(a.a[i][k]%MOD, b.a[k][j]%MOD);
				ans.a[i][j] %= MOD;
			}
		}
	}
	return ans;
}


matran binpow(matran a, ll b)
{
	matran ans;
	for(int i=1; i<=3; i++)
	{
		for(int j=1; j<=3; j++) ans.a[i][j] = 0;
	}
	if(b == 0) return ans;
	if(b == 1) return a;
	matran t = binpow(a, b/2);
	if(b % 2 == 0)
	{
		return tich(t, t);
	}
	return tich(tich(t, t), a);
}

matran sum(matran a, matran b)
{
	matran ans;
	for(int i=1; i<=3; i++)
	{
		for(int j=1; j<=3; j++) ans.a[i][j] = 0;
	}

	for(int i=1; i<=3; i++)
	{
		for(int j=1; j<=3; j++)
		{
			ans.a[i][j] = a.a[i][j] + b.a[i][j];
			ans.a[i][j] %= MOD;
		}
	}
	return ans;
}

matran giai_quyet(ll k)
{
	if(k == 0) return I;
	if(k == 1) return A;

	matran res, Akdiv2;
	
	res = giai_quyet(k/2);
	Akdiv2 = binpow(A, k/2);
	
	if(k & 1)
	{
		return (sum(tich(sum(I, Akdiv2), res), binpow(A, k)));
	}
	else
	{
		return (tich(sum(I, Akdiv2), res));
	}
}


int main()
{
	// cout << MOD << endl;
	Hello_i_am_Salmon
	A.a[1][1] = 1;
	A.a[1][2] = 1;
	A.a[1][3] = 1;
	A.a[2][1] = 1;
	A.a[2][2] = 0;
	A.a[2][3] = 0;
	A.a[3][1] = 0;
	A.a[3][2] = 1;
	A.a[3][3] = 0;
	for(int i=1; i<=3; i++)
	{
		for(int j=1; j<=3; j++)
		{
			if(i == j) I.a[i][j] = 1;
			else I.a[i][j] = 0;
		}
	}
	int t; cin >> t;
	while(t--)
	{
		ll n; cin >> n;
		if(n <= 3)
		{
			if(n == 1) cout << 1 << endl;
			else if(n == 2) cout << 3 << endl;
			else cout << 6 << endl;
			continue;
		}

		matran tot = giai_quyet(n-3);

		// for(int i=1; i<=3; i++)
		// {
		// 	for(int j=1; j<=3; j++)
		// 	{
		// 		cout << tot.a[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;

		ll ans = tot.a[1][1]*3 + tot.a[1][2]*2 + tot.a[1][3] + 6;
		cout << ans % MOD << endl;
	}
}
