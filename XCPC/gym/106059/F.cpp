#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int mod = 1000000007;
constexpr int N = 15;
int f[N], inv[N];
LL ksm(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int C(int n, int m){
    if(m > n) return 0;
    return 1LL * f[n] * inv[n - m] % mod *inv[m] % mod;
}
void solve()
{
    int n, m; cin >> n >> m;
    vector<bool> ok(1 << 7);
    for(int i = 0; i < m; i++){
        int k; cin >> k;
        int mask = 0;
        for(int j = 0; j < k; j++){
            char x; cin >> x;
            mask |= 1 << (x - 'a');
        }
        for(int j = 0; j < (1 << 7); j++)
            ok[mask | j] = true;
    }
    int ans = 0;
    for(int mask = 0; mask < (1 << 7); mask++){
        if(!ok[mask]){
            // 求长度为 n 的由指定字符构成的字符串的数量
            int cnt = __builtin_popcount(mask);
            for(int i = cnt; i >= 1; i--){
                if((cnt - i) & 1){
                    ans = (ans - C(cnt, i) * ksm(i, n) % mod) % mod;
                }else{
                    ans = (ans + C(cnt, i) * ksm(i, n) % mod) % mod;
                }
            }
        }
    }
    cout << (ans + mod) % mod << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    f[0] = 1;
    for(int i = 1; i < N; i++)
        f[i] = 1LL * f[i - 1] * i % mod;
    inv[N - 1] = ksm(f[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--){
        inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
    }
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}