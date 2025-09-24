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
const ll maxN = 500005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, MOD = 998244353, nmax = 1e7 + 5;
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        cin >> n;
        vl a(2 * n);
        for (fint i = 0; i < n * 2; i++) cin >> a[i];
        sort(all(a));
        ll tot = accumulate(all(a), 0LL);
        vl pre(2 * n + 1, 0);
        for (fint i = 0; i < n * 2; i++) pre[i + 1] = pre[i] +a[i];
        vl O, E;
        for (fint i = 0; i < 2 * n; i++) {
            if (i % 2 == 0) E.eb(a[i]);
            else O.eb(a[i]);
        }
        fint n0 = n;
        vl preO(n0 + 1, 0), preE(n0 + 1, 0);
        for (fint i = 0; i < n0; i++) {
            preO[i + 1] = preO[i] + O[i];
            preE[i + 1] = preE[i] + E[i];
        }
        vl res;
        for (fint k = 1; k <= n; k++) {
            ll seg = 0;
            if (k % 2 == 0) {
                fint m = k / 2;
                if (m <= n0 - m - 1) seg = preO[n0 - m] - preE[m];
                else {
                    fint m = (k - 1) / 2;
                    if (m + 1 <= n0 - m - 1) seg = preE[n0 - m] - preE[m + 1];
                }
                ll ent = pre[k] + seg;
                res.eb(tot - 2 * ent);
            }
        }
        for (ll val : res) {
            cout << val << " ";
        }
        cout << '\n';
    }
}