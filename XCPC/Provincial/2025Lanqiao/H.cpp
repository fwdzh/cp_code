// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
template <typename T1, typename T2>
void cmin(T1 &x, const T2 &y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1 &x, const T2 &y)
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

constexpr int mod = int(1e9) + 7;
ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void ChatGptDeepSeek() // Date: 2025-04-15
{                      // Time: 00:14:11
    int n;
    cin >> n;
    ll ans = 0, s = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    s = 0;
    for (int i = 1; i < n; i++)
        s ^= a[i], ans = (ans + 2 * ksm(3, n - i - 1) * s % mod) % mod;
    s^=a[n];
    ans = (ans + s) % mod;
    cout << ans << '\n';
}
/*
后面有多少个符号 就要加3的多少次方
a1+()
a1-()

a1^a2+()
a1^a2-()
*/

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