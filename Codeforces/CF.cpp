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
const ll maxN = 500005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, MOD = 998244353;
ll n;
pll a[maxN];
vl v;
ll fenw[maxN];
void upd(int i, ll val) {
    while (i <= sz(v)) {
        fenw[i] = max(fenw[i], val);
        i += i & -i;
    }
}
ll get(int i) {
    ll res = 0;
    while (i > 0) {
        res = max(res, fenw[i]);
        i -= i & -i;
    }
    return res;
}
Piu {
    fl;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
        v.pb(a[i].fi);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    ll ans = 0, m = sz(v);
    for (ll i = 0; i < n; i++) {
        ll x = a[i].fi, w = a[i].se;
        ll pos = lower_bound(all(v), x) - v.begin() + 1;
        ll best = get(pos - 1);
        ll dp = best + w;
        upd(pos, dp);
        ans = max(ans, dp);
    }
    cout << ans;
}  
