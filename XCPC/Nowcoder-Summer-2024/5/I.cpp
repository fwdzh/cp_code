#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    ll ans;
    if(n & 1){
        ans = 2 * n + n / 2 * 2 + 2;
    }else{
        ans = 2 * (n + 1) + n;
    }
    cout << ans << '\n';
}
int main()
{
    // freopen("1.in", "r", stdin), freopen("1.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}