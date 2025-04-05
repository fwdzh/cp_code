// Date: 2025-04-04
// Time: 18:32:36
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

ll dp[404][404];

void ChatGptDeepSeek()
{
    int n, m, V;
    cin >> n >> m >> V;
    vector<int> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> g[i];
    for(int i=0;i<=m;i++)for(int j=0;j<=V;j++) dp[i][j]=0;
    // dp[i][j] 買i個 花費等於j元的方案數
    dp[0][0] = 1;
    /*
    2 3 4
    1 2
    */
    for (int i = 1; i <= n; i++)
    {
        for (int cnt = 0; cnt < m; cnt++)
        {
            for (int cost = 0; cost <= V - g[i]; cost++)
            {
                dp[cnt + 1][cost + g[i]] = (dp[cnt + 1][cost + g[i]] + dp[cnt][cost]) % mod;
                // cerr << cnt << " " << cost << " " << dp[cnt + 1][cost + g[i]] << '\n';
            }
            //
        }
        // cerr << dp[m][V] << '\n';
    }
    // 400 * 400
    //
    ll ans = 0;
    for (int i = 0; i <= V; i++)
        ans = (ans + dp[m][i]) % mod;
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