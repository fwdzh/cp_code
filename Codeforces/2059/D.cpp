#include <bits/stdc++.h>
using namespace std;

void man()
{
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<set<int>> g1(n + 1), g2(n + 1);
    set<pair<int, int>> e1, e2;
    int m1, m2;
    cin >> m1;
    for (int i = 1; i <= m1; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        g1[u].insert(v);
        g1[v].insert(u);
        e1.insert({u, v});
    }
    cin >> m2;
    for (int i = 1; i <= m2; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        g2[u].insert(v);
        g2[v].insert(u);
        e2.insert({u, v});
    }
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (e1.count({i, j}) && e2.count({i, j}))
                vis[i] = true, vis[j] = true;
        }
    }
    queue<array<int, 2>> q;
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 1000000000));
    cost[s1][s2] = 0;
    q.push({s1, s2});
    while (!q.empty())
    {
        auto [v1, v2] = q.front();
        // cerr << v1 << " " << v2 << '\n';
        q.pop();
        for (auto u1 : g1[v1])
        {
            for (auto u2 : g2[v2])
            {
                int x = abs(u1 - u2);
                if (cost[u1][u2] > cost[v1][v2] + x)
                {
                    cost[u1][u2] = cost[v1][v2] + x;
                    q.push({u1, u2});
                }
            }
        }
    }
    int ans = 1000000000;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            ans = min(ans, cost[i][i]);
    }
    if (ans == 1000000000)
        cout << "-1\n";
    else
        cout << ans << '\n';
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        man();
    return 0;
}