#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
using ull = unsigned long long;

void ChatGptDeepSeek() // Date: 2025-04-13
{                      // Time: 18:10:15
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    sort(c.begin() + 1, c.end());

    auto check = [&](ll H)
    {
        vector<int> p(n + 1), s(n + 1);
        int M = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > 0)
            {
                ll need = (H - b[i]) / a[i] + ((H - b[i]) % a[i] != 0);
                // cerr << i << " " << need << " ";
                int idx = lower_bound(c.begin() + 1, c.end(), need) - c.begin();
                // cerr << i << " " << need << " " << idx << " \n";
                if (idx <= n)
                {
                    s[idx]++;
                    assert(idx >= 1 && idx <= n);
                }
            }
            else if (a[i] == 0)
            {
                if (b[i] >= H)
                    M++;
            }
            else
            {
                ll need = (H - b[i]) / a[i] - ((H - b[i]) % a[i] != 0);

                int idx = upper_bound(c.begin() + 1, c.end(), need) - c.begin() - 1;

                // cerr << i << " " << need << " " << idx << " \n";

                if (idx >= 1)
                {
                    assert(idx >= 1 && idx <= n);

                    p[idx]++;
                }
            }
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     cerr << p[i] << " \n"[i == n];
        // }
        // for (int i = 1; i <= n; i++)
        // {
        //     cerr << s[i] << " \n"[i == n];
        // }
        // cerr << M << '\n';
        // for (int i = n - 1; i >= 1; i--)
        // {
        //     p[i] += p[i + 1];
        //     p[i] = min(p[i], i);
        // }
        for (int i = 1; i <= n; i++)
        {
            s[i] = min(s[i], n - i + 1);
        }

        for (int i = n - 1; i >= 1; i--)
            s[i] += s[i + 1];
        for (int i = 1; i < n; i++)
            s[i + 1] = max(s[i + 1], s[i]);
        for (int i = 1; i <= n; i++)
        {
            s[i] = min(s[i], n - i + 1);
        }
        for (int i = 1; i <= n; i++)
        {
            p[i] = min(p[i], i);
        }
        for (int i = n - 1; i >= 1; i--)
            p[i] += p[i + 1];
        for (int i = n - 1; i >= 1; i--)
            p[i] = max(p[i], p[i + 1]);
        for (int i = 1; i <= n; i++)
        {
            // p[i] = max(p[i], p[i + 1]);
            p[i] = min(p[i], i);
        }

        // for (int i = 1; i <= n; i++)
        // {
        //     cerr << p[i] << " \n"[i == n];
        // }
        // for (int i = 1; i <= n; i++)
        // {
        //     cerr << s[i] << " \n"[i == n];
        // }
        // cerr << M << '\n';
        if (p[n] + M >= (n + 1) / 2 || s[1] + M >= (n + 1) / 2)
            return true;

        for (int i = 1; i + 1 <= n; i++)
        {
            if (M + p[i] + s[i + 1] >= (n + 1) / 2)
                return true;
        }
        return false;
    };
    ll lo = -3e18, hi = 3e18;
    while (lo < hi - 1)
    {
        ll mi = (lo + hi) / 2;
        if (check(mi))
            lo = mi;
        else
            hi = mi;
    }
    cout << lo << '\n';
    assert(check(lo + 1) == false);
    assert(lo != -4e18);
    // cerr << check(11) << '\n';
    // cerr << check(25) << '\n';
    // cout << check(9) << '\n';
    // cout << check(10) << '\n';
    // cout << check(13) << '\n';
}
/*
0 0 0 3 0
0 0 0 2 1

0 1 0 1 0
0 2 2 2 1

1 0 1 0 0
2 2 2 2 1

*/

signed main()
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