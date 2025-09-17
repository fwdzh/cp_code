#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > g;
constexpr int N = 100005;
int dfn[N], son[N], siz[N], top[N], dep[N], fa[N], cntd;
void dfs1(int u, int p){
    siz[u] = 1, dep[u] = dep[p] + 1, fa[u] = p;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs1(v, u);
        if(siz[v] > siz[son[u]]) son[u] = v;
        siz[u] += siz[v];
    }
}
void dfs2(int u){
    dfn[u] = ++cntd;
    top[u] = son[fa[u]] == u ? top[fa[u]] : u;
    if(son[u]) dfs2(son[u]);
    for(auto v : g[u]){
        if(v == son[u] || v == fa[u]) continue;
        dfs2(v);
    }
}
struct node{
    int sum, lazy;
    node(){sum = 0; lazy = -1;}
};
node seg[N << 2];
void push_down(int p, int l, int r){
    if(seg[p].lazy != -1){
        int mid = (l + r) >> 1;
        seg[p << 1].sum = (mid - l + 1) * seg[p].lazy;
        seg[p << 1 | 1].sum = (r - (mid + 1) + 1) * seg[p].lazy;
        seg[p << 1].lazy = seg[p << 1 | 1].lazy = seg[p].lazy;
        seg[p].lazy = -1;
    }
}
void upd(int p, int l, int r, int lx, int rx, int x){
    if(l >= lx && r <= rx){
        seg[p].sum = (r - l + 1) * x;
        seg[p].lazy = x;
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if(lx <= mid) upd(p << 1, l, mid, lx, rx, x);
    if(rx > mid) upd(p << 1 | 1, mid + 1, r, lx, rx, x);
    seg[p].sum = seg[p << 1].sum + seg[p << 1 | 1].sum;
}
int query(int p, int l, int r, int lx, int rx){
    if(l >= lx && r <= rx) return seg[p].sum;
    int res = 0, mid = (l + r) >> 1;
    push_down(p, l, r);
    if(lx <= mid) res += query(p << 1, l, mid, lx, rx);
    if(rx > mid) res += query(p << 1 | 1, mid + 1, r, lx, rx);
    return res;
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q; cin >> n >> q;
    g.assign(n + 1, {});
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1);
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int res = 0;
        int x = a, y = b;
        while(top[x] != top[y]){
            if(dep[top[x]] < dep[top[y]]) swap(x, y);
            upd(1, 1, n, dfn[top[x]], dfn[x], 1);
            res += dfn[x] - dfn[top[x]] + 1;
            x = fa[top[x]];
        }
        if(dep[x] > dep[y]) swap(x, y);
        upd(1, 1, n, dfn[x], dfn[y], 1);
        res += dfn[y] - dfn[x] + 1;
        x = c, y = d;
        while(top[x] != top[y]){
            if(dep[top[x]] < dep[top[y]]) swap(x, y);
            res -= query(1, 1, n, dfn[top[x]], dfn[x]);
            res += dfn[x] - dfn[top[x]] + 1;
            x = fa[top[x]];
        }
        if(dep[x] > dep[y]) swap(x, y);
        res -= query(1, 1, n, dfn[x], dfn[y]);
        res += dfn[y] - dfn[x] + 1;
        cout << res << '\n';

        x = a, y = b;
        while(top[x] != top[y]){
            if(dep[top[x]] < dep[top[y]]) swap(x, y);
            upd(1, 1, n, dfn[top[x]], dfn[x], 0);
            x = fa[top[x]];
        }
        if(dep[x] > dep[y]) swap(x, y);
        upd(1, 1, n, dfn[x], dfn[y], 0);
    }
    return 0;
}