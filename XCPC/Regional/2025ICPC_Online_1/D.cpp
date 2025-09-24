#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 1000010;
constexpr LL inf = 1e18;
vector<vector<int>> g;
int a[N];
LL dp[N][4];
void dfs(int u, int p){
    dp[u][1] = a[u];
    dp[u][2] = -a[u];
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        LL tmp[4]{0, -inf, -inf, 0};
        for(int x = 0; x < 4; x++){
            for(int y = 0; y < 3; y++){
                if(x & y) continue;
                tmp[x | y] = max(tmp[x | y], dp[u][x] + dp[v][y]);
            }
        }
        for(int x = 0; x < 4; x++) dp[u][x] = tmp[x];
    }
    dp[u][0] = dp[u][3];
}
void solve()
{
    int n; cin >> n;
    g.assign(n + 1, {});
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << dp[1][0] << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}