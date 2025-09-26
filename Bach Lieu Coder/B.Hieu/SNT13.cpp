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
#pragma GCC target ("avx2")
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
Piu{
    fl;
    sieve();
    ll n;
    cin >> n;
    ll res = 0;
    bool c = false;
    while (n > 0) {
        ll dg = n % 10;
        if (p[dg]) res += dg, c = true;
        n /= 10;
    }
    if (c) cout << res;
    else cout <<  "-1\n";
}