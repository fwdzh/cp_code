#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> t(n + 1), l(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> l[i] >> w[i];
    ll lo = 0, hi = 4e18 + 1;
    auto check = [&](ll x)
    {
        ll res = 0;
        for (int i = 1; i <= n; i++)
        {
            ll y = 1LL * t[i] * l[i] + w[i];
            res += x / y * l[i] + min(1LL * l[i], (x % y) / t[i]);
            if (res >= k)
                return true;
        }
        // cerr<<res<<'\n';
        return res >= k;
    };
    while (lo < hi - 1)
    {
        ll mid = (lo + hi) >> 1;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    // cerr<<check(10)<<'\n';
    cout << hi << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}