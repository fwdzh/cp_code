#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> xmin(n + 1), xmax(n + 1), d(n + 1);
    for(int i = 1; i <= n; i++) xmin[i] = xmax[i] = i;
    vector<pair<int, int>> op(m);
    for(int i = 1; i <= m; i++){
        int l, r; cin >> l >> r;
        op[i - 1] = {l, r};
        for(int j = l; j <= r; j++){
            xmin[j] = min(xmin[j], l);
            xmax[j] = max(xmax[j], r);
            d[j]++;
        }
    }
    vector<int> ans(n + 1, -1);
    int tot = 0;
    if(m > 1){
        for(int i = 1; i <= n; i++){
            if(d[i] == m){
                ans[i] = tot++;
                for(int j = 1; j <= n; j++){
                    if(ans[j] < 0) ans[j] = tot++;
                    cout << ans[j] << " \n" [j == n];
                }
                return;
            }
        }
    }
    for(int i = 1; i + 1 <= n; i++){
        bool ok1 = true, ok2 = true;
        for(auto [l, r] : op){
            if(r == i){
                ok1 = false;
            }
            if(l == i + 1){
                ok2 = false;
            }
        }
        if(ok1 || ok2){
            // cout << "ok\n";
            if(ok1)
                ans[i] = tot++, ans[i + 1] = tot++;
            else
                ans[i + 1] = tot++, ans[i] = tot++;
            for(int j = 1; j <= n; j++){
                    if(ans[j] < 0) ans[j] = tot++;
                    cout << ans[j] << " \n" [j == n];
                }
            return;
        }
    }
    for(int i = 1; i <= n; i++){
        if(d[i] == 0){
            ans[i] = tot++;
            for(int j = 1; j <= n; j++){
                if(ans[j] < 0) ans[j] = tot++;
                cout << ans[j] << " \n" [j == n];
            }
            return;
        }
    }
    for(int i = 1; i <= n; i++){
        if(xmin[i] != 1 || xmax[i] != n){
            ans[xmin[i]] = tot++;
            if(xmin[i] != 1) ans[xmin[i] - 1] = tot++;
            else ans[xmax[i] + 1] = tot++;
            for(int j = 1; j <= n; j++){
                if(ans[j] < 0) ans[j] = tot++;
                cout << ans[j] << " \n" [j == n];
            }
            return;
        }
    }
    ans[min_element(d.begin() + 1, d.end()) - d.begin()] = tot++;
    for(int i = 1; i <= n; i++){
        if(ans[i] < 0) ans[i] = tot++;
        cout << ans[i] << " \n" [i == n];
    }
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0; 
}
/*
0 和 1 不在一起的话，答案是 2


ans = 0，必定是没有 mex = 0，即 0 在每一个区间里？
如果只有一个区间，那么把0放在外面，那个位置 d = 0，会被其他情况考虑，应该不用管

ans = 1，如果可以所有区间都不包含 1，那么答案一定是 1，即找 d = 0 的地方

还有啥情况吗？只要同时有 1，0，就至少会是 2
由于 0 不能被每一个区间包含，一定会出现 0，

如果可以让 1 和 0，永远不在一起，则只会有 1 和 0，答案一定是 2
如果让 1 和 0，永远在一起，则只会有 2 和 0， 答案为 1

那么还有什么情况 可以使得 ans = 1 呢？

*/