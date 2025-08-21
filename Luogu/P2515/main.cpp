#include<bits/stdc++.h>
using namespace std;

constexpr int N = 110;
int n, m, w[N], v[N];
int head[N], to[N], nxt[N], EdgeCnt = 1;
void addEdge(int u, int v)
{
    nxt[EdgeCnt] = head[u];
    head[u] = EdgeCnt;
    to[EdgeCnt] = v;
    EdgeCnt++;
}
vector<int> dfs(int u){
    vector<int> dp(m + 1);
    dp[w[u]] = v[u];
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        vector<int> ndp = dfs(v);
        for(int x = m; x >= w[u]; x--){
            for(int y = 0; y + x <= m; y++)
                dp[x + y] = max(dp[x + y], dp[x] + ndp[y]);
        }
    }
    return dp;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    int rt = 0;
    for(int i = 1; i <= n; i++){
        int d; cin >> d;
        if(d) addEdge(d, i);
        else rt = i;
    }
    assert(rt);
    vector<int> dp = dfs(rt);
    cout << ranges::max(dp) << '\n';
    return 0;
}