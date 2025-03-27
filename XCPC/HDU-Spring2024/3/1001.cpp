// Date: 2025-03-21
// Time: 19:56:44

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 998244353;

void ChatGptDeepSeek()
{
    /*
    101
    101

    2+1
    */
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        int L;
        cin >> L;
        if (L >= a[i])
        {
            int x = 0;
            for (int j = 30; j >= 0; j--)
                x += (a[i] >> j & 1);
            ans = ans * (1 << x) % mod;
            continue;
        }
        int cnt = 0, ok = 1;
        for (int j = 30; j >= 0; j--)
        {
            int x = a[i] >> j & 1;
            int y = L >> j & 1;
            if (y)
            {
                int bit = 0;
                for (int k = j - 1; k >= 0; k--)
                    bit += (a[i] >> k & 1);
                cnt = (cnt + (1 << bit)) % mod;
                if (x == 0)
                {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok)
            cnt++;
        ans = ans * cnt % mod;
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