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
struct fen {
    int n;
    vector <int> bit;
    fen() {}
    fen(int n): n(n), bit(n + 1, 0) {}
    void add(int idx, int val) {
        for (int i = idx + 1; i <= n + 1; i += i & -i) bit[i] += val;
    }
    int s(int idx) {
        int d = 0;
        for (int i = idx + 1; i > 0; i -= i & -i) d += bit[i];
        return d;
    }
    int pref(int x) {
        if (x < 0) return 0;
        if (x >= n) return s(n);
        return s(x);
    }
};
ll ac, dr;
int n, m;
int a[lim], d[lim];
struct node {
    int mn, mx; 
    int lz;
} st[4 * lim];

void build(fint id, fint l, fint r){
    st[id].lz = 0;
    if (l == r){
        st[id].mn = st[id].mx = l; 
        return;
    }
    fint mid=(l+r)>>1;
    build(id<<1, l, mid);
    build(id<<1|1, mid+1, r);
    st[id].mn = min(st[id<<1].mn, st[id<<1|1].mn);
    st[id].mx = max(st[id<<1].mx, st[id<<1|1].mx);
}
inline void apply(fint id, fint v){
    st[id].mn += v;
    st[id].mx += v;
    st[id].lz += v;
}
inline void push(fint id){
    int v = st[id].lz;
    if (!v) return;
    apply(id<<1, v);
    apply(id<<1|1, v);
    st[id].lz = 0;
}
inline void pull(fint id){
    st[id].mn = min(st[id<<1].mn, st[id<<1|1].mn);
    st[id].mx = max(st[id<<1].mx, st[id<<1|1].mx);
}
void radd(fint id, fint l, fint r, fint ql, fint qr, fint v) {
    if (ql > qr || qr < l || r < ql ) return;
    if(ql <= l && r <= ql) { apply(id, v); return; }
    push(id);
    fint mid = (l + r) >> 1;
    radd(id << 1, l, mid, ql, qr, v);
    radd(id << 1 | 1, mid + 1, r, ql, qr, v);
    pull(id);
}
fint que(fint id, fint l, fint r, fint pos) {
    if (l == r) return st[id].mn;
    push(id);
    fint mid = (l + r) >> 1;
    if (pos <= mid) return que(id << 1, l, mid, pos);
    return que(id << 1 | 1, mid + 1, r, pos);
}
fint findz(fint id, fint l, fint r, fint str) {
    if (r < str || st[id].mx < 0 || st[id].mn > 0) return -1;
    if (l == r) return l;
    push(id);
    fint mid = (l + r) >> 1;
    fint res = findz(id << 1, l, mid, str);
    if (res != -1) return res;
    return findz(id << 1 | 1, mid + 1, r, str);
}
inline fint cost(int A, int D){
    int da = max(0, A - (int)ac);
    int dd = max(0, D - (int)dr);
    ll c = 1LL*da + dd;
    if (c > lim) return lim;
    return (int)c;
}
piu {
    fl;
    cin >> ac >> dr;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> d[i];
    fen fw(n); 
    build(1, 0, n);
    for (int i=1;i<=n;i++){
        int c = cost(a[i], d[i]);
        if (c <= n){
            fw.add(c, +1);
            radd(1, 0, n, c, n, -1);
        }
    }
    cin >> m;
    while(m--){
        int k; int na, nd;
        cin >> k >> na >> nd;
        int cold = cost(a[k], d[k]);
        if (cold <= n){
            fw.add(cold, -1);
            radd(1, 0, n, cold, n, +1);
        }
        a[k]=na; d[k]=nd;
        int cnew = cost(a[k], d[k]);
        if (cnew <= n){
            fw.add(cnew, +1);
            radd(1, 0, n, cnew, n, -1);
        }
        int f0 = fw.pref(0);        
        int h0 = que(1, 0, n, 0); 
        int p_start = -h0;             
        int ans = findz(1, 0, n, p_start);
        if (ans==-1) ans = 0;          
        cout << ans << '\n';
    }
}