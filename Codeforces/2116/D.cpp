// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/codes/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif

#define rep(N) for(int i = 1; i <= N; i++)

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
template <class T>
using vc = vector<T>;

#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

// Date: 2025-05-31
// Time: 23:16:55
void ChatGptDeepSeek()
{
    int n, m;
    double p;
    cin >> n >> m >> p;
    vc<vc<double>> dp(401, vc<double> (400 * n + 1));
    // 1e5 * 20, 2e6
    vi h(n + 1);
    int mn = INF, sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
        sum += h[i];
        cmin(mn, h[i]);
        if(i == n){
            dp[mn][sum - n] = 1.0;
        }
    }
    for(int min_val = mn; min_val >= 0; min_val--){

    }
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}