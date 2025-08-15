// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/codes/cp_code/template/debug.hpp"
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

void ChatGptDeepSeek() // Date: 2025-07-23
{                      // Time: 21:14:24 
    int n, k;
    cin >> n >> k;
    vector<vi> f(n + 1, vi(22));
    for(int i = 2; i <= n; i++){
        cin >> f[i][0];
    }
    for(int j = 1; j <= 21; j++){
        for(int i = 1; i <= n; i++){
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
    vector<bool> vis(n + 1);
    vis[1] = true;
    int ans = -1;
    while(k--){
        int u, l, r;
        cin >> u >> l >> r;
        if(ans > -1) continue;
        for(int j = l; j <= r; j++){
            int x = u;
            for(int t = 20; t >= 0; t--){
                if(!f[x][t] || vis[f[x][t]]) continue;
                x = f[x][t];
            }
            if(x == u){
                ans = j;
                break;
            }
            vis[x] = true;
        }
    }
    cout << ans << '\n';
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
        ChatGptDeepSeek();
    return 0;
}