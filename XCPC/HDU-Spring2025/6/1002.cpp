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

struct SegTree
{
#define ls p << 1
#define rs p << 1 | 1
#define mi ((l + r) >> 1)
    vector<int> tr;
    SegTree(vector<int> &a)
    {
        tr = vector<int>((sz(a)) << 2);
        auto build = [&](auto &&self, int p, int l, int r) -> void
        {
            if (l == r)
            {
                tr[p] = a[l];
                return;
            }
            self(self, ls, l, mi);
            self(self, rs, mi + 1, r);
            tr[p] = max(tr[ls], tr[rs]);
        };
        build(build, 1, 1, sz(a) - 1);
    }
    int query(int p, int l, int r, int lx, int rx)
    {
        if (l >= lx && r <= rx)
            return tr[p];
        int res = 0;
        if (lx <= mi)
            res = max(res, query(ls, l, mi, lx, rx));
        if (rx > mi)
            res = max(res, query(rs, mi + 1, r, lx, rx));
        return res;
    }
};
void ChatGptDeepSeek() // Date: 2025-04-11
{                      // Time: 18:51:52
    int n;
    ll k;
    cin >> n >> k;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vl p(n + 1);
    for (int i = 2; i <= n; i++)
        p[i] = p[i - 1] + abs(a[i] - a[i - 1]);
    if (p[n] <= k)
    {
        cout << "0\n";
        return;
    }
    SegTree Tr(a);

    auto check = [&](int len)
    {
        for (int R = len; R <= n; R++)
        {
            //[L,R]的贡献减掉 然后加上一些东西
            int L = R - len + 1;
            ll now_val = p[n];
            if (R == n)
                now_val -= p[n] - p[L];
            else
                now_val -= p[R + 1] - p[L];
            int mx = Tr.query(1, 1, n, L, R);
            // cerr << L << " " << R << " " << mx << '\n';
            if (L > 1)
                now_val += abs(mx - a[L - 1]);
            if (R < n)
                now_val += abs(a[R + 1] - mx);
            // cerr << now_val << '\n';
            if (now_val <= k)
                return true;
        }
        return false;
    };
    int lo = 1, hi = n + 1;
    while (lo < hi - 1)
    {
        int mid = (lo + hi) >> 1;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }

    cout << hi << '\n';
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