#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-15 15:16:08
constexpr int inf = int(2e9) + 1;
constexpr int N = 2e5 + 5;
struct node{
    int min[10], ans;
    node(){
        for(int i = 0; i < 10; i++) min[i] = inf;
        ans = inf;
    }
};
node seg[N << 2];
array<int, N> a;
node merge(const node &x, const node &y){
    node z;
    z.ans = min(x.ans, y.ans);
    for(int i = 0; i < 10; i++){
        if(x.min[i] <= 1e9 && y.min[i] <= 1e9)
            z.ans = min(z.ans, x.min[i] + y.min[i]);
        // z.min[i] = min({z.min[i], x.min[i], y.min[i]});
        z.min[i] = min(x.min[i], y.min[i]);
    }
    return z;
}
void build(int p, int l, int r){
    if(l == r){
        for(int i = 0, x = a[l]; x; x /= 10, i++){
            if(x % 10) seg[p].min[i] = a[l];
            else seg[p].min[i] = inf;
        }
        seg[p].ans = inf;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
}
void upd(int p, int l, int r, int i, int val){
    if(l == r){
        for(int i = 0, x = val; i < 10; x /= 10, i++){
            if(x % 10) seg[p].min[i] = val;
            else seg[p].min[i] = inf;
        }
        seg[p].ans = inf;
        return;
    }
    int mid = (l + r) >> 1;
    if(i <= mid) upd(p << 1, l, mid, i, val);
    else upd(p << 1 | 1, mid + 1, r, i, val);
    seg[p] = merge(seg[p << 1], seg[p << 1 | 1]);
}
node query(int p, int l, int r, int lx, int rx){
    if(l >= lx && r <= rx) return seg[p];
    int mid = (l + r) >> 1;
    node res;
    if(lx <= mid) res = merge(res, query(p << 1, l, mid, lx, rx));
    if(rx > mid) res = merge(res, query(p << 1 | 1, mid + 1, r, lx, rx));
    return res;
}
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(m--){
        int op; cin >> op;
        if(op == 1){
            int i, x; cin >> i >> x;
            upd(1, 1, n, i, x);
        }else{
            int l, r; cin >> l >> r;
            node res = query(1, 1, n, l, r);
            cout << (res.ans == inf ? -1 : res.ans) << '\n';
        }
    }
}
int main(){
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    {solve();} return 0;
}