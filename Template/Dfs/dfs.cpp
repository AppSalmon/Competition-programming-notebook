// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
using namespace std;

#define MAXN 100001

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
	spf[1] = 1;
	for (int i=2; i<MAXN; i++)

		// marking smallest prime factor for every
		// number to be itself.
		spf[i] = i;

	// separately marking spf for every even
	// number as 2
	for (int i=4; i<MAXN; i+=2)
		spf[i] = 2;

	for (int i=3; i*i<MAXN; i++)
	{
		// checking if i is prime
		if (spf[i] == i)
		{
			// marking SPF for all numbers divisible by i
			for (int j=i*i; j<MAXN; j+=i)

				// marking spf[j] if it is not
				// previously marked
				if (spf[j]==j)
					spf[j] = i;
		}
	}
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
	vector<int> ret;
	while (x != 1)
	{
		ret.push_back(spf[x]);
		x = x / spf[x];
	}
	return ret;
}

// driver program for above function
int main(int argc, char const *argv[])
{
	// precalculating Smallest Prime Factor
	sieve();
	int x = 40320;
	cout << "prime factorization for " << x << " : ";

	// calling getFactorization function
	vector <int> p = getFactorization(x);

	for (int i=0; i<p.size(); i++)
		cout << p[i] << " ";
	cout << endl;
	return 0;
}

// void getFactorization()
// {
// 	for(int i=1; i<=N; i++)
// 	{
// 		int x = i;
// 		if(mcd[i] == 0) break;
// 		while (x != 1)
// 		{
// 			arr[spf[x]]+=mcd[i];
// 			x = x / spf[x];
// 		}

// 	}
// }

// void getFactorization_x(int n)
// {
// 	xprime.clear();
// 	show1
// 	for(int i=1; i<=n; i++)
// 	{
// 		int x = i;
// 		while (x != 1)
// 		{
// 			xprime[spf[x]]++;
// 			x = x / spf[x];
// 		}
// 	}
// }

// bool Ok(int x)
// {
// 	getFactorization_x(x);

// 	for(auto it : xprime)
// 	{
// 		if(arr[it.fi] < it.se) return false;
// 	}
// 	return true;

// }

	// while(l <= r)
	// {
	// 	show1
	// 	long long mid = (l + r) / 2;
	// 	if(Ok(mid))
	// 	{
	// 		show2
	// 		ans = mid;
	// 		r = mid - 1;
	// 	}
	// 	else l = mid + 1;
	// }

	// void sieve()
// {
// 	spf[1] = 1;
// 	for (int i=2; i<N; i++)
// 		spf[i] = i;

// 	for (int i=4; i<N; i+=2)
// 		spf[i] = 2;

// 	for (int i=3; i*i<N; i++)
// 	{
// 		if (spf[i] == i)
// 		{
// 			for (int j=i*i; j<N; j+=i)
// 				if (spf[j]==j)
// 					spf[j] = i;
// 		}
// 	}
// }