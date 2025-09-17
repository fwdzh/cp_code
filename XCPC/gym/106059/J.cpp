#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-17 15:58:32
vector < vector<int> > g;
bool vis[1010];
int match[1010];
bool dfs(int u){
    for(auto v : g[u]){
        if(!vis[v]){
            vis[v] = true;
            if(!match[v] || dfs(match[v])){
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    g.assign(n + 1, {});
    auto check = [&](int x){
        int s = sqrt(x);
        return s * s == x;
    };
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(check(a[j] + i))
                g[i].push_back(j);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) vis[j] = false;
        if(!dfs(i)){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}