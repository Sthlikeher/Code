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
const ll maxN = 500005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, MOD = 998244353, nmax = 1e7 + 5;
fint cost(vl &a) {
    fint n = sz(a), end = -1, mx = a[0];
    for (fint i = 1; i < n; i++) {
        if (a[i] < mx) end = i;
        else mx = a[i];
    }
    if (end == -1) return 0;
    fint s = -1, mn = a[n - 1];
    for (fint i = n - 2; i >= 0; i--) {
        if (a[i] > mn) s = i;
        else mn = a[i];
    }
    return end - s + 1;
}
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        cin >> n;
        vl p(n);
        vector<bool> pre(n + 1, false);
        for (fint i = 0; i < n; i++) {
            cin >> p[i];
            if (p[i] != 0) pre[p[i]] = true;
        }
        vl miss;
        for (fint i = 1; i <= n; i++) if (!pre[i]) miss.pb(i);
        sort(allr(miss));
        vl z;
        for (fint i = 0; i < n; i++) if (p[i] == 0) z.pb(i);
        sort(all(z));
        vl a = p;
        for (size_t i = 0; i < z.size(); i++) a[z[i]] = miss[i];
        cout << cost(a) << '\n';
    }
}