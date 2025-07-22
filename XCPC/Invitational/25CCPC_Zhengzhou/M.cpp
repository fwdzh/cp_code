#include<bits/stdc++.h>
using namespace std;

constexpr int N = int(1e6);
int f[N + 1];
int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        f[i] = i;
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        if(find(u) == find(v))
            ans++;
        else
            f[f[u]] = f[v];
    }
    set<int> st;
    for(int i = 1; i <= n; i++)
        st.insert(find(i));
    ans += st.size() - 1;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    solve(); return 0;
}