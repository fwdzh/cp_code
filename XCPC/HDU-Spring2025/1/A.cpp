// Date: 2025-03-07
// Time: 18:31:02

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string p;
    cin>>n>>p;
    int ans=-1;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s==p) ans=i;
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}