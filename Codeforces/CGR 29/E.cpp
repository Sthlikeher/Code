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
const ll maxN = 500005, lim = 1e6 + 5, bits = 31, inf = 1 << bits, MOD = 998244353, INF = (ll)4e18;
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        fint n, q;
        cin >> n >> q;
        vl a(n);
        for (fint i = 0; i < n; i++) cin >> a[i];
        vl cost(bits, INF);
        ll ini = 0;
        for (ll x : a) ini |= x;
        for (fint k = 0; k < bits; k++) if (ini & (1LL << k)) cost[k] = 0;
        for (ll x : a) {
            for (fint k = 0; k < bits; k++) {
                if (cost[k] == 0) continue;
                ll m = (1LL << k);
                ll base = (x | m) & (~(m - 1));
                ll delta;
                if (base >= x) delta = base - x;
                else {
                    ll block = (m << 1);
                    delta = base + block - x;
                }
                cost[k] = min(cost[k], delta);
            }
        }
        sort(all(cost));
        vl pref(bits + 1, 0);
        for (fint i = 0; i < bits; i++) pref[i + 1] = pref[i] + cost[i];
        while(q--) {
            ll b;cin >> b;
            ll lo = 0, hi = bits;
            while (lo < hi) {
                fint mid = (lo + hi + 1) >> 1;
                if (pref[mid] <= b) lo = mid;
                else hi = mid - 1;
            }
            cout << lo << '\n';
        }
    }
}