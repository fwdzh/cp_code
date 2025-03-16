#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    ll p, a, b, q, c, d, m, t;
    cin >> p >> a >> b >> q >> c >> d >> m >> t;

    /*
    (m/p)*(a+b)+c+d <= t

    */
    for (int i = 1;; i++)
    {

        ll x = m / p;
        if (!x)
            break;
        __int128 cost = a * x + b + c * x + d;
        if (cost <= t)
        {
            // cerr<<t<<'\n';
            t -= cost;
            m = q * x + (m % p);
        }
        else
            break;
        ll z = t / ((a + c) * x + b + d); // 最多还能操作的次数

        ll y = (x + 1) * p;
        if (m < y)
        {
            if (m + z * (q - p) * x < y)
            {
                m += z * x * (q - p);
                t %= ((a + c) * x + b + d);
                break;
            }
            else
            {
                ll zz = (y - m) / ((q - p) * x);
                m += zz * (q - p) * x;
                t -= zz * ((a + c) * x + b + d);
            }
        }
    }
    // cerr << "m t: " << m << " " << t << '\n';
    auto check = [&](ll x)
    {
        return (__int128)a * x + b + c * x + d <= t;
    };
    ll lo = 0, hi = m / p + 1;
    while (lo < hi - 1)
    {
        ll mid = (lo + hi) >> 1;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
    m += (q - p) * lo;
    cout << m << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}