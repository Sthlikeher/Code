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
const ll maxN = 200005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, mod = 998244353, neg_inf = -4e18;
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        cin >> n;
        vl l(n), r(n);
        for (fint i = 0; i < n; i++) cin >> l[i] >> r[i];
        ll base = 0, suml = 0;
        for (fint i = 0; i < n; i++) base += (r[i] - l[i]), suml += l[i];
        fint k = n / 2;
        vector<pll> val(n);
        for (fint i = 0; i < n; i++) val[i] = {r[i] + l[i], i};
        nth_element(val.begin(), val.begin() + k, val.end(), [](const pll &a, const pll &b) { return a.fi > b.fi; });
        ll sumtop = 0;
        vector<char> inr(n, 0);
        for (fint i = 0; i < k; i++) sumtop += val[i].fi, inr[val[i].se] = 1;
        ll extra = -suml + sumtop;
        if (n % 2 == 1) {
            ll bestl = neg_inf;
            for (fint i = 0; i < n; i++) if (!inr[i]) bestl = max(bestl, l[i]);
            extra += bestl;
        }
        cout << base + extra << '\n';
    }
}