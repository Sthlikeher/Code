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
        fint n;
        cin >> n;
        vl a(n);
        for (fint &x : a) cin >> x;
        vl f(n + 1, 0);
        for (fint x : a) f[x]++;
        vl F;
        for (fint x = 1; x <= n; x++) if (f[x] > 0) F.eb(f[x]);
        fint mx_f = *max_element(all(F));
        fint res = 0;
        for (fint i = 1; i <= mx_f; i++) {
            fint k = 0;
            for (fint j : F) {if (j >= i) k++;}
            res = max(res, k * i);
        }
        cout << res << '\n';
    }
}