#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-04-12
{                      // Time: 16:54:38 
    int n,m;
    cin>>n>>m;
    vector<long long>a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i]*=a[i];
    sort(a.begin()+1,a.end());
    long long res=0;
    for(int i=1;i<m;i++)
        res+=a[i+1]-a[i];
    long long ans=res;
    for(int i=m+1;i<=n;i++){
        res-=a[i-m+1]-a[i-m];
        res+=a[i]-a[i-1];
        ans=min(ans,res);
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}