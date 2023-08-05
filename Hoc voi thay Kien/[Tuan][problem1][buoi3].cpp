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
const long long maxN = (1 << 20) + 5;
const double PI = atan(1)*4;
const int INF = 2e9+5;

int n;
ll a[21][21];
ll F[21][maxN];
int last;

int getbit(int mask, int i)
{
	if((mask & (1 << i)) > 0) return 1;
	return 0;
}

int offbit(int mask, int i)
{
	return (mask ^ (1 << i ));
}

int main()
{
	Hello_i_am_Salmon
	int t; cin >> t;
	while(t--)
	{
		cin >> n;
		last = (1 << n) -1;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				cin >> a[i][j];
			}
		}
		for(int mask = 0; mask <= last; mask++)
		{
			int k = __builtin_popcount(mask);
			for(int i=0; i<n; i++)
			{
				if(getbit(mask, i) == 1)
				{
					int old_mask = offbit(mask, i);
					F[k][mask] = max(F[k][mask], F[k-1][old_mask] + a[k][i+1]);
				}
			}
		}
		cout << F[n][last] << endl;
		for(int i=0; i<=20; i++)
		{
			for(int j=0; j<=maxN; j++)
			{
				F[i][j] = 0;
			}
		}
		for(int i=0; i<=20; i++)
		{
			for(int j=0; j<=20; j++)
			{
				a[i][j] = 0;
			}
		}

	}
	// cout << countSetBits(5) << endl;
}