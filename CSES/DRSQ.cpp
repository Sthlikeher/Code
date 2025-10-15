#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define piu signed main()
#define fi first
#define se second
#define ld long double
#define pii pair<fint, fint>
#define pll pair<long long, long long>
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) x.size())
#pragma GCC optimize ("Ofast","unroll-loops")
#pragma GCC target ("avx2")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef int_fast64_t fint;
const ll maxN = 30, lim = 5e5 + 5, mod = 998244353, N = 2e5 + 5;
fint n, q;
vl bit, a;
void add(fint i, ll d) {
    for (; i <= n; i += i & -i) bit[i] += d; 
}
ll s(fint i) {
    ll ss = 0;
    for (; i > 0; i -= i & -i) ss += bit[i];
    return ss;
}
piu {
    fl;
    cin >> n >> q;
    bit.assign(n + 1, 0), a.assign(n + 1, 0);
    for (fint i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i]);
    }
    while (q--) {
        fint t;
        cin >> t;
        if (t== 1) {
            fint k;
            ll u;
            cin >> k >> u;
            add(k, u- a[k]);
            a[k] = u;
        } else {
            fint l, r;
            cin >> l >> r;
            cout << (s(r) - s(l - 1)) << '\n';
        }
    }
}