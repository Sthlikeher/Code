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
const ll maxN = 200005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, mod = 998244353, neg_inf = -4e18;
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        cin >> n;
        vl a(n);
        for (fint i = 0; i < n; i++) cin >> a[i];
        ll base = 0;
        for (fint i = 0; i < n; i++) base += (i % 2 == 0 ? a[i] : -a[i]);
        ll best = 0;
        ll mineven = inf, midodd = inf;
        ll minpref = inf;
        ll maxpref = -inf;
        for (fint i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (mineven != inf) best = max(best, (ll)i - mineven);
                if (maxpref != -inf) best = max(best, maxpref - (2 * a[i] - (ll)i));
                mineven = min(mineven, (ll)i);
                minpref = min(minpref, (ll)i + 2 * a[i]);
            } else {
                if (midodd != inf) best = max(best, (ll)i - midodd);
                if (minpref != inf) best = max(best, ((ll)i + 2 * a[i]) - minpref);
                midodd = min(midodd, (ll)i);
                maxpref = max(maxpref, 2 * a[i] - (ll)i);
            }
        }
        cout << base + best << '\n';
    }
}