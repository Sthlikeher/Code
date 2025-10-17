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
const ll maxN = 30, lim = 1e7 + 7, mod = 1e9 + 7, N = 2e5 + 5, base = 131;
piu {
    fl;
    fint m;
    cin >> m;
    if (m > 0 && m <= 12) {
        switch (m) {
        case 1:
        case 2:
        case 3:
            cout << "Quy 1.";
            break;
        case 4:
        case 5:
        case 6:
            cout << "Quy 2.";
            break;
        case 7:
        case 8:
        case 9:
            cout << "Quy 3.";
            break;
        case 10:
        case 11:
        case 12:
            cout << "Quy 4.";
            break;
        default:
            break;
        }
    }
}