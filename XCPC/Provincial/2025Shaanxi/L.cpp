/*
gcd(a, b) = g
gcd(a / g, b / g) = 1

16 18

32 48
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
        for(int i = 1; i < n; i++){
            ans += 3 + (i - 1) * 2 * (n + 1);
        }
    ans += n * n + (n * n - n + 1);
    
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}