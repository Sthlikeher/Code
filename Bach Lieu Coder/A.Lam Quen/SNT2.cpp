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
ll rabin(ll n) {
    if (n < 2) return 0;
    if (n < 4) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (ll i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return 0;
    return 1;
} 
Piu {
    fl;
    sieve();
    fint n;
    cin >> n;
    cout << (rabin(n) ? "YES" : "NO");
}