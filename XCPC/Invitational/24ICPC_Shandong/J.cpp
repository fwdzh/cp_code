#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> b(n + 1, vector<int>(n + 1));
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i]--;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> b[i][j];
    set<int> vis;
    priority_queue<pii, vector<pii>, greater<>> pq;
    // 先每种颜色都只用一个点 再慢慢加上去
    vis.insert(1);
    for (int i = 2; i <= n; i++)
        pq.push({b[1][i], i});
    while (!pq.empty())
    {
        auto [val, i] = pq.top();
        pq.pop();
        if (vis.count(i))
            continue;
        vis.insert(i);
        sum += val;
        for (int j = 1; j <= n; j++)
        {
            if (vis.count(j))
                continue;
            pq.push({b[i][j], j});
        }
    }
    // cerr << sum << '\n';
    for(int i=1;i<=n;i++){
        sum+=1LL*a[i]*(*min_element(b[i].begin()+1,b[i].end()));
    }
    cout<<sum<<'\n';
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