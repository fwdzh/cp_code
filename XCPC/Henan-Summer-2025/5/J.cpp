#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 100000 + 5;
vector<int> g[N];
vector<pair<LL, LL>> vg[N];
int tot, dfn[N], dep[N], f[N][21], a[N];
LL we[N][21], dp[N];
void dfs(int u, int p)
{
    dfn[u] = ++tot, dep[u] = dep[p] + 1;
    for(int i = 1; i <= 20; i++){
        f[u][i] = f[f[u][i - 1]][i - 1];
        we[u][i] = we[f[u][i - 1]][i - 1] + we[u][i - 1];
    }
    for(auto v : g[u]){
        if(v == p) continue;
        f[v][0] = u;
        we[v][0] = a[v];
        dfs(v, u);
    }
}
int lca(int x, int y)
{
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1){
        if(z & 1) x = f[x][i];
    }
    if(x == y) return x;
    for(int i = 20; i >= 0; i--){
        if(f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}
LL get(int x, int y)
{
    if(dep[x] < dep[y]) swap(x, y);
    LL res = -a[x];
    for(int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1){
        if(z & 1){
            res += we[x][i];
            x = f[x][i];
        }
    }
    return res;
}
void add(int x, int y)
{
    vg[x].push_back({y, get(x, y)});
}
void build(vector<int>& p)
{
    ranges::sort(p, [&](int x, int y){return dfn[x] < dfn[y];});
    for(int i = 0, k = p.size(); i + 1 < k; i++){
        p.push_back(lca(p[i], p[i + 1]));
    }
    ranges::sort(p, [&](int x, int y){return dfn[x] < dfn[y];});
    p.erase(unique(p.begin(), p.end()), p.end());
    for(int i = 0; i + 1 < p.size(); i++){
        // vg[lca(p[i], p[i + 1])].push_back(p[i + 1]);
        add(lca(p[i], p[i + 1]), p[i + 1]);
    }
    if(vg[1].empty()){
        // vg[1].push_back(p[0]);
        add(1, p[0]);
    }
}
void dfs1(int u)
{
    dp[u] = a[u];
    for(auto [v, w] : vg[u]){
        dfs1(v);
        dp[u] += w + dp[v];
        dp[v] = 0;
    }
    vg[u].clear();
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    // vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    // cerr << get(1, 3) << '\n';
    int q; cin >> q;
    while(q--){
        int k; cin >> k;
        vector<int> p(k);
        for(int i = 0; i < k; i++){
            cin >> p[i];
            // dp[p[i]] = a[p[i]];
        }
        // build(p);
        // dfs1(1);
        // cout << dp[1] << '\n';
        // vg[1].clear();
        ranges::sort(p, [&](int x, int y){return dfn[x] < dfn[y];});
        LL ans = a[1] + get(1, p[0]) + a[p[0]];
        for(int i = 1; i < k; i++)
            ans += get(1, p[i]) + a[p[i]] - get(1, lca(p[i - 1], p[i])) - a[lca(p[i - 1], p[i])];
        cout << ans << '\n';
    }
    return 0;
}