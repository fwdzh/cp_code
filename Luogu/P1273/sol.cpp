// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
template <typename T1, typename T2>
void cmin(T1 &x, const T2 &y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1 &x, const T2 &y)
{
    x = x > y ? x : y;
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

void ChatGptDeepSeek() // Date: 2025-04-11
{                      // Time: 11:04:40
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1, vector<pii>());
    for (int i = 1; i <= n - m; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int v, w;
            cin >> v >> w;
            adj[i].push_back({v, w});
        }
    }
    vector<vi> dp(n + 1, vi(n * 10 * 2 + 10));
    vi cost(n + 1);
    for (int i = n - m + 1; i <= n; i++)
        cin >> cost[i], dp[i][cost[i]] = 1;
    auto dfs = [&](auto &&self, int u, int pre) -> void
    {
        for (auto [v, w] : adj[u])
        {
            if (v == pre)
                continue;
            self(self, v, u);
            for (int i = 10 * n; i >= -10 * n; i--)
            {
                if (i - w + 10 * n >= 0)
                    cmax(dp[u][i + 10 * n], dp[u][i + 10 * n - w] + dp[v][i - w + 10 * n]);
            }
        }
        for (int i = -10 * n + 1; i <= 10 * n; i++)
        {
            cmax(dp[u][i + 10 * n], dp[u][i - 1 + 10 * n]);
        }
    };
    dfs(dfs, 1, 0);
    cout << dp[1][10 * n] << '\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}