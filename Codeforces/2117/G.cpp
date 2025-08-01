#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void solve()
{
    // 基本上一模一样 https://codeforces.com/gym/104857/problem/J
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> vec(n + 1);
    vector<array<int, 3>> edges;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
        vec[v].push_back({u, w});
        edges.push_back({u, v, w});
    }
    /*
    如果可以知道只经过小于 w 的边可以到达的最短的边是多少，会比较方便
    因为如果只算某个点到 1 和  n 经过的最大边，是比较方便的，且不怎么影响小的边
    反之影响更大，不方便

    呃 是不是不用考虑那么多 求最短的最大边的时候 顺便记录经过的最小边是不是就行了
    */
    auto dijkstra = [&](int s) -> vector<int> {
        vector<int> dis(n + 1, 1e9);
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
        pq.push({0, s});
        while(pq.size()){
            auto [dist, u] = pq.top();
            pq.pop();
            if(dis[u] < dist) continue;
            for(auto [v, w] : vec[u]){
                if(max(w, dist) < dis[v]){
                    dis[v] = max(w, dist);
                    pq.push({dis[v], v});
                }
            }
        }
        return dis;
    };
    vector<int> dis1 = dijkstra(1);
    vector<int> disn = dijkstra(n);
    int ans = INT_MAX;
    for(auto [u, v, w] : edges){
        // cerr << format("u, v, w : [{}, {}, {}]\n", u, v, w);
        // cerr << format("dis1[u], disn[v] : {} {} dis1[v], disn[u] : {} {}\n", dis1[u], disn[v], dis1[v], disn[u]);
        ans = min(ans, min(max({dis1[u], disn[v], w}), max({dis1[v], disn[u], w})) + w);
    }
    cout << ans << '\n';
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