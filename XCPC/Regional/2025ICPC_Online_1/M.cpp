#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using pii = pair<int, int>;

vector<vector<pii>> g;
vector<pii> e;
LL dis[5005][2];
LL sum = 0;
void init(int u, int p){
    sum += dis[u][0];
    for(auto [v, w] : g[u]){
        if(v == p) continue;
        dis[v][0] = dis[u][0] + w;
        init(v, u);
    }
}
void dfs1(int u, int p){
    sum += dis[u][0];
    for(auto [v, w] : g[u]){
        if(v == p) continue;
        dis[v][0] = min(dis[v][0], dis[u][0] + w);
        dfs1(v, u);
    }
}
void dfs2(int u, int p){
    for(auto [v, w] : g[u]){
        if(v == p) continue;
        dfs2(v, u);
        dis[u][0] = min(dis[u][0], dis[v][0] + w);
    }
}
void solve()
{
    int n, m; cin >> n >> m;
    g.assign(n + 1, {}), e.assign(m, {});
    for(int i = 1; i < n; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    init(1, 0);
    for(int i = 0; i < m; i++)
        cin >> e[i].first >> e[i].second;
    cout << sum << "\n";
    for(int _ = 0; _ < n; _++){
        for(int j = 1; j <= n; j++)
            dis[j][1] = dis[j][0];
        for(auto [x, y] : e){
            dis[x][0] = min(dis[x][0], dis[y][1]);
            dis[y][0] = min(dis[y][0], dis[x][1]);
        }
        sum = 0;
        dfs2(1, 0), dfs1(1, 0);
        cout << sum << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}