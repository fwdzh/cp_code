// Date: 2025-03-17
// Time: 19:56:04

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(k), y(k), a(k);
    int now = 0;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i] >> a[i];
        mp[{ x[i], y[i] }] = i;
        now |= (a[i] << (2 * i));
    }
    // 10 01 10
    // cerr << now << '\n';
    vector<int> dp(now + 1, 666);
    dp[now] = 0;
    vector<pair<int, int>> dir { { 0, 0 }, { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    auto calc = [&](int now_val, int i, int j) {
        for (auto it : dir) {
            int nx = i + it.first, ny = j + it.second;
            if (nx > n || nx < 1 || ny > m || ny < 1)
                continue;
            if (mp.contains({ nx, ny })) {
                int xx = (now_val >> (2 * mp[{ nx, ny }])) & 3;
                assert(xx <= 3 && xx >= 0);
                now_val ^= (xx << (2 * mp[{ nx, ny }]));
                xx = max(0, xx - 1);
                now_val |= (xx << (2 * mp[{ nx, ny }]));
            }
        }
        return now_val;
    };
    for (int i = 0; i < k; i++) {
        for (auto it : dir) {
            int nx = x[i] + it.first, ny = y[i] + it.second;
            if (nx > n || nx < 1 || ny > m || ny < 1)
                continue;
            // for (int _ = 1; _ <= 3; _++)
            for (int j = now; j >= 0; j--) {
                int nxt = calc(j, nx, ny);
                assert(nxt <= j);
                dp[nxt] = min(dp[nxt], dp[j] + 1);
            }
        }
    }
    cout << dp[0] << '\n';
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