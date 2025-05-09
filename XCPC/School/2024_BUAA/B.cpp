#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 998244353;

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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int x, y;
    cin >> x >> y;
    ll L = 0;
    for(int i = 1; i <= min(x - 1, y - 1); i++)
        L = (L * 10 + 4) % mod;
    L = (L * 10 + 5) % mod;
    for(int i = 1; i <= x - y; i++)
        L = L * 10 % mod;
    // cout << L << '\n';
    ll R = (ksm(10, x) - 1 + mod) % mod;
    ll ans = (L + R) * (R - L + 1) % mod * ksm(2, mod - 2) % mod;
    ans = (ans + mod) % mod;
    cout << ans << '\n';
    return 0;
}