#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr ll inf = int(1e9) + 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pii>> g(n + 1, vector<pii>());
    for(int i = 1; i <= m; i++){
        int u, v, d;
        cin >> u >> v >> d;
        g[u].push_back({v, d});
    }
    // 可能多个重复的边，好吧 这个好像不用管的
    vector<vector<ll>> dp(n + 1, vector<ll>(32, 1));
    for(int edge = 1; edge <= 31; edge++){
        for(int i = 1; i <= n; i++){
            for(auto [v, d] : g[i]){
                dp[i][edge] = max(dp[i][edge], dp[v][edge - 1] * d);
                dp[i][edge] = min(dp[i][edge], inf);
            }
        }
    }
    while(q--){
        int p, x;
        cin >> p >> x;
        for(int edge = 1; ; edge++){
            if(dp[p][edge] > x){
                cout << edge << '\n';
                break;
            }
        }
    }
    return 0;
}