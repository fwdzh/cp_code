// Date: 2025-03-30
// Time: 18:37:46
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void ChatGptDeepSeek()
{
    ll k, b, c, v;
    cin >> k >> b >> c >> v;
    ll led = 0;
    // p^c <=v
    ll ans = 0;
    for (int i = 60; i >= 0; i--)
    {
        if (v >> i & 1)
        {
            ll u = (led ^ c) & ((1LL << 61) - (1LL << i));
            ll L = u - 1, R = u + (1LL << i) - 1;
            // [u,R] 是 i全为0的区间，在这之后 i 这个地方全会为1了
            // 那么我们后面其实会漏掉 p=v 的情况
            if (R >= b)
                ans += (R - b) / k + 1;
            if (L >= b)
                ans -= (L - b) / k + 1;
            led |= 1LL << i;
        }
    }
    if ((v ^ c) >= b && ((v ^ c) - b) % k == 0)
        ans++;
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