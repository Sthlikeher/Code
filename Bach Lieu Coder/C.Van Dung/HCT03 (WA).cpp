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
    vl a(n), b(n);
    for (ll i = 0; i < n; i++) cin >> a[i] >> b[i];
    sort(all(a)), sort(all(b));
    bool ua[1000], ub[1000];
    memset(ua, false, sizeof(ua));
    memset(ub, false, sizeof(ub));
    ll w = 0, d = 0;
    for (ll i = 0; i < n; i++) {
        ll bi = -1;
        for (ll j = 0; j < n; j++) {
            if (!ua[j] && a[j] < b[i]) {
                if (bi == -1 || a[j] > a[bi]) bi = j; 
            }
        }
        if (bi != -1) w++, ua[bi] = true, ub[i] = true;
    }
    for (ll i = 0; i < n; i++) {
        if (!ub[i]) {
            for (ll j = 0; j < n; j++) {
                if (!ua[j] && a[j] == b[i]) {
                    d++, ua[j] = true, ub[i] = true;
                    break;
                }
            }
        }
    }
    cout << 2 * w + d;
}