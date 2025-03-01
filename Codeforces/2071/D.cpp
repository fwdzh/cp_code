// Date: 2025-02-28
// Time: 23:31:09

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5;
int a[(N<<2)+1],pre[(N<<2)+1];

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i],pre[i]^=a[i];
    cout<<'\n';
    for(int j=1;j<=8;j++){
        for(int i=1;i<=n;i++){
            a[j*n+i]=pre[(j*n+i)>>1];
            pre[j*n+i]^=a[j*n+i];
            cout<<a[j*n+i]<<" \n"[i==n];
        }
    }    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}