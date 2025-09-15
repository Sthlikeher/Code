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
typedef __uint128_t u128;
const ll maxN = 500005, lim = 1e6 + 5, bits = 30, inf = 1 << bits, MOD = 998244353, nmax = 1e7 + 5;
fint binp(fint b, fint e, fint mod) {
    fint res = 1;
    b %= mod;
    while (e) {
        if (e & 1) res = (u128)res * b % mod;
        b = (u128)b * b % mod, e >>= 1;
    }
    return res;
}
bool check(fint n, fint a, fint d, int s) {
    fint x = binp(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (ll i = 1; i < s; i++) {
        x = (u128)x * x % n;
        if (x == n - 1) return false;
    }
    return true;
}
bool miller(fint n, int it = 5) {
    if (n < 4) return n == 2 || n == 3;
    int s = 0;
    fint d = n - 1;
    while ((d & 1) == 0) d >>= 1, s++;
    for (int i = 0; i < it; i++) {
        int a = 2 + rand() % (n - 3);
        if (check(n, a, d, s)) return false;
    }
    return true;
}
Piu {
    fl;
    fint n;
    cin >> n;
    if (miller(n)) cout << "YES\n";
    else cout << "NO\n";
}