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
                int idx = lower_bound(c.begin() + 1, c.end(), need) - c.begin();
                if (idx <= n)
                {
                    s[idx]++;
                    assert(idx >= 1 && idx <= n);
                }
            }
            else if (a[i] == 0)
            {
                if (b[i] >= H)
                {
                    // s[1]++;
                    p[n]++;
                    // M++;
                }
            }
            else
            {
                ll need = (H - b[i]) / a[i] - ((H - b[i]) % (-a[i]) != 0);
                // ll need = (H - b[i]) / a[i];
                //ax+b>=H
                //x<=(H-b)/a
                //所以减1 没问题阿
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
        //     cerr << p[i] << " \n"[i == n];
        // for (int i = 1; i <= n; i++)
        //     cerr << s[i] << " \n"[i == n];
        // 1 0 1 0
        for (int i = 1; i <= n; i++)
            p[i] = min(p[i], i);
        for (int i = 1; i <= n; i++)
            s[i] = min(s[i], n - i + 1);
        vector<int> p1 = p, s1 = s;

        // for (int i = 1; i <= n; i++)
        //     p[i] += p[i - 1];
        for (int i = n - 1; i >= 1; i--)
            p[i] += p[i + 1];
        for (int i = 1; i <= n; i++)
            p[i] = min(p[i], i);

        for (int i = 1; i <= n; i++)
            s[i] += s[i - 1];
        // for (int i = n - 1; i >= 1; i--)
        //     s[i] += s[i + 1];
        for (int i = 1; i <= n; i++)
            s[i] = min(s[i], n - i + 1);

        for (int i = n - 1; i >= 1; i--)
        {
            // s1[i] += s1[i + 1];
            s1[i] = s1[i + 1] + min(n - i + 1 - s1[i + 1], s1[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            // p1[i] += p1[i - 1];
            p1[i] = p1[i - 1] + min(i - p1[i - 1], p1[i]);
        }

        for (int i = 1; i <= n; i++)
        {
            s1[i] = min(s1[i], n - i + 1);
            p1[i] = min(p1[i], i);
        }
        for (int i = 1; i <= n; i++)
            p[i] += p1[i - 1];
        for (int i = 1; i < n; i++)
            s[i] += s1[i + 1];

        for (int i = 1; i <= n; i++)
        {
            // p[i - 1] = max(p[i - 1], p[i]);
            p[i] = min(p[i], i);
            s[i] = min(s[i], n - i + 1);
        }
        for (int i = n - 1; i >= 1; i--)
        {
            // s[i + 1] = max(s[i], s[i + 1]);
            s[i] = min(s[i], n - i + 1);
        }
        for (int i = 1; i <= n; i++)
        {
            // p[i - 1] = max(p[i - 1], p[i]);
            p[i] = min(p[i], i);
            s[i] = min(s[i], n - i + 1);
        }
        // for (int i = 1; i <= n; i++)
        //     cerr << p[i] << " \n"[i == n];
        // for (int i = 1; i <= n; i++)
        //     cerr << s[i] << " \n"[i == n];
        if (p[n] >= (n + 1) / 2 || s[1] >= (n + 1) / 2)
            return true;

        for (int i = 1; i + 1 <= n; i++)
        {
            if (p[i] + s[i + 1] >= (n + 1) / 2)
                return true;
        }
        return false;
    };
    ll lo = -2e18, hi = 2e18, ans = 0;
    while (lo <= hi)
    {
        // ll mi = (lo + hi) / 2;
        // if (check(mi))
        //     lo = mi;
        // else
        //     hi = mi;
        ll mid = (lo + hi) / 2;
        if (check(mid))
            lo = mid + 1, ans = mid;
        else
            hi = mid - 1;
    }
    cout << ans << '\n';
    // cout << lo << '\n';
    // if(n==28308)
    //     assert(check(999999997000000000));
    // assert(check(lo + 1) == false);
    // assert(lo != -4e18);
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
    // cerr<<(-3/-2)<<'\n';
    // cerr<<(-2%2)<<'\n';
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}