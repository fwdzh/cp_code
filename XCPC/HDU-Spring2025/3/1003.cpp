// Date: 2025-03-21
// Time: 18:32:06

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    vector<vector<int>> c(n + 1, vector<int>(m + 1)), w(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];
    }
    vector<priority_queue<pii, vector<pii>, greater<>>> pq(m + 1);
    queue<int> q;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] > a[j])
            {
                pq[j].push({c[i][j], i});
                cnt[i]++;
            }
        }
        if (!cnt[i])
            q.push(i);
    }
    int ans = 0;
    while (!q.empty())
    {
        ans++;
        int k = q.front();
        q.pop();
        for (int i = 1; i <= m; i++)
        {
            a[i] += w[k][i];
            while (!pq[i].empty() && a[i] >= pq[i].top().first)
            {
                auto [_, j] = pq[i].top();
                pq[i].pop();
                cnt[j]--;
                if (!cnt[j])
                    q.push(j);
            }
        }
    }
    cout << (ans == n ? "YES\n" : "NO\n");
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