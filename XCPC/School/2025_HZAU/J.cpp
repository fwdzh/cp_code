#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr int N = int(2e4);

#define ls p << 1
#define rs p << 1 | 1
#define mi ((l + r) >> 1)

int tr[(N + 1) << 2];
void push_up(int p)
{
    tr[p] = tr[ls] + tr[rs];
}
void add(int p, int l, int r, int i, int x)
{
    if(l == r){
        tr[p] += x;
        return;
    }
    if(i <= mi) add(ls, l, mi, i, x);
    else add(rs, mi + 1, r, i, x);
    push_up(p);
}
int query(int p, int l, int r, int k)
{
    //查询第 k 大
    if(l == r) return l;
    if(tr[ls] >= k) return query(ls, l, mi, k);
    return query(rs, mi + 1, r, k - tr[ls]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), s(n + 1), nv(n + 1), rev(n + 1), dep(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    { //离散化一下
        vector<pii>tmp(n + 1);
        tmp[0] = {-1, -1};
        for(int i = 1; i <= n; i++)
            tmp[i] = {v[i], i};
        sort(tmp.begin() + 1, tmp.end());
        int tot = 0;
        for(int i = 1; i <= n; i++){
            auto [val, j] = tmp[i];
            if(val != tmp[i - 1].first) ++tot;
            nv[j] = tot, rev[tot] = val;
        }
    }
    vector<vector<int>> g(n + 1, vector<int>());
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    /*
    好像很简单啊，只要把每个节点的值给算出来，就可以直接进行背包DP了
    */
    auto dfs1 = [&](auto &&self, int u, int pre) -> void{
        dep[u] = dep[pre] + 1;
        add(1, 1, N, nv[u], 1);
        s[u] = rev[query(1, 1, N, dep[u]/2 + 1)];
        for(auto v : g[u]){
            if(v == pre) continue;
            self(self, v, u);
        }
        add(1, 1, N, nv[u], -1);
    };
    dfs1(dfs1, 1, 0);
    // for(int i = 1; i <= n; i++)
    //     cerr << s[i] << " \n"[i == n];
    vector<vector<ll>> dp(n + 1, vector<ll> (m + 1));
    auto dfs2 = [&](auto &&self, int u, int pre) -> void{
        dp[u][1] = s[u];
        for(auto v : g[u]){
            if(v == pre) continue;
            self(self, v, u);
            for(int i = 0; i < m; i++){
                
            }
        }
    };
    return 0;
}