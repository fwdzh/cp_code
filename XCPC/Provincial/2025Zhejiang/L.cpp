#include <bits/stdc++.h>
using namespace std;
using LL = long long;

vector<vector<int>> g;
vector<int> f;
int find(int x){return f[x] == x ? f[x] : f[x] = find(f[x]);}
int dp[100005][2];
void dfs(int u, int p)
{
    dp[u][1] = 1, dp[u][0] = 0;
    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v, u);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
}
void solve()
{
    int n; cin >> n;
    f = vector<int> (n + 1);
    g = vector<vector<int>> (n + 1);
    iota(f.begin() + 1, f.end(), 1);
    vector<pair<int, int>> vec;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        int fi = find(i), fx = find(x);
        // cerr << fi << " " << fx << '\n';
        if(fi == fx){
            vec.push_back({i, x});
        }
        else{
            g[i].push_back(x);
            g[x].push_back(i);
            f[fx] = fi;
        }
    }
    // for(int i = 1; i <= n; i++)
    //     cout << find(i) << " ";
    // assert(vec.size() == 1);
    int ans = 0;
    for(auto [u, v] : vec){
        int res = 0;
        dfs(u, 0);
        res = max(res, dp[u][0]);
        dfs(v, 0);
        res = max(res, dp[v][0]);
        ans += res;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}