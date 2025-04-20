#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    // cerr<<(1LL<<30);
    // cerr << sum << '\n';
    ll res = 0;
    for (int i = 30; i >= 0; i--)
    {
        ll val = ((1LL << i) - 1) * n;
        if (val >= sum)
            continue;
        if (sum >= (1LL << i) * n)
            sum -= (1LL << i) * n;
        else
            sum %= (1LL << i);
        res |= 1LL << i;
    } // 1001
    cout << res << '\n';
    return 0;
}