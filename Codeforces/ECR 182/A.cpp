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
        vl a(n + 1), cnt(n + 1);
        for (fint i = 1; i <= n; i++) cin >> a[i];
        for (fint i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + a[i];
        for (fint l = 1; l < n; l++) {
            for (fint r = l + 1; r < n; r++) {
                set <fint> st;
                st.insert(cnt[l] % 3);
                st.insert((cnt[r] - cnt[l]) % 3);
                st.insert((cnt[n] - cnt[r]) % 3);
                if (st.size() == 1 || st.size() == 3) {
                    cout << l << " " << r << '\n';
                    goto end;
                }
            }
        }
        cout << "0 0\n";
        end:;
    }
}