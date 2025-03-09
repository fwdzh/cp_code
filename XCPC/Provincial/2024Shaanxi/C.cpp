// Date: 2025-03-09
// Time: 15:46:55

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<set<int>> g(n * 2 + 1, set<int>());
    vector<int> a(n + 1), s(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[a[i]].insert(i);
    }
    {
        vector<int> du(n + 1);
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            du[i] = g[i].size();
            if (!du[i]) {
                q.push(i);
            }
        }
        // cerr<<q.size()<<'\n';
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            if (a[x] > n)
                continue;
            du[a[x]]--;
            if (!du[a[x]]) {
                q.push(a[x]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (du[i])
                ans++;
        for (int i = n + 1; i <= n * 2; i++) {
            int cnt = 0;
            auto dfs = [&](auto&& self, int u, int len) -> void {
                cnt = max(cnt, len);
                for (auto v : g[u]) {
                    self(self, v, len + 1);
                }
            };
            dfs(dfs, i, 1);
            // if (cnt > 1)
            ans += cnt - 1;
        }
        cout << ans << '\n';
    }

    // {
    //     set<int> st;
    //     for (int i = 1; i <= n; i++) {
    //         cout << s[i] << " \n"[i == n];
    //         st.insert(s[i]);
    //         assert(s[i] == i || s[i] == a[i]);
    //     }
    //     assert(st.size() == n);
    // }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}