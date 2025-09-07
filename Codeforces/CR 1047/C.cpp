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
Piu {
    fl;
    fint t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (b % 2 == 1) {
            if (a % 2 == 1) cout << a * b + 1 << '\n';
            else cout << -1 << '\n';
        } else {
            if (a % 2 == 0) cout << a * (b / 2) + 2 << '\n';
            else {
                if (b % 4 == 0) cout << a * (b / 2) + 2 << '\n';
                else cout << -1 << '\n';
            }
        }
    }
}