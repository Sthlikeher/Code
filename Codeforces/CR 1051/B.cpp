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
    while(t--) {
        fint n, k;
        cin >> n >> k;
        vl a(n);
        for (fint &i : a) cin >> i;
        vl b(k);
        for (fint &i : b) cin >> i;
        sort(allr(a));
        sort(all(b));
        ll tot = 0;
        for (ll v : a) tot += v;
        ll fs = 0, pos = 0;
        for (fint i = 0; i < k && pos < n; i++) {
            if (pos + b[i] <= n) {
                fs += a[pos + b[i] - 1];
                pos += b[i];
            } else break;
        }
        cout << tot - fs << '\n';
    }
}