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
const ll maxN = 200005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, mod = 998244353;
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vl cnt(n + 2, 0);
        for (ll i = 0; i < n; i++) {
            ll x; cin >> x;
            if (x <= n) cnt[x]++;
        }
        ll M = 0;
        while (M <= n && cnt[M] > 0) ++M;
        if (k == 1) {
            ll u_cnt = 0, u_sum = 0;
            for (ll x = 0; x < M; x++) if (cnt[x] == 1) {
                ++u_cnt; u_sum += x;
            }
            ll ans = u_sum + (ll)(n - u_cnt) * M;
            cout << ans << '\n';
            continue;
        }
        ll m = -1;
        for (ll x = 0; x < M; x++) if (cnt[x] != 1) {m = x; break;}
        if (m == -1) m = M;
        ll c = n - m, base = 1LL * m * (m - 1) / 2, rep;
        if (m < M) {
            if (c >= 2) rep = m + (k & 1);
            else rep = m;
        } else {
            if (c >= 2) rep = m + ((k % 2 == 0) ? 1 : 0);
            else rep = m;
        }
        cout << base + c * rep << '\n';
    }
}