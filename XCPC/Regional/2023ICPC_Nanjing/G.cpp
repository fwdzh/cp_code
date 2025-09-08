#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, W, k; cin >> n >> W >> k;
    vector<array<int, 2>> vec(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> vec[i][0] >> vec[i][1];
    sort(vec.begin() + 1, vec.end(), [&](array<int, 2> x, array<int, 2> y){
        return x[0] < y[0];
    });
    vector<LL> dp(W + 1), pre(n + 1);
    for(int i = 1; i <= n; i++){
        vector<LL> ndp(dp);
        for(int x = 0; x + vec[i][0] <= W; x++){
            ndp[x + vec[i][0]] = max(ndp[x + vec[i][0]], dp[x] + vec[i][1]);
        }
        for(int x = 1; x <= W; x++)
            ndp[x] = max(ndp[x], ndp[x - 1]);
        dp = ndp;
        pre[i] = max(pre[i - 1], dp[W]);
    }
    priority_queue<int, vector<int>, greater<>> pq;
    LL sum = 0, ans = pre[n];
    // cerr << ans << "\n";
    for(int i = n; i >= 1; i--){
        pq.push(vec[i][1]);
        sum += vec[i][1];
        if(pq.size() > k) sum -= pq.top(), pq.pop();
        // cerr << pre[i - 1] << " " << sum << '\n';
        ans = max(ans, pre[i - 1] + sum);
    }
    cout << ans << '\n';
    return 0;
}