#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<long long, long long>;

void solve()
{
    int n;
    cin >> n;
    vector<ll> ans;
    vector<int> a(n + 1);
    ll now = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        now += 1LL * a[i] * i;
    }
    // ans[n] = now;
    ans.push_back(now);
    ll suf = a[n];
    set<pll> st1, st2;
    st2.insert({1, a[1]});
    st2.insert({n, a[n]});
    if (n > 1)
        st1.insert({suf, n});
    for (int i = n - 1; i >= 2; i--)
    {
        suf += a[i];
        st1.insert({suf, i});
        st2.insert({i, a[i]});
    }
    while (!st1.empty())
    {
        auto [val, i] = *st1.begin();
        st1.erase(st1.begin());
        auto it = st2.lower_bound({i, 0});
        auto [j1, x1] = *it;
        auto [j2, x2] = *prev(it);
        now -= val;
        ans.push_back(now);
        st2.erase({j1, x1});
        st2.erase({j2, x2});
        st2.insert({j2, x1 + x2});
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
    cout << '\n';
}
// 6
// 1 3 -4 5 -1 -2
// 1 3 -4 4 -2
// 1 -1 4 -2
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