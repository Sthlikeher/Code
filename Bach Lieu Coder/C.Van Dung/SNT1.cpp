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
ll p[nmax];
void sieve() {
    fill (p, p + nmax, 1);
    p[0] = p[1] = 0;
    for (ll i = 2; i * i < nmax; i++) 
        if (p[i]) 
            for (ll j = i * i; j < nmax; j += i)  p[j] = 0;
}
Piu {
    fl;
    sieve();
    string s;
    cin >> s;
    ll cnt = 0;
    for (char c : s) if (isdigit(c)) cnt++;
    ll res = 0, cur = 0;
    bool ch = false;
    for (char c : s) {
        if (isdigit(c)) {
            if (!ch) cur = c - '0', ch = true;
            else cur = cur * 10 + (c - '0');
        } else {
            if (ch) {
                if (cur > 0 && p[cur]) res = max(res, cur);
                ch = false;
            }
        }
    }
    if (ch && cur > 0 && p[cur]) res = max(res, cur);
    cout << cnt << '\n' << res;
}