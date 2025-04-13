#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-04-13
{                      // Time: 15:16:16
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> st(n + 1);
    vector<int> cnt(n + 1), f(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        st[u].insert(v);
        st[v].insert(u);
    }

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = st[i].size();
        cin >> p[i];
    }
    if (m == 0)
    {
        cout << "0\n";
        return;
    }
    // for (int i = 1; i <= n; i++)
    //     cerr << st[i].size() << " \n"[i == n];
    vector<pair<int, int>> ans;
    int cur = p[1];
    vector<bool> vis(n + 1);
    vis[p[1]] = true;
    for (auto v : st[p[1]])
    {
        // st[v].erase(p[1]);
        cnt[v]--;
    }
    if (st[p[1]].empty())
        cur = 0;
    // for (int i = 1; i <= n; i++)
    //     cerr << st[i].size() << " \n"[i == n];
    for (int i = 2; i <= n; i++)
    {
        vis[p[i]] = true;
        // cerr << p[i] << " " << cur << '\n';
        if (cur == 0)
        {
        }
        else if (st[cur].contains(p[i]))
        {
            f[p[i]] = cur;
        }
        else
        {
            f[p[i]] = p[i - 1];
            ans.push_back({p[i - 1], p[i]});
        }
        // for (auto v : st[p[i]])
        // {
        //     // st[v].erase(p[i]);
        //     cnt[v]--;
        // }
        // for (auto v : st[p[i]])
        //     if (vis[v])
        //         st[v].erase(p[i]);
        for (auto it = st[p[i]].begin(); it != st[p[i]].end();)
        {
            if (vis[*it])
            {
                st[*it].erase(p[i]);
                it = st[p[i]].erase(it);
            }
            else
                it++;
        }
        cur = p[i];
        // for (int i = 1; i <= n; i++)
        // {
        //     // cerr << st[i].size() << " \n"[i == n];
        //     cerr << cnt[i] << " \n"[i == n];
        // }
        while (cur && st[cur].empty())
        {
            // cerr<<cur<<" "<<cnt[cur]<<" "<<f[cur]<<'\n';
            cur = f[cur];
        }
        if (cur != p[i])
            f[p[i]] = cur;
        // cerr << "st[p[2]]: ";
        // for (auto x : st[p[2]])
        //     cerr << x << " ";
        // cerr << '\n';
    }
    cout << ans.size() << '\n';
    for (auto [u, v] : ans)
        cout << u << " " << v << '\n';
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