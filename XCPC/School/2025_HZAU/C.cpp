/*
1/x + 1/y
(x+y)/xy
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr int mod = ll(1e9) + 7;

ll ksm(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1; 
    }
    return res;
}
ll inv(ll a){return ksm(a, mod - 2);}
void solve()
{
    // for(int x = 1; x <= 99; x++)
    //     cout << 1.0/x + 1.0/(100-x) << '\n';
    int n, q;
    cin >> n >> q;
    vector<int>a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    while(q--){
        int L, R;
        cin >> L >> R;
        int mid = (pre[R] - pre[L - 1] + 1)/2 + pre[L - 1];
        auto it = lower_bound(pre.begin() + L, pre.begin() + R, mid);
        // cerr << it - pre.begin() << '\n';
        // if(it == pre.begin() + R){
        //     cout << (inv(a[R]) + inv(pre[R - 1] - pre[L - 1])) % mod << ' ';
        //     continue; 
        // }
        // if(it == pre.begin() + L){
        //     cout << (inv(a[L]) + inv(pre[R] - pre[L])) % mod << ' ';
        //     continue;
        // }
        int idx = it - pre.begin();
        ll X = 0;
        for(int j = max(L, idx - 1); j <= min(idx + 1, R - 1); j++){
            X = max(X, 1LL * (pre[j] - pre[L - 1]) * (pre[R] - pre[j]));
        }
        cout << 1LL * (pre[R] - pre[L - 1]) * inv(X) % mod << ' ';
    }
    cout << '\n';
}

signed main()
{
    // freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}