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
        ll n, m;
        cin >> n >> m;
        vl a(m);
        for (fint &i : a) cin >> i;
        bool bad =false;
        for (fint i = 0; i + 1 < m; i++) {
            ll nxt = a[i + 1], cur = a[i];
            if (!(nxt == cur + 1 || nxt == 1)) { bad = true; break; }
        }
        if (bad) {cout << 0 << '\n'; continue;}
        fint frs = -1;
        for (fint i = 0; i + 1 < m; i++) if (a[i + 1] == 1) {frs = i; break;}
        if (frs == -1) {
            ll nl = a.back();
            if (nl > n) cout << 0 << '\n';
            else cout << (n - nl + 1) << '\n';
            continue;
        }
        ll l = a[frs];
        if (l > n) {cout << 0 << '\n'; continue;}
        ll curl = l, val = a[0];
        bool ok =true;
        for (fint i = 0; i + 1 < m; i++) {
            if (val < 1 || val > curl) {ok =false; break;}
            ll exc ;
            if (val < curl) {
                exc = val + 1;
            } else {
                exc = 1, curl++;
                if (curl > n) {ok =false; break;}
            }
            if (a[i + 1] != exc) {ok = false; break;}
            val = a[i + 1];
        }
        cout << (ok ? 1 : 0) << '\n';
    }
}