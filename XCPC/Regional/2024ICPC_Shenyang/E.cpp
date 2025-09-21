#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-19 17:57:01
using LL = long long;
constexpr int inf = 1e9;
vector<int> dp(16, inf), a(4), ord(16);
int nxt[1 << 16][16];
struct node{
    int mask;
    int cost;
};
void solve(){
    auto cmp = [&](const node &x, const node &y){
        return x.cost > y.cost;
    };
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    int m; cin >> m;
    int st = 0;
    for(int i = 0; i < m; i++){
        int mask = 0;
        string s[2];
        cin >> s[0] >> s[1];
        if(s[0][0] == '1') mask |= 8;
        if(s[0][1] == '1') mask |= 4;
        if(s[1][0] == '1') mask |= 2;
        if(s[1][1] == '1') mask |= 1;
        st |= 1 << mask;
    }
    set<int> vis;
    pq.push({st, 0});
    while(!pq.empty()){
        auto [mask, cost] = pq.top();
        // cerr << cost << '\n';
        pq.pop();
        if(!mask){
            cout << cost << '\n';
            return;
        }
        // if(vis.contains(mask)) continue;
        vis.insert(mask);
        
        for(int i = 0; i < 16; i++){
            if(mask >> ord[i] & 1){
                int tmp = nxt[mask][ord[i]];
                assert(__builtin_popcount(tmp) == __builtin_popcount(mask) - 1);
                // for(int j = 0; j < 16; j++){
                //     if(mask >> j & 1)
                //         if((j ^ (15 ^ i)) != 15)
                //             tmp |= 1 << (j ^ (15 ^ i));
                // }
                // tmp &= 32767;
                if(vis.find(tmp) == vis.end()){
                    pq.push({tmp, cost + dp[15 ^ ord[i]]});
                    // break;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < 4; i++) cin >> a[i];
    dp[0] = 2 * ranges::min(a);
    dp[1] = dp[2] = dp[4] = dp[8] = a[0]; //0001 0010 0100 1000
    dp[12] = dp[3] = a[1]; // 1100 0011
    dp[10] = dp[5] = a[2]; //1010 0101 列
    dp[15] = a[3];
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++)
            dp[i ^ j] = min(dp[i ^ j], dp[j] + dp[i]);
    }
    for(int i = 1; i < (1 << 16); i++){
        for(int j = 0; j < 16; j++){
            if(i >> j & 1){
                int tmp = 0;
                for(int k = 0; k < 16; k++){
                    if(i >> k & 1)
                        if((k ^ (15 ^ j)) != 15)
                            tmp |= 1 << (k ^ (15 ^ j));
                }
                nxt[i][j] = tmp;
            }
            
        }
    }
    for(int i = 0; i < 16; i++) ord[i] = i;
    ranges::sort(ord, [&](int x, int y){
        return dp[x] < dp[y];
    });
    while(t--)
    {solve();} return 0;
}