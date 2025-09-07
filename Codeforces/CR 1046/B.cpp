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
        ll n, k;
        string s;
        cin >> n >> k >> s;
        ll r = 0;
        bool b = false;
        for (char c : s) {
            if (c == '1') { r++; if (r >= k) { b = true; break; } }
            else r = 0;
        }
        if (b) { cout << "NO\n"; continue; }
        cout << "YES\n";
        vector<int> p(n);
        ll v = n;
        for (ll i = 0; i < n; ++i) if (s[i] == '0') p[i] = v--;
        for (ll i = 0; i < n; ++i) if (s[i] == '1') p[i] = v--;
        for (ll i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << p[i];
        }   
        cout << '\n';
    }
}