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

constexpr int mod = 1e9 + 7;
constexpr int N = 2e5 + 10;
int f[N];

void ChatGptDeepSeek() // Date: 2025-04-11
{                      // Time: 19:18:14
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(ALL(a), greater<int>());
    ll ans = 0, s = a[1];
    for (int i = 2; i <= n; i++)
    {
        ans += s * a[i] % mod;
        ans %= mod;
        s = (s + a[i]) % mod;
    }
    ll res = 1;
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] != a[i - 1])
        {
            res = res * f[cnt] % mod;
            cnt = 1;
        }
        else
            cnt++;
    }
    res = res * f[cnt] % mod;
    cout << ans << ' ' << res << "\n";
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    f[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = 1LL * f[i - 1] * i % mod;
    }
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}