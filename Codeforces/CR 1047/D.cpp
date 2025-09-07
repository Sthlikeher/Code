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
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vl a(n);
        for (ll &i : a) cin >> i;
        vl f(n + 1, 0);
        for (ll i = 0; i < n; i++) if (a[i] <= n) f[a[i]]++;
        bool val = true;
        for (ll i = 1; i <= n; i++) {
            if (f[i] % i != 0) {
                val = false;
                break;
            }
        }
        if (!val) {
            cout << -1 << '\n';
            continue;
        }
        vl k(n + 1, 0), base(n + 1, 0);
        ll tot = 0;
        for (ll i = 1; i <= n; i++) {
            if (f[i] > 0) k[i] = f[i] / i, base[i] = tot + 1, tot += k[i];
        }
        vl cur(n + 1, 0), res(n);
        for (ll i = 0; i < n; i++) {
            fint x = a[i];
            cur[x]++;
            fint dis = (cur[x] - 1) % k[x];
            res[i] = base[x] + dis;
        }
        for (ll i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << res[i];
        }
        cout << '\n';
    }
}