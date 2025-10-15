#include <bits/stdc++.h>
#define fl ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define piu signed main()
#define fi first
#define se second
#define ld long double
#define pii pair<fint, fint>
#define pll pair<long long, long long>
#define vl vector<ll>
#define vvl vector<vl>
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) x.size())
#pragma GCC optimize ("Ofast","unroll-loops")
#pragma GCC target ("avx2")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef int_fast64_t fint;
const ll maxN = 30, lim = 5e5 + 5, mod = 1e9 + 7, N = 2e5 + 5;
piu {
    fl;
    fint n; cin >> n;
    fint dp[n +1] = {0};
    dp[0] = 1, dp[1] = 1;
    for (ll i = 4; i <= n ; i++) {
        dp[i] = (i + 1) * dp[i - 1] - (i - 2) * dp[i -2] - (i - 5) * dp[i - 3] - (i - 3) * dp[i - 4];
        dp[i] %= mod;
        dp[i] = (dp[i] + mod) % mod;
    }
    cout << dp[n];
    
}