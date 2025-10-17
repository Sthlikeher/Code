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
const ll maxN = 30, lim = 1e7 + 7, mod = 1e9 + 7, N = 2e5 + 5, base = 131;
vl p1(N + 1), p2(N + 1);
void pre() {
    p1[0] = 1, p2[0] = 1;
    for (fint i = 1; i <= N; i++) {
        p1[i] = (p1[i] * base) % lim;
        p2[i] = (p2[i] * base) % mod;
    }
}
ll comp(const vl &h, const vl &p, fint l, fint r, ll m) {
    if (l == 0) return h[r];
    ll res = (h[r] - h[l - 1] * p[r- l + 1] % m) % m;
    if (res < 0) res += m;
    return res;
}
piu {
    fl;
    pre();
    fint t;
    cin >> t;
    while (t--) {
        fint n, k;
        cin >> n >> k;
        vector <fint> a(n);
        for (auto &i : a) cin >> i;
        vector <fint> cnt(n + 1, 0);
        cnt[a[n - 1]]++;
        vl h11(n), h12(n);
        h11[0] = a[0] % lim;
        h12[0] = a[0] % mod;
        for (fint i = 1; i < n; i++) {
            h11[i] = (h11[i - 1] * base +a[i]) % lim;
            h12[i] = (h12[i - 1] * base + a[i]) % mod;
        }
        vector <fint> r(n);
        for (fint i =0; i < n; i++) r[i] = a[n - 1 - i];
        vl h21(n), h22(n);
        h21[0] = r[0] % lim;
        h22[0] = r[0] % mod;
        for (fint i = 1; i < n; i++) {
            h21[i] = (h21[i - 1] * base +r[i]) % lim;
            h22[i] = (h22[i - 1] * base + r[i]) % mod;
        }
        for (fint i = 1; i < n; i++) {
            fint l1 = n - i, r1 = n - 1;
            ll hs11 = comp(h11, p1, l1, r1, lim);
            ll hs12 = comp(h12, p2, l1, r1, mod);
            ll hs21 = comp(h21, p1, 0, i - 1, lim);
            ll hs22 = comp(h22, p2, 0, i - 1, mod);
            if (hs11 == hs21 && hs12 == hs22) {
                fint idx = n - i - 1;
                cnt[a[idx]]++;
            }
        }
        vector <fint> cand(n);
        iota(all(cand), 1);
        sort(all(cand), [&](fint x, fint y) {
            return cnt[x] < cnt[y];
        });
        vector <fint> c;
        c.pb(cand[0]);
        for (fint i = 1; i < n && c.size() < 3; i++) {
            if (c[i] != c[0]) {
                if (c.size() == 1) c.pb(cand[i]);
            } else if (cand[i] != c[1]) c.pb(cand[i]);
        }
        for (fint i = 0; i < k; i++) cout << c[i % c.size()] << " ";
        cout << '\n';
    }
}