#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PB push_back
#define F first
#define S second
#define show cerr<<"*\n"
#define triple pair<pair<int, int>, int>
#define int ll

const double eps=1e-8;
int dblcmp(double d){ if(abs(d)<eps) return 0; return (d<eps)?1:-1;}
const int N=1e5+2;
const int mod=1e9+7;
int n;
struct MaTran
{
    int c[21][21];
};

MaTran operator * (MaTran a, MaTran b)
{
    MaTran res;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            res.c[i][j] = 0;
            for (int k=0; k<n; k++)
                res.c[i][j] = (res.c[i][j]+(a.c[i][k]%mod)*(b.c[k][j])%mod)%mod;
        }
    return res;
}

MaTran operator + (MaTran a, MaTran b) {
    MaTran res;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            res.c[i][j]=a.c[i][j]%mod+b.c[i][j]%mod;
            res.c[i][j]%=mod;

        }
    }
    return res;
}



MaTran binpow (MaTran a, int n)
{
    if (n==1)
        return a;
    if (n%2!=0)
        return binpow(a,n-1)*a;
    MaTran tmp = binpow(a,n/2);
    return tmp*tmp;
}

MaTran tong(MaTran B,int k, MaTran I, MaTran A) {
    if(k==1)
        return A;
    if(k&1)
    {
         return (I+binpow(A, k/2))*tong(B, k/2, I,A)+binpow(A, k);
    }
    else{
        return (I+binpow(A, k/2))*tong(B, k/2, I, A);
    }
}

void solve(){
  int k;
  cin >> n >> k;
  MaTran A, B, I;
  for(int i=0; i<20; i++)
  {
    for(int j=0; j<20; j++) {
        B.c[i][j]=0;
        I.c[i][j]=0;
    }
}
    for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                cin >> A.c[i][j];
        }
    for(int i=0, j=0; i<n&&j<n; i++,j++)
        I.c[i][j]=1;
    MaTran res=tong(B, k, I, A);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cout<<res.c[i][j]<<" ";
        cout<<'\n';
    }
}

signed main() {
//    cout<<__gcd(1110,5);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T=1;
//    cin >> T;
    while(T--)
        solve();
}

