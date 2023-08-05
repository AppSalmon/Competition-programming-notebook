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
const ll INF = 2e9+5;


ll F[maxN][21];

ll getbit(ll mask, ll i)
{
	if((mask & (1 << i)) > 0) return 1;
	return 0;
}

ll offbit(ll mask, ll i)
{
	return (mask ^ (1 << i));
}

int main()
{
	Hello_i_am_Salmon
	ll t; cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		ll c[n+5][n+5];
		for(ll i=0; i<n; i++)
		{
			for(ll j=0; j<n; j++)
			{
				cin >> c[i][j];
			}
		}
		for(ll i=0; i<(1 << n); i++)
		{
			for(ll j=0; j<n; j++)
			{
				F[i][j] = INF;
			}
		}
		for(ll i=0; i<n; i++)
		{
			F[(1 << i)][i] = 0;
		}
		// F[0][0] = 0;

		ll ans = 0;
		for(ll mask = 0; mask < (1 << n); mask++)
		{
			for(ll u=0; u<n; u++)
			{
				if(getbit(mask, u))
				{
					ll old_mask = offbit(mask, u);
					for(ll v=0; v<n; v++) if(getbit(old_mask, v) && u != v)
					{
						
						F[mask][u] = min(F[mask][u], F[old_mask][v] + c[v][u]);
					}
				}
			}
		}
		for(ll i=0; i<n; i++)
		{
			ans = min(ans, F[(1 << n)-1][i]);
		}
		cout << ans << endl;


		// for(ll i=0; i<(1 << n); i++)
		// {
		// 	for(ll j=0; j<(1 << n); j++)
		// 	{
		// 		cout << F[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		// cout << endl;
		// for(ll i=0; i<=20; i++)
		// {
		// 	for(ll j=0; j<=maxN; j++)
		// 	{
		// 		F[j][i] = 0;
		// 	}
		// }
		// for(ll i=0; i<=n; i++)
		// {
		// 	for(ll j=0; j<=n; j++)
		// 	{
		// 		c[i][j] = 0;
		// 	}
		// }

	}
	// cout << countSetBits(5) << endl;
}