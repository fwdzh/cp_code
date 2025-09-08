#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    LL p, m; cin >> p >> m;
    LL ans = 0;
    if(((p - 1) ^ 1) <= m) ans += 1;
    ans += max(0LL, m / p - 1);
    for(LL x = m / p; x <= m / p + 2; x++){
        if(!x) continue;
        if(((p - 1) ^ (x * p + 1)) <= m) ans++;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}