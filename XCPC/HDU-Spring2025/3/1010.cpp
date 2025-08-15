// Date: 2025-03-21
// Time: 19:00:01

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n);
    vector<int> a(4);
    a[1] = a[3] = 2e9;
    a[0] = a[2] = -2e9;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        a[0] = max(a[0], x[i] + y[i]);
        a[1] = min(a[1], x[i] + y[i]);
        a[2] = max(a[2], x[i] - y[i]);
        a[3] = min(a[3], x[i] - y[i]);
    }
    long long ans = 4e9;
    for (int i = 0; i < m; i++)
    {
        int X, Y;
        cin >> X >> Y;
        long long c = X + Y, d = X - Y;
        long long now = max({c - a[1], a[0] - c, a[2] - d, d - a[3]});
        ans = min(ans, now);
    }
    cout << ans << '\n';
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