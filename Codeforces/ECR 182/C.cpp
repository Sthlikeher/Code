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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef int_fast64_t fint;
const ll maxN = 500005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, MOD = 998244353, nmax = 1e7 + 5;
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        cin >> n;
        vl a(n), b(n);
        for (ll &i : a) cin >> i;
        for (ll &i : b) cin >> i;
        fint k = 0;
        vector<vector<pii>> opt(n);
        for (fint i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                opt[i].eb(a[i], a[i]);
                k++;
            } else {
                ll mn = min(a[i], b[i]);
                ll mx = max(a[i], b[i]);
                opt[i].eb(mn, mx);
                opt[i].eb(mx, mn);
            }
        }
        vl dp(sz(opt[0]), 1);
        for (fint i = 1; i < n; i++) {
            vl new_dp(sz(opt[i]), 0);
            for (fint j = 0; j < sz(opt[i]); j++) {
                pii cur = opt[i][j];
                for (fint k = 0; k < sz(opt[i - 1]); k++) {
                    pii pre = opt[i - 1][k];
                    if (pre.fi <= cur.fi && pre.se <= cur.se) {
                        new_dp[j] = (new_dp[j] + dp[k]) % MOD;
                    }
                }
            }
            dp = new_dp;
        }
        ll tt = 0;
        for (fint cnt : dp) tt = (tt + cnt) % MOD;
        ll ans = tt;
        for (fint i = 0; i < k; i++) ans = (ans * 2) % MOD;
        cout << ans << '\n';
    }
}