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
        ll l, r;
        cin >> l >> r;
        ll n = r - l + 1;
        vl a(n);
        iota(all(a), l);
        ll L = 0, R = n;
        for (fint i = 29; i >= 0; i--) {
            fint x = L;
            while (x < R && (~(a[x] >> i) & 1)) x++;
            if (x - L < R - x) {
                fint m = 2 * x - L;
                reverse(a.begin() + L, a.begin() + m);
                L = m;
            } else {
                fint m = 2 * x - R;
                reverse(a.begin() + m, a.begin() + R);
                R = m;
            }
        }
        ll res = 0;
        for (fint i = 0; i < n; i++) {
            res += a[i] | (l + i);
        }
        cout << res << '\n';
        for (fint i = 0; i < n; i++) cout << a[i] << " " [i == n - 1];
        cout << '\n';
    }
}