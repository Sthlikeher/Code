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
typedef __uint128_t u128;
const ll maxN = 500005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, MOD = 998244353, nmax = 1e7 + 5;
Piu {
    fl;
    fint t ;
    cin >> t;
    while (t--) {
        fint n, m;
        string s;
        cin >> n >> m;
        cin >> s;
        vl a(m);
        for (fint &i : a) cin >> i;
        sort(all(a));
        set <ll> bs(all(a));
        for (fint i = 1; i <= n; i++) {
            ll cur = 1;
            for (fint j = 0; j < i; j++) {
                if (s[j] == 'A') cur++;
                else {
                    ll can = cur + 1;
                    auto it = bs.lower_bound(can);
                    while (it != bs.end() && *it == can) can++, it++;
                    cur = can;
                }
            }
            bs.insert(cur);
        }
        vl bc(all(bs));
        cout << bc.size() << "\n";
        if (!bc.empty()) {
            for (fint i = 0; i < bc.size(); i++) {
                if (i > 0) cout << " ";
                cout << bc[i];
            }
            cout << "\n";
        } else cout << "\n";
    }
}