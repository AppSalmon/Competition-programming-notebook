/*--------------------------------------------
			Competitive programing
		   Name: Đào Xuân Hoàng Tuấn (Salmon)
	Nothing is impossible, as you as you believe you can do it
			 You can do it!!!
	----------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
#define ll 				long long
#define Hello_i_am_Salmon 		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
#define el 				endl
#define ed 				'\n'
#define _ 				" "

void debug_out() {cout << '\n';}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T){
	cout << H << ' ';
	debug_out(T...);
}
#define fix(...) cout << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)

const long long N = 1e6+10;
const long long Nn = 3e3+10;
const long long amvc = 10e-10;
const double PI = atan(1)*4;
const int MOD = 1e9 + 7;
const ll INF = 2e15+5;

	/* --- Code ---- */


struct PT
{
	ll x, y;
};

vector<PT> a;
ll n;

bool cmp(PT a, PT b)
{
	// So sanh theo toa do x, sau do so sanh theo y
	return ((a.x < b.x) || (a.x == b.x && a.y < b.y));
}
bool CW(PT a, PT b, PT c)
{
	// a -> b -> c di theo chieu kim dong ho
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0; // Neu k co 3 diem thang hang thi bo dau bang
}

bool CCW(PT a, PT b, PT c)
{
	// a -> b -> c di theo chieu nguoc kim dong ho
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) >= 0; // Neu k co 3 diem thang hang thi bo dau bang
}

void Convex_hull()
{
	if(a.size() == 1)
	{ // Chi co 1 diem
		return;
	}
	sort(all(a), cmp); // Sx cac diem theo x, sau do sx theo y
	PT p1 = a[0]; // Lay diem ngoai cung ben trai phia duoi (L)
	PT p2 = a.back(); // Lay diem ngoai cung ben phai phia tren (R)
	vector<PT> up, down; // Chuoi tren va chuoi duoi
	up.pb(p1);
	down.pb(p1);
	for(int i=1; i<sz(a); i++) // Xet lan luot cac diem de them vao chuoi tren
	{
		// Them chuoi tren
		if(i == sz(a)-1 || CW(p1, a[i], p2)) // Neu L, a[i], R cung chieu kim dong ho thi:
		{
			while(up.size() >= 2 && !CW(up[sz(up)-2], up[sz(up)-1], a[i]))
			{
				// Neu 2 diem dc them vao gan day nhat ket hop voi a[i] ma nguoc chieu KDH thi xoa diem them vao gan nhat
				// Lap lai den khi cung chieu thi thoi
				up.pop_back();
			}
			up.pb(a[i]); // Them diem moi vao
		}

		// Them chuoi duoi
		// Them chuoi duoi tuong tu nhu chuoi tren chi khac la swap(CCW, CW)
		if(i == sz(a)-1 || CCW(p1, a[i], p2))
		{
			while(sz(down) >= 2 && !CCW(down[sz(down)-2], down[sz(down)-1], a[i]))
			{
				down.pop_back();
			}
			down.pb(a[i]);
		}		
	}
	//Gop 2 chuoi tren va duoi de lay bao loi
	a.clear();
	for(int i=0; i<sz(up); i++) a.pb(up[i]);	
	for(int i=sz(down)-2; i>0; i--) a.pb(down[i]);

	//for(int i=0; i<sz(up); i++) cout << up[i].x << _ << up[i].y << ed;	
	//for(int i=0; i<sz(down); i++) cout << down[i].x << _ << down[i].y << ed;
}

int main()
{
	Hello_i_am_Salmon
	cin >> n;
	for(int i=0; i<n; i++)
	{
		PT point;
		ll x, y; cin >> x >> y;
		point.x = x;
		point.y = y;
		a.pb(point);
	}
	// for(int i=0; i<sz(a); i++) cout << a[i].x << _ << a[i].y << ed;
	// cout << "---" << ed;
	Convex_hull();
	cout << sz(a) << ed;
	for(int i=0; i<sz(a); i++) cout << a[i].x << _ << a[i].y << ed;


}

/* Test case

6
2 1
2 5
3 3
4 3
4 4
6 3

*/
