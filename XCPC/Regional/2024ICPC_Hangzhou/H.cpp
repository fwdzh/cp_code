// Date: 2025-03-29
// Time: 18:52:27
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void ChatGptDeepSeek()
{
    int n, k;
    cin >> n >> k;
    vector<pii> p(k);

    for (int i = 0; i < k; i++)
        cin >> p[i].first >> p[i].second;
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    vector<int> f(n + 1);
    sort(p.begin(), p.end(), [](pii x, pii y)
         { return x.second - x.first > y.second - y.first; });
    if (p[0].first == p[0].second)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int l = p[0].first + 1; l <= p[0].second; l++)
        f[l] = l - 1;

    int max_len = p[0].second - p[0].first + 1, root = p[0].first;
    if (k > 1 && p[1].second - p[1].first+1 == max_len)
    {
        auto [l, r] = p.back();
        if (r - l + 1 >= max_len - 1)
        // if (max_len - (r - l + 1) <= 1)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
        f[l] = root + 1;
        for (int i = l + 1; i <= r; i++)
        {
            if (f[i] || i == root)
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
            f[i] = i - 1;
        }
        k--;
    }
    long long sum = max_len;
    for (int i = 1; i < k; i++)
    {
        auto [l, r] = p[i];
        sum += r - l + 1;

        // if (r - l + 1 == max_len)
        // {
        //     cout << "IMPOSSIBLE\n";
        //     return;
        // }
        if (f[l] || l == root)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
        f[l] = root;

        for (int j = l + 1; j <= r; j++)
        {
            if (f[j] || j == root)
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
            f[j] = j - 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 0 && (i != root))
        {
            cout << "IMPOSSIBLE\n";
            return;
            // f[i] = root;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << f[i] << " \n"[i == n];
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