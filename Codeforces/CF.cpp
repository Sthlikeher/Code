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
typedef  __uint128_t u128;
const ll maxN = 30, lim = 1e7 + 7, mod = 1e9 + 7, N = 2e5 + 5, base = 131, inf = (1ULL << 62);
struct op {
    fint l, r;
};
bool palin(string s) {
    fint n = sz(s);
    for (fint i = 0; i < n / 2; i++) if (s[i] != s[n - 1 - i]) return false;
    return true;
}
piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector <op> ops;
        fint lim = n - 4;
        for (fint i = 0; i < lim; i++) {
            if (s[i] == t[i]) continue;
            if (s[i] == s[i + 1]) {
                ops.pb({i + 1, i + 2});
                s[i] = (s[i] == '0' ? '1' : '0');
                s[i + 1] = (s[i + 1] == '0' ? '1' : '0');
            }
            else if (s[i] == s[i + 2]) {
                ops.pb({i + 1, i + 3});
                s[i] = (s[i] == '0' ? '1' : '0');
                s[i + 1] = (s[i + 1] == '0' ? '1' : '0');
                s[i + 2] = (s[i + 2] == '0' ? '1' : '0');
            }
            else {
                ops.pb({i + 2, i + 3});
                s[i + 1] = (s[i + 1] == '0' ? '1' : '0');
                s[i + 2] = (s[i + 2] == '0' ? '1' : '0');
                ops.pb({i + 1, i + 3});
                s[i] = (s[i] == '0' ? '1' : '0');
                s[i + 1] = (s[i + 1] == '0' ? '1' : '0');
                s[i + 2] = (s[i + 2] == '0' ? '1' : '0');
            }
        }
        string s_suff = s.substr(n - 4);
        string t_suff = t.substr(n - 4);
        if (s_suff == t_suff) {
            cout << sz(ops) << '\n';
            for (auto op : ops) cout << op.l << " " << op.r << '\n';
            continue;
        }
        queue <string> q;
        q.push(s_suff);
        map <string, string> par;
        map <string, op> m;
        map <string, bool> vis;
        vis[s_suff] = true;
        par[s_suff] = "";
        bool f = false;
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            if (u == t_suff) {
                f = true;
                break;
            }
            for (fint len = 2; len <= 4; len++) {
                for (fint i = 0; i <= 4 - len; i++) {
                    string sub = u.substr(i, len);
                    if (palin(sub)) {
                        string v = u;
                        for (fint k = i; k < i + len; k++) v[k] = (v[k] == '0' ? '1' : '0');
                        if (!vis[v]) {
                            vis[v] = true;
                            par[v] = u;
                            m[v] = {(n - 4) + i + 1, (n - 4) + i + len};
                            q.push(v);
                        }
                    }
                }
            }
        }
        if (!f) {
            cout << "-1\n";
        }
        else {
            vector <op> suff_ops;
            string curr = t_suff;
            while (curr != s_suff) {
                suff_ops.pb(m[curr]);
                curr = par[curr];
            }
            reverse(suff_ops.begin(), suff_ops.end());
            for (auto op : suff_ops) ops.pb(op);
            cout << sz(ops) << '\n';
            for (auto op : ops) cout << op.l << " " << op.r << '\n';
        }
    }
}  
