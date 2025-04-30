// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif

#define rep(N) for(int i = 1; i <= N; i++)

template <typename T1, typename T2>
void cmin(T1& x, const T2& y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1& x, const T2& y)
{
    x = x > y ? x : y;
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

constexpr int N = int(1e5);
int siz[N + 1], fa[N + 1], dep[N + 1], son[N + 1], top[N + 1], dfn[N + 1];

struct tree{
    int l, r, cnt, ans;
    tree(int v = 0){
        l = r = ans = v;
    }
};
tree tr[N * 50];
int cnt;
#define lson tr[p].l
#define rson tr[p].r
#define mi ((l + r) >> 1)
void push_up(int p)
{
    tr[p].cnt = max(tr[lson].cnt, tr[rson].cnt);
    if(tr[lson].cnt >= tr[rson].cnt)
        tr[p].ans = tr[lson].ans;
    else
        tr[p].ans = tr[rson].ans;
}
void update(int &p, int l, int r, int pos, int v)
{
    if(!p) p = ++cnt;
    if(l == r){
        tr[p].cnt += v;
        tr[p].ans = l;
        return;
    }
    if(pos <= mi) update(lson, l, mi, pos, v);
    else update(rson, mi + 1, r, pos, v);
    push_up(p);
}
int merge(int a, int b, int l, int r)
{
    if(!a) return b;
    if(!b) return a;
    if(l == r){
        tr[a].cnt += tr[b].cnt;
        tr[a].ans = tr[b].ans;
        return a;
    }
    tr[a].l = merge(tr[a].l, tr[b].l, l, mi);
    tr[a].r = merge(tr[a].r, tr[b].r, mi + 1, r);
    push_up(a);
    return a;
}
void ChatGptDeepSeek() // Date: 2025-04-30
{                      // Time: 08:38:13 
    int n, m;
    cin >> n >> m;
    cnt = n;
    vector<vi> g(n + 1, vi());
    vi rt(n + 1), ans(n + 1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs1 = [&](auto &&self, int u, int pre) -> void{
        dep[u] = dep[pre] + 1, siz[u] = 1, fa[u] = pre;
        for(auto v : g[u]){
            if(v == pre) continue;
            self(self, v, u);
            siz[u] += siz[v];
            if(son[u] == 0 || siz[v] > siz[son[u]])
                son[u] = v;
        }
    };
    dfs1(dfs1, 1, 0);
    int cntd = 0;
    auto dfs2 = [&](auto &&self, int u, int pre) -> void{
        dfn[u] = ++cntd;
        top[u] = (son[pre] == u) ? top[pre] : u;
        if(son[u]) self(self, son[u], u);
        for(auto v : g[u]){
            if(v == pre || v == son[u]) continue;
            self(self, v, u);
        }
    };
    dfs2(dfs2, 1, 0);
    auto LCA = [&](int x, int y){
        while(top[x] != top[y]){
            if(dep[top[x]] < dep[top[y]]) swap(x, y);
            x = fa[top[x]];
        }
        return (dep[x] < dep[y]) ? x : y;
    };
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        int lca = LCA(x, y);
        update(rt[x], 1, N, z, 1);
        update(rt[y], 1, N, z, 1);
        update(rt[lca], 1, N, z, -1);
        update(rt[fa[lca]], 1, N, z, -1);
    }
    auto dfs = [&](auto &&self, int u, int pre) -> void{
        for(auto v : g[u]){
            if(v == pre) continue;
            self(self, v, u);
            rt[u] = merge(rt[u], rt[v], 1, N);
        }
        ans[u] = tr[rt[u]].cnt ? tr[rt[u]].ans : 0;
    };
    dfs(dfs, 1, 0);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << "\n";
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#else
    int START = clock();
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
#ifdef YUANSHEN
    cerr << "Run Time: " << (clock() - START)/1000.0 << "ms\n";
#endif
    return 0;
}