// Date: 2025-03-07
// Time: 14:54:50

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[v].push_back({ u, w });
        adj[u].push_back({ v, w });
    }
    vector<vector<int>> f(n + 1, vector<int>(25));
    vector<vector<int>> cost(n + 1, vector<int>(25));
    vector<int> dep(n + 1);
    auto dfs = [&](auto&& self, int u) -> void {
        dep[u] = dep[f[u][0]] + 1;
        for (int i = 1; i < 25; i++) {
            f[u][i] = f[f[u][i - 1]][i - 1];
            cost[u][i] = cost[f[u][i - 1]][i - 1] + cost[u][i - 1];
        }
        for (auto [v, w] : adj[u]) {
            if (v == f[u][0])
                continue;
            f[v][0] = u;
            cost[v][0] = w;
            self(self, v);
        }
    };
    dfs(dfs, 1);
    auto lca = [&](int x, int y) {
        if (dep[x] < dep[y])
            swap(x, y);
        int z = dep[x] - dep[y], res = 0;

        // 先让深度相同
        for (int i = 0; z; i++, z >>= 1) {
            if (z & 1)
                res += cost[x][i], x = f[x][i];
        }
        if (x == y)
            return res;
        // 否则需要找它们的lca第一次不相等的地方
        for (int i = 24; i >= 0 && x != y; --i) {
            if (f[x][i] != f[y][i]) {
                res += cost[x][i] + cost[y][i];
                x = f[x][i], y = f[y][i];
            }
        }
        res += cost[x][0] + cost[y][0];
        return res;
    };
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cerr << (2 << 24);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}