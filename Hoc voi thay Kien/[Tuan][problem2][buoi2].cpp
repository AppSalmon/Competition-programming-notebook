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
const int MOD = 1000000007;

struct matran
{
	ll a[22][22];
};

ll n, k;
matran A;
matran I;
matran endgame;

void clear(matran x)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			x.a[i][j] = 0;
		}
	}
}

matran tich(matran a, matran b)
{
	matran ans;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			ans.a[i][j] = 0;
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			for(int k=1; k<=n; k++)
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
	matran ans;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i == j) ans.a[i][j] = 1;
			else ans.a[i][j] = 0;
		}
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
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++) ans.a[i][j] = 0;
	}

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
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
	clear(res);
	clear(Akdiv2);
	
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
	Hello_i_am_Salmon

	clear(endgame);


	cin >> n >> k;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin >> A.a[i][j];
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i == j) I.a[i][j] = 1;
			else I.a[i][j] = 0;
		}
	}

	endgame = giai_quyet(k);

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cout << endgame.a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}
