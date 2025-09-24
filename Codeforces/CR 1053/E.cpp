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
typedef __uint128_t u128; 
const ll maxN = 2e5, lim = 1e6 + 5, bits = 30, inf = 1 << bits, MOD = 998244353, nmax = 1e7 + 5;
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        cin >> n;
        vl v(n + 1);
        for (fint i = 1; i <= n; i++) cin >> v[i];
        vl a(n + 1), b(n + 1);
        for (fint i = 1; i <= n; i++) cin >> a[i];
        for (fint i = 1; i <= n; i++) cin >> b[i];
        vl posb(n + 1);
        for (fint i = 1; i <= n; i++) posb[b[i]] = i;
        vl p(n + 1), w(n + 1);
        for (fint i = 1; i <= n; i++) {
            p[i] = posb[a[i]];
            w[i] = v[a[i]];
        }
        ll res = 0, pref = 0, cur = 0, bmin = n + 1;
        for (fint i = 1; i <= n; i++) {
            if (p[i] < bmin) {
                res = max(res, pref);
                pref += cur;
                cur = w[i];
                bmin = p[i];
                res = max(res, pref + cur);
            } else {
                cur += w[i];
                res = max(res, pref + cur);
            }
        }
        res = max(res, pref + cur);
        cout << res << '\n';
    }
}