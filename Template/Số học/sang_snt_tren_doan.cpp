	/*--------------------------------------------
			Competitive programing
		   Name: Đào Xuân Hoàng Tuấn (Salmon)
	Nothing is impossible, as you as you believe you can do it
			 You can do it!!!
	----------------------------------------------*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define Hello_i_am_Salmon 		ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define print_fix 			cout << fixed << setprecision(20);
#define show(x)				cerr << #x << " -> " << x << endl;
#define show3 				cerr << "***" << endl;
#define show2 				cerr << "**" << endl;
#define show1 				cerr << "*" << endl;
#define all(v) 				v.begin(), v.end()
#define sz(t) 				(int) t.size()
#define pb 				push_back
#define se 				second
#define fi 				first
#define el  			endl
#define ed 				'\n'
#define _ 				" "

void debug_out() {cout << '\n';}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
	cout << H << ' ';
	debug_out(T...);
}
#define fix(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
// long long gcd_(long long a, long long b) {return b==0 ? a : gcd(b, a%b);}
const long long N = 5e5+10;
const long long Nn = 1e3+10;
const double PI = atan(1)*4;
const int MOD = 1e9 + 7;
const unsigned long long INF = 1e19 + 7ll;

	/* --- Code ---- */



int main()
{
	Hello_i_am_Salmon
	#ifdef ONLINE_JUDGE
	freopen("eratosthene.inp", "r", stdin);
	freopen("eratosthene.out", "w", stdout);
	#endif

	// #ifdef ONLINE_JUDGE
	// freopen("llcm.inp", "r", stdin);
	// freopen("llcm.out", "w", stdout);
	// #endif

	// #ifdef ONLINE_JUDGE
	// freopen("cntdiv.inp", "r", stdin);
	// freopen("cntdiv.out", "w", stdout);
	// #endif

	long long L, R; cin >> L >> R;
	long long cnt = 0;

	vector<bool> isPrime(R - L + 1, true);  // x là số nguyên tố khi và chỉ khi isPrime[x - l] == true

	for (long long i = 2; i * i <= R; ++i) {
	    for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
	        isPrime[j - L] = false;
	    }
	}

	if (1 >= L) {  // Xét riêng trường hợp số 1
	    isPrime[1 - L] = false;
	}

	//Check cac snt tren doan L->R
	for (long long x = L; x <= R; ++x) {
	    if (isPrime[x - L]) {
	      	cnt++;
	    }
	}
	cout << cnt << ed;

}
	
		
/* Test case 




*/ 