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
bool tg (double a, double b, double c) {
    return a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a;
}
bool deu (double a, double b, double c) {
    return fabs(a - b) < 1e-9 && fabs(b - c) < 1e-9;
}
bool canh (double a, double b, double c) {
    return fabs(a - b) < 1e-9 || fabs(b - c) < 1e-9 || fabs(a - c) < 1e-9;
}
bool vuong (double a, double b, double c) {
    double x[3] = {a, b, c};
    sort(x, x + 3);
    return fabs(x[2]*x[2] - (x[0]*x[0] + x[1]*x[1])) < 1e-9;
}
bool tu (double a, double b, double c) {
    double x[3] = {a, b, c};
    sort(x, x + 3);
    return x[2]*x[2] > x[0]*x[0] + x[1]*x[1];
}
bool nhon (double a, double b, double c) {
    double x[3] = {a, b, c};
    sort(x, x + 3);
    return x[2]*x[2] < x[0]*x[0] + x[1]*x[1];
}
Piu {
    fl;
    fint a, b, c;
    cin >> a >> b >> c;
    if (!tg(a, b, c)) {
        cout << "NO";
        return 0;
    }
    cout << fixed << setprecision(2);
    if (deu(a, b, c)) cout << "TAM GIAC DEU" << ' ' << a * a * sqrt(3) / 4;
    else if (vuong(a, b, c)) {
        double x[3] = {a, b, c};
        sort(x, x + 3);
        cout << "TAM GIAC VUONG" << ' ' << x[0] * x[1] / 2;
    }
    else if (canh(a, b, c)) cout << "TAM GIAC CAN";
    else if (tu(a, b, c)) cout << "TAM GIAC TU";
    else if (nhon(a, b, c)) cout << "TAM GIAC NHON";
}