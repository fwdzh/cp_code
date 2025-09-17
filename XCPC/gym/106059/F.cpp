#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-17 17:26:57
using LL = long long;
constexpr int mod = 1000000007;
int ksm(ll a, LL b){
    LL res = 1;
    while(b){
        if(b & 1) res = res * a;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve(){
    int n, m; cin >> n >> m;
    int ans = ksm(7, n);
    vector<int> ok(1 << 7, 1);
    for(int _ = 1; _ <= m; _++){
        int k; cin >> k;
        int mask = 0;
        for(int i = 0; i < k; i++){
            char c; cin >> c;
            mask |= 1 << (c - 'a');
        }
        ok[mask] = 0;
    }
    for(int mask = 1; mask < (1 << 7); mask++){
        if(ok[mask]){
            int res = 0, cnt = __builtin_popcount(mask);
            for()
        }
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}