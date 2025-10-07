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
const ll maxN = 30, lim = 5e5 + 5, mod = 998244353;
piu {
    fl;
    fint n;
    cin >> n;
    if (n >= 0) {
        if (n >= 9) cout << "Xuat sac\n";
        else if (n >= 8 && n < 9) cout << "Gioi\n";
        else if (n >= 7 && n < 8) cout << "Kha\n";
        else if (n >= 6 && n < 7) cout << "Trung Binh Kha\n";
        else if (n >= 5 && n < 6) cout << "Trung Binh\n";
        else cout << "Yeu\n";
    } else cout << "Nhap diem khong hop le\n";
}