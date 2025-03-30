// Date: 2025-03-29
// Time: 16:10:20
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define fi first
#define se second
void ChatGptDeepSeek()
{
    int n, f;
    cin >> n >> f;
    priority_queue<pii, vector<pii>, greater<>> pq;
    priority_queue<pii> low, low1;
    vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        pq.push({l[i], i});
        // 按 [l,r] 排序
    }
    int lst = f;
    vector<int> ans;
    while (pq.size() || low.size())
    {
        while (!pq.empty() && pq.top().fi <= f)
        {
            auto [left, i] = pq.top();
            pq.pop();
            low.push({r[i], i});
        }
        if (!low.empty() && low.top().first > f)
        {
            auto [right, i] = low.top();
            low.pop();
            ans.push_back(i);
            f = right;
        }
        else if (!pq.empty())
        {
            auto [left, i] = pq.top();
            pq.pop();
            f = r[i];
            ans.push_back(i);
        }
        while (!low.empty())
        {
            auto [right, i] = low.top();
            low.pop();
            low1.push({l[i], i});
        }
    }
    while (!low1.empty())
    {
        auto [left, i] = low1.top();
        low1.pop();
        ans.push_back(i);
    }
    long long sum = 0;
    for (auto i : ans)
    {
        sum += r[i] - l[i] + max(0, l[i] - lst);
        lst = r[i];
    }
    cout << sum << '\n';
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
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