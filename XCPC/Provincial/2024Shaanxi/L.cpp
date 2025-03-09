// Date: 2025-03-09
// Time: 16:38:19

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll x)
{
    // 11
    auto check = [&](long long y, int i) {
        __int128 res = 1;
        for (int j = 1; j <= i; j++) {
            res *= y;
            if (res >= x) {
                // cerr<<y<<" "<<j<<"\n";
                return false;
            }
        }
        return true;
    };
    auto get = [&](int i) {
        // ksm(x,i-1)= X-1
        ll lo = 1, hi = x - 1;
        while (lo < hi - 1) {
            ll mid = (lo + hi) >> 1;
            if (check(mid, i))
                lo = mid;
            else
                hi = mid;
        }
        return lo;
    };
    auto ksm = [&](ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    };
    ll ans = x - 1;
    for (int i = 63; i >= 1; i--) {
        ll y = get(i);
        if (ksm(y, i) == x - 1) {
            ans = min(ans, y);
        }
    }
    // while (x) {
    //     cerr << x % ans;
    //     x /= ans;
    // }
    // cerr << '\n';
    return ans;
}

void solve()
{
    ll x;
    cin >> x;
    ll y = min(calc(x), calc(x + 2));
    // while (x) {
    //     cerr << x % y;
    //     x /= y;
    // }
    // cerr << '\n';
    cout<<y<<'\n';
}
//1101
//-111
//1000
//111,10
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}