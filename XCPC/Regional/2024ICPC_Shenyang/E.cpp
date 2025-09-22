#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9;
int dis[1 << 16];
struct node{
    int mask, cost;
};
int main(){
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    vector<int> a(4), dp(16, inf);
    for(int i = 0; i < 4; i++) cin >> a[i];
    dp[1] = dp[2] = dp[4] = dp[8] = a[0];
    dp[12] = dp[3] = a[1]; // 1100 0011
    dp[5] = dp[10] = a[2]; // 1010 0101
    dp[15] = a[3];
    dp[0] = *min_element(a.begin(), a.end()) * 2;
    for(int x = 0; x < 16; x++){
        for(int y = 0; y < 16; y++)
            dp[x ^ y] = min(dp[x ^ y], dp[x] + dp[y]);
    }
    auto cmp = [](const node &x, const node &y){
        return x.cost > y.cost;
    };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    pq.push({0, 0});
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;
    while(!pq.empty()){
        auto [mask, cost] = pq.top();
        pq.pop();
        if(cost > dis[mask]) continue;
        for(int i = 0; i < 16; i++){
            int tmp = 0;
            for(int j = 0; j < 16; j++){
                if(mask >> j & 1) tmp |= 1 << (i ^ j);
            }
            if(dis[tmp] > cost + dp[i]){
                dis[tmp] = cost + dp[i];
                pq.push({tmp, dis[tmp]});
            }
            // 然后加一个，15 ^ i
            tmp |= 1 << (15 ^ i);
            if(dis[tmp] > cost + dp[i]){
                dis[tmp] = cost + dp[i];
                pq.push({tmp, dis[tmp]});
            }
        }
    }
    while(T--){
        int m; cin >> m;
        int mask = 0;
        for(int i = 0; i < m; i++){
            int tmp = 0;
            for(int j = 0; j < 4; j++){
                char x; cin >> x;
                if(x == '1')
                    tmp |= 1 << j;
            }
            mask |= 1 << tmp;
        }
        cout << dis[mask] << "\n";
    }
    return 0;
}