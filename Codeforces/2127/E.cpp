#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n, k; cin >> n >> k;
    vector<vector<int>> g(n + 1);
    vector<int> w(n + 1), c(n + 1);
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    LL ans = 0;
    auto dfs = [&](auto &&self, int u, int pre) -> void {
        for(auto v : g[u]){

        }
    };
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    {solve();} return 0;
}
/*
感觉一点想法没有 于是看了题解
hint 1:
    有一些节点一开始就是cute的
hint 2:
    可以不增加新的cute节点

啊？为什么可以不增加新的cute节点？
好像可以有点想法的。

对于 u
lca(x, y) = u， 仅当 x, y 分别属于 u 的两个子树
所以看 u 的子树里，重复出现过的颜色

如果 >= 2，那么 u 一定为可爱节点，
如果 = 1，看是否等于 c[u]，若未涂色，则设置

若整个子树都没有颜色，那就先别管

难道直接set存，看有没有重复？
这是不是显然不太行 时间复杂度似乎有点坏

solution:
    要用 virtual tree，不会，看他再怎么说吧
*/