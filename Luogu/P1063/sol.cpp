#include <bits/stdc++.h>
using namespace std;

int dp[202][202];
void ChatGptDeepSeek() // Date: 2025-04-08
{                      // Time: 16:03:12 
    int n; cin >> n;
    vector<int>a(2*n+1); for(int i=1;i<=n;i++) cin>>a[i],a[i+n]=a[i];
    for(int len=2;len<=n;len++) for(int l=1;l<=n;l++){
        int r=l+len-1;
        for(int k=l;k<r;k++){
            dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]+a[l]*a[]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}