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

void ChatGptDeepSeek() // Date: 2025-04-11
{                      // Time: 18:39:55
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<char> s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    vector<int> v1, v2;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'R')
            v1.push_back(a[i]);
        else
            v2.push_back(a[i]);
    }
    sort(all(v1), greater<int>());
    sort(all(v2), greater<int>());
    ll ans = 0;
    for (int i = 0; i < min(sz(v1), sz(v2)); i++)
        ans += v1[i] + v2[i];
    if (sz(v1) > sz(v2))
        ans += v1[sz(v2)];
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
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}