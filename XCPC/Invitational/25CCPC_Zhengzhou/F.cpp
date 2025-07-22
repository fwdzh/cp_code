#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    for (int i = 0; i < n; i++)
        cin >> maze[i];
    int ans = n + m - 3;
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<bool>> vis1(n, vector<bool>(m));
    auto dfs1 = [&](auto &&self, int i, int j) -> void
    {
        vis1[i][j] = true;
        for (auto [dx, dy] : dir)
        {
            int ni = dx + i, nj = dy + j;
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || vis1[ni][nj])
                continue;
            if (maze[ni][nj] == '.')
                self(self, ni, nj);
        }
    };
    auto dfs = [&](auto &&self, int i, int j, int res, int lmt) -> bool
    {
        if(res > lmt + 1) return false;
        if (vis1[i][j])
        {
            
            return true;
        }
        vis[i][j] = true;
        for (auto [dx, dy] : dir)
        {
            int ni = dx + i, nj = dy + j;
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || vis[ni][nj])
                continue;
            if (maze[ni][nj] == '#')
            {
                if(self(self, ni, nj, res + 1, lmt)) return true;
            }
            else
            {
                if(self(self, ni, nj, res + (res != 0), lmt)) return true;
            }
        }
        vis[i][j] = false;
        return false;
    };
    dfs1(dfs1, n - 1, m - 1);
    // dfs(dfs, 0, 0, 0);
    int lo = -1, hi = n + m - 2;
    while(lo < hi - 1){
        int mid = (lo + hi) >> 1;
        vis = vector<vector<bool>> (n, vector<bool> (m));
        if(dfs(dfs, 0, 0, 0, mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}