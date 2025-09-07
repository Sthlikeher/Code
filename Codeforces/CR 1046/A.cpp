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
const ll maxN = 200005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, mod = 998244353;
bool f(ll x, ll y) {
    ll mx = max(x, y), mn = min(x, y);
    return mx <= 2 * (mn + 1);
}
Piu {
    fl;
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        bool f1 = f(a, b);
        bool f2 = f(c - a, d - b);
        cout << (f1 && f2 ? "YES" : "NO") << '\n';
    }
}