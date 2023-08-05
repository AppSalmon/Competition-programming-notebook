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
void debug_out(Head H, Tail ...T)
{
	cout << H << ' ';
	debug_out(T...);
}
#define fix(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
const long long N =1e6+10;
const long long Nn = 1e3+10;
const double PI = atan(1)*4;
const int MOD = 1e9 + 7;
const long long INF = 1e9 + 7ll;

struct toado
{
    long long x, y;
};


long long Tich_co_huong(toado AB, toado AC)
{
	return AB.x * AC.y - AB.y * AC.x;
}
int main()
{
	int t; cin >> t;
	while(t--)
    {
        toado A, B, C;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
        toado AB, AC;
        AB.x = B.x - A.x;
        AB.y = B.y - A.y;
        AC.x = C.x - A.x;
        AC.y = C.y - A.y;
        long long check = Tich_co_huong(AB, AC);
        if (check == 0)
        {
            cout << "TOUCH" << '\n';
        }
        else if (check > 0)
        {
            cout << "LEFT" << '\n';
        }
        else cout << "RIGHT" << '\n';


    }
}

/* Test case

*/


	/* My code is very beautiful and artistic */


