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

struct node{
    int i, j, dist, cnt;
};
int dis[1010][1010][11];
void ChatGptDeepSeek() // Date: 2025-08-20
{                      // Time: 14:51:57 
    int n, m, k;
    cin >> n >> m >> k;
    auto cmp = [&](node x, node y) -> bool {
        return x.dist == y.dist ? x.cnt > y.cnt : x.dist > y.dist;
    };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    pq.push({0, 0, 0, 0});
    vector<string> s(n);
    // vector<vector<int>> dis(n, vector<int> (m, INF));
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int c = 0; c <= k; c++)
                dis[i][j][c] = INF;
    dis[0][0][0] = 0;
    vector<pii> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(!pq.empty()){
        auto [i, j, dist, cnt] = pq.top();
        assert(cnt <= k);
        // cerr << i << " " << j << " " << dist << " " << cnt << '\n';
        pq.pop();
        if(dis[i][j][cnt] < dist) continue;
        for(auto [dx, dy] : dir){
            int nx = dx + i, ny = dy + j;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(s[nx][ny] == '.'){
                if(dis[nx][ny][cnt] > dist + 1){
                    dis[nx][ny][cnt] = dist + 1;
                    pq.push({nx, ny, dist + 1, cnt});
                }
            }else{
                if(cnt + 1 <= k && dis[nx][ny][cnt + 1] > dist + 1){
                    dis[nx][ny][cnt + 1] = dist + 1;
                    pq.push({nx, ny, dist + 1, cnt + 1});
                }
            }
        }
    }
    int ans = INF;
    for(int i = 0; i <= k; i++)
        cmin(ans, dis[n - 1][m - 1][i]);
    if(ans == INF) ans = -1;
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