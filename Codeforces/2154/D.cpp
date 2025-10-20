#include<bits/stdc++.h>
using namespace std;

using LL = long long;
void solve()
{
    int n; cin >> n;
    vector<vector<int>> g(n + 1, vector<int> ());
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> fa(n + 1), dep(n + 1);
    vector<bool> sel(n + 1), des(n + 1);
    auto init = [&](auto &&self, int u, int p) -> void {
        fa[u] = p, dep[u] = dep[p] + 1;
        for(auto v : g[u]){
            if(v == p) continue;
            self(self, v, u);
        }
    };
    init(init, 1, 0);
    for(int p = n; p; p = fa[p]) sel[p] = true;
    assert(sel[1]);
    vector<vector<int>> ans;
    bool find = false;
    auto dfs = [&](auto &&self, int u) -> void {
        assert(sel[u]);
        if(u == n){
            find = true;
            return;
        }
        int cnt = 0;
        for(auto v : g[u]){
            if(!sel[v]){
                ans.push_back({2, v});
                ans.push_back({1});
                ans.push_back({1});
                // des[v] = true;
            }else cnt++;
        }
        assert(cnt == 1);
        ans.push_back({1});
        sel[u] = false;
        bool vis = false;
        for(auto v : g[u]){
            if(sel[v]){
                assert(vis == false);
                self(self, v);
                vis = true;
                return;
            }
        }
        assert(0);
    };
    dfs(dfs, 1);
    assert(find);
    assert((int)ans.size() <= 3 * n);
    cout << ans.size() << '\n';
    for(auto v : ans){
        for(auto x : v)
            cout << x << " ";
        cout << "\n";
    }
    cout << '\n';
}
int main()
{
#ifdef LOCAL
    freopen("1.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}