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
mt19937_64 rng(time(NULL));
ll rnd(ll l, ll r)
{
    uniform_int_distribution<ll> dis(l, r);
    return dis(rng);
}
void ChatGptDeepSeek() // Date: 2025-04-19
{                      // Time: 23:37:48
    int n;
    cin >> n;
    vector<pii> p(n), q;
    set<pii> st;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
        st.insert({x, y});
    }
    auto find = [&](int x, int y)
    {
        if (st.contains({x, y + 1}) && st.contains({x + 1, y}) && st.contains({x + 1, y - 1}))
            p.push_back({x, y});
    };
    for (int i = 0; i < n; i++)
    {
        auto [x, y] = p[i];
        find(x - 1, y), find(x + 1, y), find(x, y - 1), find(x, y + 1);
    }

    auto [x, y] = p[rnd(0, sz(p) - 1)];
    cout << x << " " << y << '\n';
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