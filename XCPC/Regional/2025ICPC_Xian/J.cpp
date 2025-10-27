#include <bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int inf = 1000000000;
LL dp[300050][20];
int fa[300050][20];
int dep[300050];
void solve()
{
    // 当且仅当 lca(x, y) = y ?
    int n, q; cin >> n >> q;
    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto init = [&](auto &&self, int u, int p) -> void {
        LL f1 = inf, f2 = inf;
        for(auto v : g[u]){
            if(v == p) continue;
            self(self, v, u);
            if(c[v] < f1){
                f2 = f1, f1 = c[v];
            }else if(c[v] < f2){
                f2 = c[v];
            }
        }
        c[u] = min(0ll + c[u], f1 + f2);
    };
    init(init, 1, 0);
    auto dfs = [&](auto &&self, int u, int p) -> void {
        LL f1 = inf, f2 = inf;
        dep[u] = dep[p] + 1;
        dp[u][0] = inf;
        for(auto v : g[u]){
            if(v == p) continue;
            self(self, v, u);
            // dp[v][0] = c[u];
            fa[v][0] = u;
            if(c[v] < f1){
                f2 = f1, f1 = c[v];
            }else if(c[v] < f2){
                f2 = c[v];
            }
        }
        for(auto v : g[u]){
            if(v == p) continue;
            if(c[v] != f1) dp[v][0] = min(dp[v][0], f1);
            dp[v][0] = min(dp[v][0], f2);
        }
    };
    dfs(dfs, 1, 0);
    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 1; i <= n; i++){
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            dp[i][j] = dp[fa[i][j - 1]][j - 1] + dp[i][j - 1];
        }
    while(q--){
        int x, y;
        cin >> x >> y;
        auto get = [](int x, int y){
            if(dep[x] < dep[y]) return -1LL;
            LL res = 0;
            for(int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1)
                if(z & 1){
                    res += dp[x][i];
                    x = fa[x][i];
                }
            if(x != y) res = -1;
            return res;
        };
        cout << get(x, y) << '\n';
    }
}
int main()
{
#ifdef LOCAL
    freopen("1.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}