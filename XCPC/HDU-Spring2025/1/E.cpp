// Date: 2025-03-07
// Time: 19:59:34

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr long long LNF = 1000000000000000000LL;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ull>> t(n + 1, vector<ull>(m + 1));
    vector<vector<ull>> d(n + 1, vector<ull>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> d[i][j];
    vector<vector<vector<ull>>> f(n + 1, vector<vector<ull>>(m + 1, vector<ull>(4, LNF)));
    // 0123 LURD
    f[1][0][2] = 0;

    {
        priority_queue<array<ull, 4>, vector<array<ull, 4>>, greater<>> pq;
        f[1][1][2] = t[1][1];
        pq.push({ t[1][1], 1, 1, 2 });
        while (!pq.empty()) {
            auto [dis, i, j, dir] = pq.top();
            // cerr << i << " " << j << '\n';
            pq.pop();
            if (f[i][j][dir] < dis)
                continue;
            for (ull k = 0; k < 4; k++) {
                // 首先它原地的不同方向
                if (f[i][j][dir] + d[i][j] < f[i][j][k]) {
                    f[i][j][k] = f[i][j][dir] + d[i][j];
                    pq.push({ f[i][j][k], i, j, k });
                }
            }
            if (i == n && j == m)
                continue;
            // 看自己是哪个方向
            if (dir == 0 && j - 1 >= 1) {
                if (f[i][j][0] + t[i][j - 1] < f[i][j - 1][0]) {
                    f[i][j - 1][0] = f[i][j][0] + t[i][j - 1];
                    pq.push({ f[i][j - 1][0], i, j - 1, 0 });
                }
            } else if (dir == 1 && i - 1 >= 1) {
                if (f[i][j][1] + t[i - 1][j] < f[i - 1][j][1]) {
                    f[i - 1][j][1] = f[i][j][1] + t[i - 1][j];
                    pq.push({ f[i - 1][j][1], i - 1, j, 1 });
                }
            } else if (dir == 2 && j + 1 <= m) {
                if (f[i][j][2] + t[i][j + 1] < f[i][j + 1][2]) {
                    f[i][j + 1][2] = f[i][j][2] + t[i][j + 1];
                    pq.push({ f[i][j + 1][2], i, j + 1, 2 });
                }
            } else if (dir == 3 && i + 1 <= n) {
                if (f[i][j][3] + t[i + 1][j] < f[i + 1][j][3]) {
                    f[i + 1][j][3] = f[i][j][3] + t[i + 1][j];
                    pq.push({ f[i + 1][j][3], i + 1, j, 3 });
                }
            }
        }
        // 距离 i j 方向
    }

    cout << f[n][m][3] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}