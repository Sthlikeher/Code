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
fint check (fint n) {
    return n == 6 || n == 28;
}
fint sd (fint n) {
    fint s = 0;
    while (n) s += n % 10, n /= 10;
    return s;
}
Piu {
    fl;
    fint n;
    cin >> n;
    fint cnt = 0;
    for (ll i = 1; i <= n; i++) {
        fint x;
        cin >> x;
        if (check(sd(x))) cnt++;
    }
    cout << cnt;
}