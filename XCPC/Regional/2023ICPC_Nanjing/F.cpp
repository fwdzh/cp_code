#include<bits/stdc++.h>
using namespace std;
using LL = long long;

vector<vector<int>> op, g;
vector<int> deg, ans;
int n, m;
void work()
{
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0)
            q.push(i);
        sort(g[i].begin(), g[i].end());
    }
    while(q.size()){
        auto u = q.front(); q.pop();
        ans.push_back(u);
        for(auto v : g[u]){
            if(deg[v]){
                if(--deg[v] == 0)
                    q.push(v);
            }
        }
    }
    reverse(ans.begin(), ans.end());
}
void solve()
{
    cin >> n >> m;
    op = vector<vector<int>> (m + 1);
    g = vector<vector<int>> (n + 1);
    deg = vector<int> (n + 1);
    for(int i = 1; i <= n; i++){
        int p; cin >> p;
        for(int j = 0; j < p; j++){
            int x; cin >> x;
            op[x].push_back(i);
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j + 1 < op[i].size(); j++){
            g[op[i].back()].push_back(op[i][j]);
            deg[op[i][j]]++;
        }
    }
    work();
    if(ans.size() != n) cout << "No\n";
    else{
        if(is_sorted(ans.begin(), ans.end())) cout << "No\n";
        else{
            cout << "Yes\n";
            for(auto x : ans)
                cout << x << " ";
            cout << '\n';
        }
    }
    ans.clear();
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}