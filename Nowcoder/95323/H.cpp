// Author: Zhangwuji
// Date: 2025-01-21
// Time: 14:21:05

// #define YUANSHEN
#if defined(YUANSHEN)
#include "D:/cp/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
template <typename T1, typename T2>
void cmin(T1& x, const T2& y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1& x, const T2& y)
{
    x = x > y ? x : y;
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

void solve()
{
    int n;
    cin >> n;
    vi l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    //[r,i]
    vector<array<int, 3>> a(n + 1);
    set<array<int, 3>> st;
    for (int i = 1; i <= n; i++)
        st.insert({ l[i], r[i], i });
    sort(ALL(a));
    set<array<int,3>> st1;
    vector<int>ans;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && (*st.begin())[0] == i) {
            auto [L, R, j] = *st.begin();
            st1.insert({R,L,j});
            st.erase(st.begin());
        }
        while(!st1.empty()&&(*st1.begin())[0]<i){
            ans.push_back((*st1.begin())[2]);
            st1.erase(st1.begin());
        }
        // cerr<<i<<" "<<sz(st1)<<'\n';
    }
    for(auto x:st1)
        ans.push_back(x[2]);
    vi vis(n+1);
    int ok=0;
    for(int i=1;i<=n;i++){
        if(ans[i-1]<l[i]||ans[i-1]>r[i]){
            cout<<"-1\n";
            return;
        }
        vis[ans[i-1]]++;
        if(vis[ans[i-1]]==1) ok++;
    }
    if(ok!=n){
        cout<<"-1\n";
        return;
    }
    for(auto x:ans)
        cout<<x<<' ';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}