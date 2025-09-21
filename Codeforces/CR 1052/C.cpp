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
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        string s;
        cin >> n >> s;
        vl st, non_st;
        for (fint i = 0; i < n; i++) {
            if (s[i] == '1') st.eb(i + 1);
            else non_st.eb(i + 1);
        }
        fint k = sz(st);
        if (k == 0) {
            cout << "YES\n";
            for (fint i = n; i >= 1; i--) cout << i << (i == 1 ? '\n' : ' ');
            continue;
        }
        vl seg;
        fint cnt0 = lower_bound(all(non_st), st[0]) - non_st.begin();
        seg.eb(cnt0);
        for (fint i = 1; i < k; i++) {
            fint l = st[i - 1], h = s[i];
            fint l_idx = upper_bound(all(non_st), l) - non_st.begin();
            fint r_idx = lower_bound(all(non_st), h) - non_st.begin();
            seg.eb(r_idx - l_idx);
        }
        fint cnt = sz(non_st) - (upper_bound(all(non_st), st.back()) - non_st.begin());
        seg.eb(cnt);
        bool imp = false;
        for (fint x : seg) {
            if (x == 1) {
                imp = true;
                break;
            }
        }
        if (imp) {
            cout << "NO\n";
            break;
        }
        vvl seg_val;
        seg_val.reserve(sz(seg));
        fint idx = 0;
        for (fint c : seg) {
            seg_val.eb(non_st.begin() + idx, non_st.begin() + idx + c);
            idx += c;
        }
        vl ins;
        ins.reserve(k);
        ins.eb(seg[0] + 1);
        for (fint i = 1; i < k; i++) ins.eb(ins.back() + seg[i] + 1);
        vl res(n + 1);
        for (fint i = 0; i < k; i++) res[ins[i]] = st[i];
        {
            auto tmp = seg_val[0];
            reverse(all(tmp));
            for (fint i = 1; i < ins[0]; i++) res[i] = tmp[i - 1];
        }
        for (fint i = 1; i < k; i++) {
            auto tmp = seg_val[i];
            reverse(all(tmp));
            fint start = ins[i - 1] + 1;
            fint end = ins[i] - 1;
            for (fint j = start; j <= end; j++) res[j] = tmp[j - start];
        }
        {
            auto tmp = seg_val.back();
            reverse(all(tmp));
            fint start = ins.back() + 1;
            for (fint j = start; j <= n; j++) res[j] = tmp[j - start];
        }
        cout << "YES\n";
        for (fint i = 1; i <= n; i++) cout << res[i] << (i == n ? '\n' : ' ');
    }
}