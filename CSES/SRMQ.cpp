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
ll a[N], st[N << 1];    
void build(ll id, ll l, ll r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    ll mid = l + r >> 1;
    build(id * 2, l, mid), build(id * 2 + 1, mid + 1, r);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}
ll get(fint id, fint l, fint r, fint u, fint v) {
    if (v < l || r < u) return INT_MAX;
    if (u <= l && r <= v) return st[id];
    fint mid = l + r >> 1;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
piu {
    fl;
    fint n, q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    memset(st, 0x3f, sizeof st), build (1, 1, n);
    while(q--) {
        fint l, r;
        cin >>l >> r;
        cout << get(1, 1, n, l, r) << '\n';
    }
}