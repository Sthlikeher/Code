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
const ll maxN = 500005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, MOD = 998244353, nmax = 1e7 + 5;
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        cin >> n;
        vl a(n + 1);
        for (fint i = 1; i <= n; i++) cin >> a[i], a[i] %= 3;
        vl pre(n + 1, 0);
        for (fint i = 1; i <= n; i++) pre[i] = (pre[i - 1] + a[i]) % 3;
        if (pre[n] % 3 != 0) {
            cout << "0 0\n";
            continue;
        }
        bool ok = false;
        for (fint l = 1; l <= n - 2 && !ok; l++) {
            for (fint r = l + 1; r <= n - 1 && !ok; r++) {
                fint s1 = pre[l];
                fint s2 = (pre[r] - pre[l]) % 3;
                if (s2 < 0) s2 += 3;
                fint s3 = (pre[n] - pre[r]) % 3;
                if (s3 < 0) s3 += 3;
                bool equal = (s1 == s2 && s2 == s3);
                bool dis = (s1 != s2 && s1 != s3 && s2 != s3);
                if (equal || dis) {
                    cout << l << ' ' << r << "\n";
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) cout << "0 0\n";
    }
}