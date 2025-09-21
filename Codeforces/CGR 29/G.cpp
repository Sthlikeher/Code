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
ll binp(ll b, ll e) {
    ll res = 1;
    b %= MOD;
    while (e) {
        if (e & 1) res = res* b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return res;
}
void t_factor (ll n, unordered_map<ll, fint>& M, const vl& p) {
    for (fint pr : p) {
        if ((ll) pr * pr > n) break;
        while (n % pr == 0) {
            M[pr]++;
            n /= pr;
        }
    }
    if (n > 1) M[n]++;
}
Piu {
    fl;
    vector <bool> check(lim + 1, true);
    vector <fint> p;
    for (fint i = 2; i <= lim; i++) 
        if (check[i]) {
            p.eb(i);
            if ((ll)i * i <= lim) 
                for (fint j = i * i; j <= lim ; j += i) check[j] = false;
        }
    fint t;
    cin >> t;
    while (t--) {
        ll x, y, z;
        cin >> x >> y >> z;
        unordered_map <ll, fint> cnt;
        t_factor(x, cnt, p);
        t_factor(y, cnt, p);
        t_factor(z, cnt, p);
        ll ans = 1;
        vector <ll> pm;
        for (auto [x, k] : cnt) {
            pm.eb(x);
            ans = ans * ((x - 1) % MOD) % MOD;
            ans = ans * binp(x, MOD - 1 - k) % MOD;
        }
        map <ll, fint> E;
        for (ll x : pm) {
            ll t = x - 1;
            for (fint q : p) {
                if ((ll) q * q > t) break;
                while (t % q == 0) {
                    E[q]++;
                    t /= q;
                }
            }
            if (t > 1) E[t]++;
        }
        unordered_set <ll> ps(all(pm));
        for (auto [r, e] : E) {
            if (ps.count(r)) ans = ans * binp(r, MOD - 1 - e) % MOD;
            else {
                ll invr = binp(r, MOD - 2);
                ll invr_e = binp(invr, e);
                ll term = (invr + (1 - invr + MOD) % MOD * invr_e) % MOD;
                ans = ans * term % MOD;
            }
        }
        cout << ans << '\n';
    }
}