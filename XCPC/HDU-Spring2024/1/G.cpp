// Date: 2025-03-07
// Time: 19:19:21

#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

void solve()
{
    // n=1 肯定没必要给
    // n=2 给第2个人不给第1个人，因为第2个人把我沙了就拿不到了

    // n=3 给第二个第三个，因为如果主人变成1 ，那么肯定会给3送金币
    // 所以2号会支持我如果我给他钱，
    // 所以只用给2

    // n=4 第一个人当主人会变成 (1,3)的情况，所以他只会给3钱
    // 所以如果给钱给2 4，它们会支持我 我正好也需要2个人

    // n=5 (1,4)
    // 3，5 ，
    // 它们肯定反对我 1也反对我

    // 所以我们继续给2 4

    // n=6 135反对我
    // 把钱给246

    auto get = [&](int l, int r) {
        if (l > r)
            return 0LL;
        return 1LL * (r - l + 2) / 2 * (l + r) / 2 % mod;
    };
    int n;
    cin >> n;
    cout << get(2, n - (n & 1)) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}