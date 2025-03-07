// Date: 2025-03-05
// Time: 21:09:02

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e8;
vector<int> dep(N + 1);
vector<vector<int>> f(N + 1, vector<int>(25));
// vector<vector<int>> cost(N + 1, vector<int>(25));

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    auto lca = [&](int x, int y) -> int {
        if (dep[x] < dep[y])
            swap(x, y);
        // int res = 0;
        for (int i = 0, z = dep[x] - dep[y]; z; i++, z >>= 1) {
            if (z & 1)
                x = f[x][i];
        }
        if (x == y)
            return x;
        for (int i = 24; i >= 0; i--) {
            if (f[x][i] != f[y][i]) {
                // res += cost[x][i] + cost[y][i];
                x = f[x][i], y = f[y][i];
            }
        }
        // res += cost[x][0] + cost[y][0];
        return f[x][0];
    };
    vector<int> ans(n + 1);
    auto calc = [&](int x, int y) {
        // x 走到 lca
        // y 走到 lca
        // y的反过来就行
        vector<int> v;
        int temp = a[x], z = lca(a[x], a[y]);
        while (temp != z) {
            temp /= 2;
            v.push_back(temp);
        }
        if (x != z)
            v.push_back(z);
        temp = a[y];
        vector<int> stk;
        while (temp != z) {
            temp /= 2;
            stk.push_back(temp);
        }
        for (auto it = stk.rbegin(); it != stk.rend(); it++)
            v.push_back(*it);
        if (v.size() > x - y - 1) {
            return false;
        }
        if (((int)v.size()) ^ (x - y - 1) & 1)
            return false;
        while (v.size() < x - y - 1) {
            v.push_back(v.back() * 2);
            v.push_back(v.back() / 2);
        }
        for (int i = x, j = 0; i <= y; i++, j++)
            ans[i] = v[j];
        return true;
    };
    vector<int> p;
    for (int i = 1; i <= n; i++) {
        if (a[i] != -1)
            p.push_back(i);
    }
    if (p.empty()) {
        for (int i = 1; i <= n; i++)
            cout << (i & 1) + 1 << " \n"[i == n];
    } else {

        for (int i = p.front() - 1, s = 1, x = a[p.front()]; i >= 1; i--, s ^= 1) {
            if (s)
                ans[i] = x * 2;
            else
                ans[i] = x;
        }
        for (int i = p.back() + 1, s = 1, x = a[p.back()]; i <= n; i++, s ^= 1) {
            if (s)
                ans[i] = x * 2;
            else
                ans[i] = x;
        }
        for (int i = 1; i < p.size(); i++) {
            if (!calc(p[i - 1], p[i])) {
                cout << "-1\n";
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    auto dfs = [&](auto&& self, int u) -> void {
        dep[u] = dep[u] / 2 + 1;
        for (int i = 1; i < 25; i++) {
            f[u][i] = f[f[u][i - 1]][i - 1];
            // cost[u][i] = cost[f[u][i - 1]][i - 1];
        }
        if (u * 2 <= N) {
            f[u * 2][0] = u;
            // cost[u * 2][0] = 1;
            self(self, u * 2);
        }
        if (u * 2 + 1 <= N) {
            f[u * 2 + 1][0] = u;
            // cost[u * 2 + 1][0] = 1;
            self(self, u * 2 + 1);
        }
    };
    dfs(dfs, 1);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}