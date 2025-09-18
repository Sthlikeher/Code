#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define Piu signed main()
#define fi first
#define se second
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) x.size())
#pragma GCC optimize ("Ofast","unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef int_fast64_t fint;
const ll maxN = 500005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, MOD = 998244353, nmax = 1e7 + 5;
struct BIT {
    fint n;
    vl t;
    BIT() : n(0) {}
    BIT(fint n_) { init(n_); }
    void init(fint n_) { n = n_; t.assign(n + 1, 0); }
    void add(fint i, ll v) {
        for (; i <= n; i += i & -i) {
            t[i] += v;
            if (t[i] >= MOD) t[i] -= MOD; 
        }
    }
    ll sumPrefix(fint i) const {
        ll r = 0;
        for (; i > 0; i -= i & -i) {
            r += t[i];
            if (r >= MOD) r -= MOD;
        }
        return r;
    }
};
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        cin >> n;
        vector<fint> a(n);
        fint V = 0;
        for (fint i = 0; i < n; i++) { cin >> a[i]; V = max(V, a[i]); }
        vector<BIT> bit(V + 1);
        for (fint M = 1; M <= V; M++) bit[M].init(M);
        vl diag(V + 1, 0);   
        vl tot(V + 1, 0);   
        BIT totFenwick(V);
        totFenwick.init(V);
        for (fint idx = 0; idx < n; idx++) {
            fint x = a[idx];
            ll add_diag = (1 + totFenwick.sumPrefix(x)) % MOD;
            diag[x] += add_diag; if (diag[x] >= MOD) diag[x] -= MOD;
            bit[x].add(x, add_diag);
            tot[x] += add_diag; if (tot[x] >= MOD) tot[x] -= MOD;
            totFenwick.add(x, add_diag);
            for (fint M = x + 1; M <= V; M++) {
                ll nondec = bit[M].sumPrefix(x);
                ll dec = diag[M];
                ll add = (nondec + dec) % MOD;
                if (add > 0) {
                    bit[M].add(x, add);
                    tot[M] += add; if (tot[M] >= MOD) tot[M] -= MOD;
                    totFenwick.add(M, add);
                }
            }
        }
        ll non = totFenwick.sumPrefix(V);
        cout << (1 + non) % MOD << '\n';
    }
}