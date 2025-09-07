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
const ll maxN = 200005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, mod = 998244353;
Piu {
    fl;
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n+1);
        for (ll i = 1; i <= n; i++) cin >> a[i];
        vector<ll> dp(n+1, 0);
        vector<vector<ll>> v(n+1);
        for (ll i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            ll k = a[i];
            if (k > n) {
            } else {
                if (k == 1) {
                    dp[i] = max(dp[i], dp[i-1] + 1);
                } else {
                    ll m = v[k].size();
                    if (m >= k-1) {
                        ll j = v[k][m - (k-1)];
                        dp[i] = max(dp[i], dp[j-1] + k);
                    }
                }
            }
            if (a[i] <= n) v[a[i]].push_back(i);
        }
        cout << dp[n] << "\n";
    }
}