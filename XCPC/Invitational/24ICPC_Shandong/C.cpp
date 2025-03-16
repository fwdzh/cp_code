#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 998244353;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> seg(n);
    for (int i = 0; i < n; i++)
        cin >> seg[i].first >> seg[i].second;
    sort(seg.begin(), seg.end());
    priority_queue<int, vector<int>, greater<>> pq;
    int cnt = 0;
    ll res = 1;
    for (int i = 0; i < n; i++)
    {
        while (!pq.empty() && pq.top() < seg[i].first)
        {
            pq.pop();
            cnt--;
        }
        if (k - cnt > 0)
        {
            // cerr << cnt << '\n';

            res = res * (k - cnt) % mod;
            pq.push(seg[i].second);
            cnt++;
        }
        else
        {
            res = 0;
            break;
        }
    }
    cout << res << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}