// Date: 2025-04-05
// Time: 13:38:31
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int N = 500005;

// vector<vector<pii>> adj(500005, vector<pii>());
vector<pii>adj[N];
// vector<int> dis(500005);
int dis[N];

void dfs(int u, int pre)
{
    for (int i=0;i<adj[u].size();i++)
    {
        if (adj[u][i].first == pre)
            continue;
        dis[adj[u][i].first] = dis[u] + adj[u][i].second;
        dis[adj[u][i].first] &= 1;
        dfs(adj[u][i].first, u);
    }
}

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        w &= 1;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, 0);
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i])
            c1++;
        else
            c2++;
    }
    long long ans = 1LL * c1 * (c1 - 1) * (c1 - 2) / 6 + 1LL * c2 * (c2 - 1) * (c2 - 2) / 6;
    ans += 1LL * c2 * (c2 - 1) / 2 * 6 + n;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}