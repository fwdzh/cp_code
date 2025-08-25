#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<int> h(n + 1);
    for(int i = 1; i <= n; i++) cin >> h[i];
    vector<LL> dp(n + 1, LLONG_MAX);
    dp[n] = h[n];
    // 后缀的答案是可以算的 h[i] + max(h[i + 1] - i, 0) + max(h[i + 2] - 1, 0) ... 
    for(int i = n - 1; i >= 1; i--){
        
        dp[i] = min(dp[i], dp[i + 1] + h[i] - i);
    }
    cout << dp[1] << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}