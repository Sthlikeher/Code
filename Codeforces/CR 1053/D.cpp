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
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef int_fast64_t fint;
typedef __uint128_t u128; 
const ll maxN = 2e5, lim = 1e6 + 5, bits = 30, inf = 1 << bits, MOD = 998244353, nmax = 1e7 + 5;
fint binp(fint b, fint e) {
    fint res = 1;
    b %= MOD;
    while (e) {
        if (e & 1) res = (u128)res * b % MOD;
        b = (u128)b * b % MOD, e >>= 1;
    }
    return res;
}
struct comb {
    vl fact, invfact;
    comb(int n=0){init(n);}
    void init(int n){
        fact.assign(n+1,1);
        for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%MOD;
        invfact.assign(n+1,1);
        invfact[n]=binp(fact[n], MOD-2);
        for(int i=n;i>0;i--) invfact[i-1]=invfact[i]*i%MOD;
    }
    ll C(fint n,fint k){
        if(k<0||k>n) return 0;
        return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
    }
};
Piu {
    fl;
    fint t;
    cin >> t;
    comb cb(maxN);
    while (t--) {
        fint n;
        cin >> n;
        vl a(n + 1);
        ll sA = 0;
        for (fint i = 1; i <= n; i++) {
            cin >> a[i];
            sA += a[i];
        }
        if (sA !=n) {
            cout << "0\n";
            continue;
        }
        fint R= (n + 1) / 2;
        bool ok = true;
        for (fint i = R + 1; i <= n; i++) if (a[i] != 0) {ok = false; break;}
        if (!ok) {cout << "0\n"; continue;}
        auto c_of = [&](fint r)->fint{
            if (n % 2 == 1 && r == R) return 1; 
            return 2;
        };
        ll res = 1;
        fint av = 0;
        for (fint r = R; r >= 1; r--) {
            fint cr = c_of(r);
            av += cr;
            if (a[r] > av) {ok = false; break;}
            res = res * cb.C(av, a[r]) % MOD;
            av -= a[r];
        }
        if(!ok) cout<<"0\n";
        else cout<<res % MOD<<"\n";
    }
}