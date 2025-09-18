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
    fint t;
    cin >> t;
    while (t--) {
        fint n;
        cin >> n;
        vector<vl> g(n + 1);
        vl in(n + 1, 0);
        for (fint i = 0; i < n - 1; i++) {
            fint u, v, x, y;
            cin >> u >> v >> x >> y;
            if (x > y) {
                g[u].eb(v);
                in[v]++;
            } else {
                g[v].eb(u);
                in[u]++;
            }
        }
        queue<fint> q;
        for (fint i = 1; i <=n; i++) if (in[i] == 0) q.push(i);
        vl topo;
        while (!q.empty()) {
            fint u = q.front();
            q.pop();
            topo.eb(u);
            for (fint v : g[u]) {
                in[v]--;
                if (in[v] == 0) q.push(v);
            }
        }
        vl res(n + 1);
        fint num = n;
        for (fint v : topo) {
            res[v] = num;
            num--;
        }
        for (fint i = 1; i <= n; i++) cout << res[i] << " ";
        cout << '\n';
    }
}