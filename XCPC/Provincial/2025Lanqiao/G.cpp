#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

int n;
vi w;
vector<vi> adj;
bool dp[1024][1024];
bool pd[1024][1024];

int siz[1024];

void dfs(int u, int pre)
{
    // cerr<<u<<" "<<pre<<'\n';
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        // cerr<<v<<'\n';
        if (v == pre)
            continue;
        dfs(v, u);
        for (int x = 0; x <= w[u]; x++)
        {
            // if (dp[u][x] == false)
            //     continue;
            for (int y = 0; x + y <= w[u] && y <= w[v]; y++)
            {
                if (dp[u][x] && dp[v][y])
                {
                    pd[u][x + y] = true;
                }
            }
        }
        for (int x = 0; x <= w[u]; x++)
            dp[u][x] = pd[u][x];
    }
}
void dfs1(int u, int pre)
{
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (v == pre)
            continue;
        siz[u]++;
        dfs1(v, u);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    w = vector<int>(n + 1);
    adj = vector<vi>(n + 1, vi());
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (siz[i] == 0)
        {
            dp[i][w[i]] = true;
            pd[i][w[i]] = true;
        }
        dp[i][0] = true;
        pd[i][0] = true;
    }
    dfs(1, 0);
    for (int i = w[1]; i >= 0; i--)
    {
        if (dp[1][i])
        {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}