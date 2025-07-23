#define YUANSHEN
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

constexpr int mod = 998244353;
ll ksm(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void ChatGptDeepSeek() // Date: 2025-07-22
{                      // Time: 23:01:06 
    int n, m;
    cin >> n >> m;
    vector<array<int, 4>> vec(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++)
            cin >> vec[i][j];
    }
    ranges::sort(vec, [](array<int, 4> x, array<int, 4> y){
        return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0];
    });
    vl dp(m + 1), po(m + 1);
    vector<vector<array<int, 2>>> vec1(m + 1);
    // 
    ll now = 1;
    po[0] = 1;
    for(int i = 1, j = 1; i <= n; i++){
        while(j <= n && vec[j][0] == i){
            auto [l, r, p, q] = vec[j];
            now = now * p * ksm(q, mod - 2) % mod;
            vec1[r].push_back({p, q});
            j++;
        }
        po[i] = now * po[i - 1] % mod;
        for(auto [p, q] :vec1[i]){
            now = now * q * ksm(p, mod - 2) % mod;
        }
    }
    dbg(po);
    dp[0] = 1;
    ranges::sort(vec, [](array<int, 4> x, array<int, 4> y){
        return x[1] == y[1] ? x[0] < y[0] : x[1] < y[1];
    });
    for(auto [l, r, p, q] : vec){
        ll p1 = p * ksm(q, mod - 2) % mod;
        // ll p0 = ((1 - p1) + mod) % mod;
        auto get = [&](int l, int r){
            ll res = po[r] * ksm(po[l - 1], mod - 2) % mod;
            res = res * ksm(ksm(p1, r - l + 1), mod - 2) % mod;
            return res;
        };
        dp[r] = (dp[r] + dp[l - 1] * p1 % mod * get(l, r)) % mod;
        // cerr << dp[r] << '\n';
        // dp[l - 1] = dp[l - 1] * p0 % mod;
    }
    /*
    [l, r - 1] 需要乘 p0 吧                               
    */
    cout << dp[m] << '\n';
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