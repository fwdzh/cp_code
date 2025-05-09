#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    if(m < __lg(n) + 1){
        cout << "-1\n";
        return;
    }
    ll ans = ll(2e10);
    for(int i = 0; i <= __lg(n); i++){
        ll max_val = (1LL << (i + 1)) - 1;
        if(max_val > n) break;
        if(m - i - 1 == 0){
            if(max_val >= n)
                ans = min(ans, 1LL << i);
            break;
        }
        ll X = (n - max_val - 1) / (m - i - 1) + 1;
        // cerr << max_val << " " << X << '\n';
        if(X <= max_val){
            ans = min(ans, max(X, 1LL << i));
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}