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
struct bitmax {
    fint n; vl bit;
    void init (fint nn) { n = nn; bit.assign(n + 1, 0); }
    fint que (fint pos) const {
        fint res = 0;
        while (pos > 0) {
            res = max(res, bit[pos]);
            pos -= pos & -pos;
        }
        return res;
    }
    void upd (fint pos, fint val) {
        while (pos <= n) {
            bit[pos] = max(bit[pos], val);
            pos += pos & -pos;
        }
    }
};
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        cin >> n;
        vl a(n + 1), b(n + 1);
        for (fint i = 1; i <= n; i++) cin >> a[i];
        for (fint i = 1; i <= n; i++) cin >> b[i];
        fint V = 2 * n + 2;
        auto mappos = [&](fint val) { return V - val + 1; }; 
        bitmax bit; bit.init(V + 5);
        ll ans = 0;
        for (fint i = 1; i <= n; i++) {
            fint preva = bit.que(mappos(a[i])); 
            fint prevb = bit.que(mappos(b[i]));
            fint l = preva + 1;
            ll cnt_max = (a[i] == b[i]) ? (ll)(i - l + 1) : 0LL;
            ll cnt_old = min(l - 1, prevb);
            ll wr = (ll)(n - i + 1);
            ans += wr * (cnt_max + cnt_old);
            bit.upd(mappos(a[i]), i);
        }
        cout << ans << '\n';
    }
}