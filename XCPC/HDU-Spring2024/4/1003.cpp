// Date: 2025-03-30
// Time: 18:37:46
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void ChatGptDeepSeek()
{
    ll k, b, c, v;
    cin >> k >> b >> c >> v;
    // px^c <= v
    // px <= v^c
    // px = kx+b
    ll lo = 0, hi = (c ^ v) + 1;
    ll mx = (c ^ v) - b;
    cerr << mx << '\n';
    while (lo < hi - 1)
    {
        ll mid = (lo + hi) >> 1;
        if (k * mid <= mx)
            lo = mid;
        else
            hi = mid;
    }
    if (b <= (c ^ v))
        lo++;
    cout << lo << '\n';
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