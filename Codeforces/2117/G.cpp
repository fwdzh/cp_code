#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> vec(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
        vec[v].push_back({u, w});
    }
    auto dfs = [&](auto &&self, int u, )
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}