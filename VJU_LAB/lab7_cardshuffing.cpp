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
const ll maxN = 500005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, MOD = 998244353; 
Piu {
    fl;
    ll n;
    cin >> n;
    ll t = 2 * n;
    vl a;
    for (ll i = 1; i <= t; i++) a.push_back(i);
    vvl v;
    v.push_back(a);
    vl cur = a;
    while (true) {
        vl nd;
        for (ll i = 0; i < n; i++) {
            nd.push_back(cur[n + i]);
            nd.push_back(cur[i]);
        }
        cur = nd;
        v.push_back(cur);
        if (cur == a) { break; }
    }
    cout << v.size() - 1 << '\n';
    for (const auto& x: v) {
        for (ll card : x) cout << card << " ";
        cout << '\n';
    }
}