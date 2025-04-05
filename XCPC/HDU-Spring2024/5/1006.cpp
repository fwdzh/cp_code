// Date: 2025-04-04
// Time: 19:29:23
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void ChatGptDeepSeek()
{
    int d, r, x, y;
    cin >> d >> r >> x >> y;
    // vector<pii> p;
    // p.push_back({r, d});
    // p.push_back({-r, d});

    // p.push_back({r, -d});
    // p.push_back({-r, -d});

    // p.push_back({0, -d});
    // p.push_back({0, d});

    auto calc = [&](int x1, int y1)
    {
        int x2 = x, y2 = y;
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };
    double ans = 1e8;
    ans = min(ans, calc(r, d));
    ans = min(ans, calc(-r, d));
    ans = min(ans, calc(r, -d));
    ans = min(ans, calc(-r, -d));

    // if (y >= d)
    //     ans = min(ans, calc(0, d) - r);
    // else
    //     ans = min(ans, calc(0, d) + r);

    if (y >= -d && y <= d)
        ans = min({ans, abs(x - r) * 1.0, abs(x + r) * 1.0});
    if (x >= -r && x <= r)
    {
        // 直綫
        //  x*x+(y-d)*(y-d)=r*r
        //  解方程
        //  ans = min({ans, abs()});
        if (x * x + (y - d) * (y - d) <= r * r)
        {
            if (y >= d)
                ans = min(ans, r - calc(0, d));
        }

        //
        if (x * x + (y + d) * (y + d) <= r * r)
        {
            if (y <= -d)
                ans = min(ans, r - calc(0, -d));
        }
    }
    if (y >= d && x * x + (y - d) * (y - d) > r * r)
    {
        ans = min(ans, calc(0, d) - r);
    }
    if (y <= -d && x * x + (y + d) * (y + d) > r * r)
    {
        ans = min(ans, calc(0, -d) - r);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(0);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}