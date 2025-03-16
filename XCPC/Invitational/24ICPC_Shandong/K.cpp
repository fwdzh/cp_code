/*
1 x 3
x x x
2 x 4

1 5 5 2
5 x 5 x
x 5 x 5
3 5 5 4

1 5 2
6 1 1
3 1 4

1 1 2 1
x 1 1 x
1 x x 1
3 1 4 1

1 5 1 1 2
x 1 5 1 1 
1 1 1 5 1
1 1 x 1 5
3 1 1 x 4

1 x x x 1 2
1 1 1 1 2 1
1 1 1 2 1 x
1 1 2 1 1 x
1 2 1 1 1 x
3 1 1 1 1 4
//2n-4
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>>a(n+1,vector<int>(n+1));
    a[1][1]=1,a[1][n]=2,a[n][1]=3,a[n][n]=4;
    int tot=5;
    for(int i=2;i<n;i++){
        a[1][i]=a[n][i]=tot++;
    }
    for(int i=2;i<n;i++){
        for(int j=1;j<=n;j++)
            a[i][j]=tot;
        tot++;
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" \n"[j==n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}