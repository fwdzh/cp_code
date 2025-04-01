// Date: 2025-03-29
// Time: 17:04:03
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int g = 0, mn = 1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    for (int i = 2; i <= n; i++)
        g = __gcd(g, abs(a[i] - a[i - 1]));
    // cerr << g << '\n';
    if (!g)
    {
        cout << k << " " << 1LL * k * (k + 1) / 2 << '\n';
        return;
    }
    vector<int> b(n + 1), l(n + 1), r(n + 1), d;
    for (int i = 1; i * i <= g; i++)
    {
        if (g % i == 0)
        {
            int dd = i - mn;
            if (dd >= 1 && dd <= k)
                d.push_back(dd);
            if (i * i != g)
            {
                dd = g / i - mn;
                if (dd >= 1 && dd <= k)
                    d.push_back(dd);
            }
        }
    }
    int ans = 0;
    long long sum = 0;

    auto build = [&]()
    {
        vector<int> stk;
        for (int i = 1; i <= n; i++)
        {
            while (!stk.empty() && b[stk.back()] > b[i])
                l[i] = stk.back(), stk.pop_back();
            if (!stk.empty())
                r[stk.back()] = i;
            stk.push_back(i);
        }
        mn = stk[0];
    };
    auto dfs = [&](auto &&self, int i) -> bool
    {
        if (l[i])
        {
            if (b[l[i]] % b[i])
                return false;
            if (!self(self, l[i]))
                return false;
        }
        if (r[i])
        {
            if (b[r[i]] % b[i])
                return false;
            if (!self(self, r[i]))
                return false;
        }
        return true;
    };
    auto check = [&](int x)
    {
        for (int i = 1; i <= n; i++)
            b[i] = a[i] + x, l[i] = r[i] = 0;
        build();
        return dfs(dfs, mn);
    };

    for (auto x : d)
    {
        // cerr << x << "\n";
        if (check(x))
            ans++, sum += x;
    }
    cout << ans << " " << sum << '\n';
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