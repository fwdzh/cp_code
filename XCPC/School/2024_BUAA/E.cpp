#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), cnt(n + 1), ru(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> g(n + 1, vector<int>());
    vector<vector<int>> g1(n + 1, vector<int>());
    // for(int i = 1; i <= n; i++)
    //     g1[a[i]].push_back(i);
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        ru[y]++;
        if(a[x] != a[y]){
            cnt[a[y]]++;
        }
    }
    // queue<int> q;
    // vector<bool> vis(n + 1);
    // set<int> st;
    // auto cmp = [&](int x, int y){
    //     return a[x] < a[y];
    // };
    // priority_queue<int, vector<int>, decltype(cmp)>pq(cmp);
    set<int> color;
    vector<queue<int>>q(n + 1);
    {
        vector<int> tmp;
        for(int i = 1; i <= n; i++){
            // cerr << ru[i] << " " << cnt[a[i]] << '\n';

            if(ru[i] == 0 && cnt[a[i]] == 0){
                // q.push(i);
                // tmp.push_back(i);
                // pq.push(i);
                color.insert(a[i]);
            }
            if(ru[i] == 0)
                q[a[i]].push(i);
        }
        // sort(tmp.begin(), tmp.end(), [&](int x, int y){
        //     return a[x] < a[y];
        // });
        // for(auto x : tmp)
        //     q.push(x);
    }
    vector<int> ans;
    while(color.size()){
        int x = *color.begin();
        color.erase(color.begin());
        while(!q[x].empty()){
            int u = q[x].front();
            q[x].pop();
            ans.push_back(u);
            for(auto v : g[u]){
                ru[v]--;
                if(a[v] == x){
                    if(ru[v] == 0)
                        q[x].push(v);
                }else{
                    cnt[a[v]]--;
                    if(ru[v] == 0)
                        q[a[v]].push(v);
                    if(cnt[a[v]] == 0)
                        color.insert(a[v]);

                }
            }
        }
    }
    // while(pq.size()){
    //     // queue<int> q1;
    //     {
    //         int u = pq.top();
    //         // q.pop();
    //         pq.pop();
    //         // if(vis[u]) continue;
    //         // q1.push(u);
            
    //         // vis[a[u]] = true;
    //         // cerr << u << '\n';
    //         // vis[u] = true;
    //         ans.push_back(u);
    //         for(auto v : g[u]){
    //             if(v == 5){
    //                 cerr << cnt[a[5]] << '\n';
    //             }
    //             ru[v]--;
    //             if(a[v] == a[u]){
    //                 if(ru[v] == 0)
    //                     pq.push(v);
    //             }else{
    //                 cnt[a[v]]--;
    //                 if(ru[v] == 0)
    //                     g1[a[v]].push_back(v);
    //                 if(cnt[a[v]] == 0){
    //                     for(auto x : g1[a[v]])
    //                         pq.push(x);
    //                 }
    //             }
    //         }
    //     }
    //     // while(!q1.empty()){
    //         // auto u = q1.front();
    //         // cerr << u << '\n';
    //     //     q1.pop();
    //     //     vis[u] = true;
    //     //     ans.push_back(u);
    //     //     for(auto v : g[u]){
    //     //         ru[v]--;
    //     //         if(a[v] == a[u]){
    //     //             if(ru[v] == 0)
    //     //                 q1.push(v);
    //     //         }else{
    //     //             cnt[a[v]]--;
    //     //             if(ru[v] == 0)
    //     //                 g1[a[v]].push_back(v);
    //     //             if(cnt[a[v]] == 0){
    //     //                 for(auto x : g1[a[v]])
    //     //                     q.push(x);
    //     //             }
    //     //         }
    //     //     }
    //     // }
    // }
    if(ans.size() != n){
        cout << "-1\n";
        return;
    }
    for(auto x : ans)
        cout << x << ' ';
    cout << '\n';
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}