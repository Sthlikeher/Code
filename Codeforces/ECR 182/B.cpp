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
const ll maxN = 500005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, MOD = 998244353, nmax = 1e7 + 5;
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        cin >> n;
        vector <fint> a(n);
        for (fint &i : a) cin >> i;
        vector <fint> not_ex;
        {
            vector <bool> f(n + 1, false);
            for (fint i = 0; i < n; i++) f[a[i]] = true;
            for (fint i = 1; i <= n; i++) if (!f[i]) not_ex.eb(i);
        }
        for (fint i = 0; i < n; i++) {
            if (a[i] == 0) {
                a[i] = not_ex.back();
                not_ex.pop_back();
            }
        }
        fint l = 0, r = n - 1;
        while (l < n && a[l] == l + 1) l++;
        while (r >= 0 && a[r] == r + 1) r--;
        cout << max<fint>(0, r - l + 1) << '\n';
    }
}
