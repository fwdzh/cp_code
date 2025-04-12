#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000010;
int dp[N][4], a[4];

void ChatGptDeepSeek() // Date: 2025-04-12
{                      // Time: 16:57:08
    string s[2];
    cin >> s[0] >> s[1];
    int n = s[0].size();
    s[0] = " " + s[0];
    s[1] = " " + s[1];
    auto work = [&](int i)
    {
        for (int j = 0; j < 4; j++)
        {
            a[j] = 0;
            int x = j >> 1 & 1, y = j & 1;
            if (x)
            {
                if (s[0][i] == '.')
                    a[j]++;
            }
            else
            {
                if (s[0][i] == '#')
                {
                    a[j] = -1;
                    continue;
                }
            }
            if (y)
            {
                if (s[1][i] == '.')
                    a[j]++;
            }
            else
            {
                if (s[1][i] == '#')
                {
                    a[j] = -1;
                    continue;
                }
            }
        }
    };
    for (int i = 0; i < 4; i++)
    {
        work(1);
        dp[1][i] = a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        work(i);
        for (int x = 0; x < 4; x++)
        {
            if (a[x] == -1)
                dp[i][x] = -1;
            else
                dp[i][x] = 1000000000;
        }
        for (int x = 0; x < 4; x++)
        {
            if (dp[i - 1][x] == -1)
                continue;
            for (int y = 0; y < 4; y++)
            {
                if (dp[i][y] == -1)
                    continue;
                if (x == 3 && y)
                    dp[i][y] = min(dp[i][y], dp[i - 1][x] + a[y]);
                if (y == 3 && x)
                    dp[i][y] = min(dp[i][y], dp[i - 1][x] + a[y]);
                if (x == y)
                    dp[i][y] = min(dp[i][y], dp[i - 1][x] + a[y]);
                if (y == 0)
                    dp[i][y] = min(dp[i][y], dp[i - 1][x]);
            }
        }
    }
    int ans = 1000000000;
    for (int i = 0; i < 4; i++)
    {
        if (dp[n][i] != -1)
            ans = min(ans, dp[n][i]);
    }
    if (ans == 0)
    {
        cout << ans << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[0][i] == '#' || s[1][i] == '#')
            break;
        ans--;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}