// Date: 2025-03-28
// Time: 18:37:03
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1)), a(n + 1, vector<int>(k + 1));
    /* 到i 分了j段 */
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            // cerr << dp[i][j] << " \n"[j == k];
        }
    }
    cout << dp[n][k] << '\n';
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