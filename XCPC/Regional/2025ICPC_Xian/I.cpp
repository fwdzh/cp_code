#include <bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int inf = 1000000000;
int a[2025][2025];
void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            cin >> a[i][j], a[j][i] = a[i][j];
    vector<int> p(n + 1);
    queue<int> q;
    q.push(1);
    p[1] = -1;
    vector<vector<int>> g(n + 1);
    while(!q.empty()){
        auto k = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(p[i]) continue;
            vector<int> dis(n + 1, -1);
            dis[i] = i;
            queue<int> que;
            que.push(i);
            g[i].push_back(k);
            while(que.size()){
                auto u = que.front();
                if(a[i][u] != dis[u]){
                    break;
                }
                que.pop();
                for(auto v : g[u]){
                    if(dis[v] == -1){
                        dis[v] = dis[u] ^ v;
                        que.push(v);
                    }
                }
            }
            if(que.empty()){
                p[i] = k;
                g[k].push_back(i);
                q.push(i);
            }else
                g[i].pop_back();
        }
    }
    for(int i = 2; i <= n; i++)
        cout << i << " " << p[i] << '\n';
}
int main()
{
#ifdef LOCAL
    // freopen("1.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}