// Tutorial: https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
// Walsh–Hadamard transform
//
// xor FFT:
// - Given 2 arrays A and B of length N = 2^k.
// - For each (i, j): C[i ^ j] = C[i ^ j] + A[i] * B[j]
//
// Tested:
// XOR:
// - https://csacademy.com/contest/archive/task/random_nim_generator/
//
// AND:
// - https://csacademy.com/contest/archive/task/and-closure
//
// OR:
// - https://csacademy.com/contest/archive/task/maxor/

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
long long power(long long x, long long k, long long MOD) {
    long long res = 1;
    while (k) {
        if (k & 1) res = res * x % MOD;
        k >>= 1;
        x = x * x % MOD;
    }
    return res;
}

// H = [1 1; 1 -1]
void xorFFT(long long a[], int n, int MOD, int invert) {
    assert(__builtin_popcountll(n) == 1);  // N must be power of 2.

    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len << 1) {
            for (int j = 0; j < len; j++) {
                long long u = a[i + j];
                long long v = a[i + j + len];

                a[i + j] = u + v;
                if (a[i + j] >= MOD) a[i + j] -= MOD;

                a[i + j + len] = u - v;
                if (a[i + j + len] < 0) a[i + j + len] += MOD;
            }
        }
    }

    if (invert) {
        long long inv = power(n, MOD - 2, MOD);
        REP(i,n) a[i] = a[i] * inv % MOD;
    }
}

// H = [0 1; 1 1]
void andFFT(long long a[], int n, int MOD, int invert) {
    assert(__builtin_popcountll(n) == 1);  // N must be power of 2.

    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len << 1) {
            for (int j = 0; j < len; j++) {
                long long u = a[i + j];
                long long v = a[i + j + len];

                if (!invert) {
                    a[i + j] = v;
                    a[i + j + len] = u + v;
                    if (a[i + j + len] >= MOD) a[i + j + len] -= MOD;
                } else {
                    a[i + j] = v - u;
                    if (a[i + j] < 0) a[i + j] += MOD;
                    a[i + j + len] = u;
                }
            }
        }
    }
}

// H = [1 1; 1 0]
void orFFT(long long a[], int n, int MOD, int invert) {
    assert(__builtin_popcountll(n) == 1);  // N must be power of 2.

    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += len << 1) {
            for (int j = 0; j < len; j++) {
                long long u = a[i + j];
                long long v = a[i + j + len];

                if (!invert) {
                    a[i + j] = u + v;
                    if (a[i + j] >= MOD) a[i + j] -= MOD;

                    a[i + j + len] = u;
                } else {
                    a[i + j] = v;
                    a[i + j + len] = u - v;
                    if (a[i + j + len] < 0) a[i + j + len] += MOD;
                }
            }
        }
    }
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int get_rand(int r) {
    return uniform_int_distribution<int> (0, r-1)(rng);
}

namespace Test {
#define TWO(X) (1LL << (X))
    const int MAXN = 1e5 + 5;
    const int MAXV = 100;
    long long a[MAXN], b[MAXN], c[MAXN];
    void testXorFFT() {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);

        int n = TWO(11);
        const int MOD = 1e9 + 7;
        REP(i,n) a[i] = get_rand(MAXV);
        REP(i,n) b[i] = get_rand(MAXV);

        REP(i,n) REP(j,n) {
            c[i ^ j] = (c[i ^ j] + a[i] * b[j]) % MOD;
        }
        xorFFT(a, n, MOD, 0);
        xorFFT(b, n, MOD, 0);
        REP(i,n) a[i] = a[i] * b[i] % MOD;

        xorFFT(a, n, MOD, 1);
        REP(i,n) {
            assert(a[i] == c[i]);
        }

        cerr << "XOR OK" << endl;
    }

    void testAndFFT() {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);

        int n = TWO(11);
        const int MOD = 1e9 + 7;
        REP(i,n) a[i] = get_rand(MAXV);
        REP(i,n) b[i] = get_rand(MAXV);

        REP(i,n) REP(j,n) {
            c[i & j] = (c[i & j] + a[i] * b[j]) % MOD;
        }
        andFFT(a, n, MOD, 0);
        andFFT(b, n, MOD, 0);
        REP(i,n) a[i] = a[i] * b[i] % MOD;
        andFFT(a, n, MOD, 1);
        REP(i,n) {
            assert(a[i] == c[i]);
        }
        cerr << "AND OK" << endl;
    }

    void testOrFFT() {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);

        int n = TWO(11);
        const int MOD = 1e9 + 7;
        REP(i,n) a[i] = get_rand(MAXV);
        REP(i,n) b[i] = get_rand(MAXV);

        REP(i,n) REP(j,n) {
            c[i | j] = (c[i | j] + a[i] * b[j]) % MOD;
        }
        orFFT(a, n, MOD, 0);
        orFFT(b, n, MOD, 0);
        REP(i,n) a[i] = a[i] * b[i] % MOD;
        orFFT(a, n, MOD, 1);
        REP(i,n) {
            assert(a[i] == c[i]);
        }
        cerr << "OR OK" << endl;
    }
}
