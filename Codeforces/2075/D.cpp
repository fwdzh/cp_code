// Date: 2025-03-17
// Time: 23:26:59

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[60][60], ndp[60][60];

void ChatGptDeepSeek()
{
    ll X, Y;
    cin >> X >> Y;
    if (X == Y) {
        cout << "0\n";
        return;
    }
    // 100
    auto calc = [&](int x, int y) {
        // vector<vector<ll>> dp(x + 1, vector<ll>(y + 1, 4e18 + 1));
        dp[0][0][0] = 0;
        // cerr << dp[0][0] << '\n';
        for (int i = 1; i < 57; i++) {
            for (int xx = x; xx >= 0; xx--) {
                for (int yy = y; yy >= 0; yy--)
                    dp[xx][yy] = dp[xx][yy];
            }
            for (int xx = x; xx >= 0; xx--)
                for (int yy = y; yy >= 0; yy--) {
                    if (xx - i >= 0)
                        dp[xx][yy] = min(dp[xx][yy], dp[xx - i][yy] + (1LL << i));
                    if (yy - i >= 0)
                        dp[xx][yy] = min(dp[xx][yy], dp[xx][yy - i] + (1LL << i));
                }
        } // 1000
        // cerr << dp[x][y] << '\n';
        return dp[x][y];
    };
    vector<int> b1, b2;
    ll tmp = X;
    while (tmp) {
        b1.push_back(tmp % 2);
        tmp /= 2;
    }
    reverse(b1.begin(), b1.end());
    tmp = Y;
    while (tmp) {
        b2.push_back(tmp % 2);
        tmp /= 2;
    }
    reverse(b2.begin(), b2.end());
    int len = 0;
    for (int i = 0; i < b1.size() && i < b2.size(); i++) {
        if (b1[i] != b2[i]) {
            len = i;
            break;
        }
        // assert(i <= b1.size() && i <= b2.size());
    }
    ll ans = 4e18 + 1;
    for (int i = 0; i <= len; i++) {
        ans = min(ans, calc(b1.size() - i, b2.size() - i));
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cerr << __lg(vvv) << '\n';
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}