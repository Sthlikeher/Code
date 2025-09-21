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
        fint n, m;
        cin >> n >> m;
        vvl s(n);
        vl f(m + 1, 0 );
        ll ls = 0;
        for (fint i = 0; i < n; i++) {
            fint li; cin >> li;
            s[i].resize(li);
            for (fint j = 0; j < li; j++) {
                fint x; cin >> x;
                s[i][j] = x;
                ++f[x];
            }
            ls += li;
        }
        bool c = true;
        for (fint i = 1; i <= m; i++) if (f[i] == 0) {c = false; break;}
        if (!c) {
            cout << "NO\n";
            continue;
        }
        fint r = 0;
        for (fint i = 0; i < n; i++) {
            bool p = false;
            for (fint x : s[i]) {
                if (f[x] == 1) {p = true; break;}
            }
            if (!p) ++r;
        }
        cout << (r >= 2 ? "YES\n" : "NO\n");
    }
}