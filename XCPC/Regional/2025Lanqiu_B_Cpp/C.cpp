#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    k %= n;
    int ans = INT_MAX;
    if(k == 0) ans = min(ans, 0);
    if((n - k) % 2 == 0) ans = min(ans, (n - k) / 2);
    if((2 * n - k) % 2 == 0) ans = min(ans, (2 * n - k) / 2);
    if(ans == INT_MAX) ans = -1;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}