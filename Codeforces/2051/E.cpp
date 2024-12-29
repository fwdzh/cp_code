// Author: Zhangwuji
// Date: 2024-12-24
// Time: 12:15:03

// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/templates/debug.hpp"
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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pii> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi;
    for (int i = 1; i <= n; i++)
        cin >> a[i].se;
    sort(ALL(a), [](pii x, pii y) {
        return x.se > y.se;
    });
    multiset<int> st;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && *st.rbegin() >= a[i].se)
            st.erase(prev(st.end()));
        st.insert(a[i].fi);
        if (sz(st) <= k && (i == n || a[i + 1].se != a[i].se)) {
            cmax(ans, 1ll * a[i].se * i);
        }
    }
    // cerr<<ans<<'\n';
    sort(ALL(a));
    st.clear();
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && *st.begin() < a[i].fi) {
            st.erase(st.begin());
            cnt++;
        }
        // cerr<<cnt<<'\n';
        if (i - 1 - cnt <= k) {
            cmax(ans, 1ll * (n - cnt) * a[i].fi);
            // cerr<<k<<'\n';
            // cerr<<i-1-cnt<<'\n';
        }
        st.insert(a[i].se);
    }
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
        solve();
    return 0;
}