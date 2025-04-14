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

void ChatGptDeepSeek() // Date: 2025-04-14
{                      // Time: 17:50:21
    int n;
    // 10101
    cin >> n;
    string s;
    cin >> s;
    if (s[n - 1] == '0' && s[n - 2] == '0')
    {
        cout << "Yes\n";
        return;
    }
    if (n == 3)
    {
        if (s[2] == '1' || s[1] == '1')
            cout << "No\n";
        else
            cout << "Yes\n";
        return;
    }
    if (s[n - 1] == '1' && s[n - 2] == '1')
    {
        if (s[n - 3] == '0' && s[n - 4] == '1')
            cout << "Yes\n";
        else
            cout << "No\n";
        return;
    }
    if (count(all(s), '1') >= 2)
        cout << "Yes\n";
    else
        cout << "No\n";
    // 110-> 010 ，前面有1就ok
    // 101-> 110 , 前面若有1 1110-> 1010 ok
    // 111->
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