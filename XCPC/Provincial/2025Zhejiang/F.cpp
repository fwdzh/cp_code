#include<bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> c;
vector<bool> vis;
vector<vector<int>> g;
struct node{
    int u, len, l;
};
bool check(int col)
{
    queue<node> q;
    vector<vector<int>> dis(n + 1, vector<int> (2, INT_MAX));
    vector<int> L(n + 1);
    for(int i = 1; i <= n; i++){
        if(c[i] == col){
            q.push({i, 1, i});
            dis[i][0] = 1;
            L[i] = i;
        }
    }
    while(q.size()){
        auto [u, len, l] = q.front(); q.pop();
        if(len >= k) continue;
        for(auto v : g[u]){
            if(c[v] == col && v != l) return false;
            if(dis[v][0] == INT_MAX){
                dis[v][0] = len + 1;
                L[v] = l;
                q.push({v, dis[v][0], l});
            }else if(dis[v][1] == INT_MAX && l != L[v]){
                dis[v][1] = len + 1;
                q.push({v, dis[v][1], l});
            }
        }
    }
    return true;
}
void solve()
{
    cin >> n >> m >> k;
    c = vector<int> (n + 1), vis = vector<bool> (51);
    g = vector<vector<int>> (n + 1);
    for(int i = 1; i <= n; i++) cin >> c[i], vis[c[i]] = true;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    for(int i = 1; i <= 50; i++){
        if(vis[i]){
            if(!check(i)){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}