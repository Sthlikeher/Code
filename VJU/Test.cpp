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
piu {
    fl;
    string s;
    getline(cin, s);
    ull t = 0, cur = 0;
    bool ch = false;
    for (char c : s) {
        if (isdigit(c)) cur = cur * 10 + (c - '0'), ch = true;
        else if (ch) t += cur, cur = 0, ch = false;
    }
    if (ch) t += cur;
    cout << t;
}