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
set <fint> get_l(const vl &a) {
    set <fint> l;
    fint cur = -1;
    for (fint x : a) {
        if (x > cur) {
            l.insert(x);
            cur = x;
        }
    }
    return l;
}
set <fint> get_r(const vl &a) {
    set <fint> r;
    fint cur = -1;
    for (fint i = sz(a) - 1; i >= 0; i--) {
        if (a[i] > cur) {
            r.insert(a[i]);
            cur = a[i];
        }
    }
    return r;
}
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        cin >> n;
        vl a(n);
        for (ll &i : a) cin >> i;
        set <fint> L = get_l(a), R = get_r(a);
        if (n > 20) {
            cout << 1 << '\n';
            continue;
        }
        fint res = 0;
        for (fint bit = 0; bit < (1 << n); bit++) {
            vl sub;
            for (fint i = 0; i < n; i++) {
                if (bit & (1 << i)) {
                    sub.pb(a[i]);
                }
            }
            if (sub.empty()) continue;
            if (get_l(sub) == L && get_r(sub) == R) {
                res = (res + 1) % MOD;
            }
        }
        cout << res << '\n';
    }
}