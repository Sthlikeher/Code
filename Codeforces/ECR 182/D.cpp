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
        fint n, y;
        cin >> n >> y;
        vl a(n);
        fint m = 0;
        for (ll &i : a) cin >> i, m = max(m, static_cast<fint>(i));
        vl freq(m + 1, 0);
        for (fint i = 0; i < n; i++) if (a[i] <= m) freq[a[i]]++;
        vl f(m + 1, 0);
        if (m >= 1) {
            f[0] = 0;
            for (fint i = 1; i <= m; i++) f[i] = f[i - 1] + freq[i];
        }
        fint res = -LLONG_MIN;
        for (fint x = 2; x <= m; x++) {
            ll s = 0, val = 0;
            for (fint v = 1 ;; v++) {
                fint l = x * (v - 1) + 1;;
                if (l > m) break;
                fint r = min(x * v, m);
                ll cnt = f[r] - f[l - 1];
                if (cnt == 0) continue;;
                s += v * cnt;
                if (v <= m) val += min(static_cast<ll>(freq[v]), cnt);
            }
            ll inc = s - y * (n - val);
            if (inc > res) res = inc;
        }
        ll sl = n;
        ll ml = min(static_cast<ll>(freq[1]), static_cast<ll>(n));
        ll incl = sl - y * (n - ml);
        if (incl > res) res = incl;
        cout << res << '\n';
    }
}