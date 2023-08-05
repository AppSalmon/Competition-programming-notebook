#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <bits/stdc++.h>
using namespace std;

#include "../modint.h"
#include "../Polynomial/NTT.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
using mint = ModInt<998244353>;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<mint> a(n); REP(i,n) cin >> a[i];
    vector<mint> b(m); REP(i,m) cin >> b[i];

    auto c = multiply(a, b);
    for (auto x : c) cout << x << ' ';
    cout << endl;
    return 0;
}
