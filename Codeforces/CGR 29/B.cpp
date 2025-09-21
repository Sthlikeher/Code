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
    while (t--) {
        fint n;
        cin >> n;
        fint m = 2 * n;
        vl a(m + 1, 0);
        vector <char> used(m + 1, 0);
        fint cur = 1;
        for (fint x = n; x >= 1; --x) {
            while (used[cur]) ++cur;
            fint i = cur, j = i + x;
            while (j <= m && used[j]) j += x;
            a[i] = a[j] = x;
            used[i] = used[j] = 1;
        }
        for (fint i = 1; i <= m; i++) {
            if (i > 1) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
}