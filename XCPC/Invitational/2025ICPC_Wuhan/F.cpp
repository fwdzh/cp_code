#include <bits/stdc++.h>
// #include "C:/codes/cp_code/template/debug.hpp"
using namespace std;

#define int long long

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define fi first
#define se second

constexpr int mod = 998244353;
constexpr ll lmt = ll(2e14);

ll ksm(ll a, ll b)
{
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll msk(__int128 a, ll b)
{
    __int128 res = 1;
    while(b){
        if(a >= lmt) return lmt + 1;
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
        if(res >= lmt)
            return lmt + 1;
    }
    return ll(res);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pll> info(n);
    for(int i = 0; i < n; i++)
        cin >> info[i].se >> info[i].fi;
    set<pll> bag;
    sort(info.begin(), info.end(), greater<>());
    ll ans = 0;
    for(auto [x, y] : info){
        // dbg(x, y);
        // cerr << x << " " << y << '\n';
        while(y){
            if(bag.empty()){
                ll cnt = (y + m - 1) / m;
                ll all = cnt * m;
                ans = (ans + ksm(2, x) * cnt % mod) % mod;
                if(all > y)
                    bag.insert({x, all - y});
                break;
            }else{
                // dbg(bag);
                auto [lx, ly] = *bag.rbegin();
                // cerr << " lx , ly :" << lx << " " << ly << '\n'; 
                bag.erase(prev(bag.end()));
                ll cnt = msk(2, lx - x);
                if(cnt >= lmt || __int128(cnt) * ly - y >= lmt){
                    cout << ans << '\n';
                    return;
                }
                if(cnt * ly - y > 0){
                    bag.insert({x, cnt * ly - y});
                    break;
                }else y -= cnt * ly;
            }
        }
        // dbg(bag);
    }
    cout << ans << '\n';
}

signed main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}