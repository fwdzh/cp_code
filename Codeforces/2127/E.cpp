#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 200000 + 5;
vector<int> g[N], in[N];
int w[N], c[N], f[N][21], dep[N], dfn[N], tot;
LL ans;
void dfs(int u, int p)
{
    dfn[u] = ++tot, dep[u] = dep[p] + 1;
    for(int i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for(auto v : g[u]){
        if(v == p) continue;
        f[v][0] = u;
        dfs(v, u);
    }
}
int lca(int x, int y)
{
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1)
        if(z & 1) x = f[x][i];
    if(x == y) return x;
    for(int i = 20; i >= 0; i--){
        if(f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}
set<int> build(vector<int> p)
{
    int k = p.size();
    ranges::sort(p, [&](int x, int y){return dfn[x] < dfn[y];});
    for(int i = 0; i + 1 < k; i++)
        p.push_back(lca(p[i], p[i + 1]));
    ranges::sort(p, [&](int x, int y){return dfn[x] < dfn[y];});
    p.erase(unique(p.begin(), p.end()), p.end());
    k = p.size();
    for(int i = 0; i + 1 < k; i++)
        p.push_back(lca(p[i], p[i + 1]));
    return set<int> (p.begin(), p.end());
}
int dfs2(int u, int p)
{
    if(c[u] == 0 && in[u].size() == 1)
        c[u] = in[u][0];
    if(in[u].size() > 1) ans += w[u];
    int color = c[u];
    for(auto v : g[u]){
        if(v == p) continue;
        color = max(color, dfs2(v, u));
    }
    if(color && (c[u] == 0)) c[u] = color;
    else if(c[u] == 0) c[u] = c[p];
    return color;
}
void solve()
{
    int n, k; cin >> n >> k;
    vector<vector<int>> colors(k + 1);
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        colors[c[i]].push_back(i);
    }
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    tot = 0;
    dfs(1, 0);
    for(int i = 1; i <= k; i++){
        if(colors[i].size()){
            set<int> st = build(colors[i]);
            for(auto x : st)
                in[x].push_back(i);
        }
    }
    ans = 0;
    dfs2(1, 0);
    cout << ans << '\n';
    for(int i = 1; i <= n; i++){
        cout << c[i] << " \n" [i == n];
        g[i].clear(), in[i].clear();
    }

}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    {solve();} return 0;
}
/*
感觉一点想法没有 于是看了题解
hint 1:
    有一些节点一开始就是cute的
hint 2:
    可以不增加新的cute节点

啊？为什么可以不增加新的cute节点？
好像可以有点想法的。

对于 u
lca(x, y) = u， 仅当 x, y 分别属于 u 的两个子树
所以看 u 的子树里，重复出现过的颜色

如果 >= 2，那么 u 一定为可爱节点，
如果 = 1，看是否等于 c[u]，若未涂色，则设置

若整个子树都没有颜色，那就先别管

难道直接set存，看有没有重复？
这是不是显然不太行 时间复杂度似乎有点坏

solution:
    要用 virtual tree，不会，看他再怎么说吧

同种颜色建虚树
如果一个点 只在一个虚树里 那就直接记这个颜色
如果不在任何一个虚树 那就肯定不用加
如果在两个以上的虚树里 肯定要加

不在任意一个虚树的点，随便从子树找个颜色
在恰好一个虚树的点，选虚树的颜色
在两个虚树中的点，取子树的颜色

*/