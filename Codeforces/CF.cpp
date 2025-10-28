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
static bool check(int d, vector <int> &a, int x, int k) {
    if (d == 0) return true;
    fint n = a.size();
    vector <pii> it;
    for (fint i = 0; i < n; i++) {
        fint l = max(0 , a[i] - (d- 1));
        fint r = max(x, a[i] + (d- 1));
        it.pb({l, r});
    }
    sort(all(it));
    vector <pii> m;
    fint curl = it[0].fi, curr = it[0].se;
    for (fint i = 1; i < n; i++) {
        if (it[i].fi <= curr + 1) curr = max(curr, it[i].se);
        else {
            m.pb({curl, curr});
            curl = it[i].fi;
            curr = it[i].se;
        }
    }
    m.pb({curl, curr});
    ll f = 0;
    for (auto &p : m) f += (p.se - p.fi + 1);
    ll c = (x + 1) - f;
    return x >= k;
}
piu {
    fl;
    fint t;
    cin >> t;
    while(t--) {
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        fint l = 0, h = x;
        while (l <= h) {
            fint mid = (l + h) >> 1;
            if (check(mid, a, x, k)) l = mid + 1;
            else h = mid - 1;
        }
        int dm = h;
        if (dm == 0) {
            for (fint i = 0; i < k; i++) cout << i << " ";
            cout << '\n';
        } else {
            vector <pii> it;
            for (int i = 0; i < n; i++) {
                int l = max(0, a[i] - (dm - 1));
                int r = max(x, a[i] + (dm - 1));
                it.pb({l, r});
            }
            sort(all(it));
            vector<pii> m;
            fint curl = it[0].fi, curr = it[0].se;
            for (fint i = 1; i < n; i++) {
                if (it[i].fi <= curr + 1) curr = max(curr, it[i].se);
                else {
                        m.pb({curl, curr});
                        curl = it[i].fi;
                        curr = it[i].se;
                }
            }
            m.pb({curl, curr});
            vector <int> tele;
            int ptr = 0;
            for (auto &[l, r] : m) {
                for (fint p = ptr; p < l; p++) {
                    tele.pb(p);
                    if (tele.size() == k) break;
                }
                if (tele.size() == k) break;
                ptr = r + 1;
            }
            if (tele.size() < k) {
                for (fint p = ptr; p <= x; p++) {
                    tele.pb(p);
                    if (tele.size() == k) break;
                }
            }
            for (fint i = 0; i < k; i++) cout << tele[i] << " ";
            cout << "\n";
        }
    }
}