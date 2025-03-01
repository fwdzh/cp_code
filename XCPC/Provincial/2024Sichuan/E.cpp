// Date: 2025-03-01
// Time: 14:33:10

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500*500;
int cnt[N+1];

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<vector<int>>C(n+1,vector<int>(m+1));
    int tot=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(s[i][j]=='C'){
                C[i][j]=++tot;
                cnt[tot]=0;
                if(i-1>=0&&s[i-1][j]=='D'){
                    C[i-1][j]=tot;
                }
                if(i+1<n&&s[i+1][j]=='U'){
                    C[i+1][j]=tot;
                }
                if(j-1>=0&&s[i][j-1]=='R'){
                    C[i][j-1]=tot;
                }
                if(j+1<m&&s[i][j+1]=='L'){
                    C[i][j+1]=tot;
                }
            }
        }
    // cout<<'\n';
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            // cout<<C[i][j]<<" \n"[j+1==m];
            cnt[C[i][j]]++;
        }
    int all=0;
    for(int i=1;i<=tot;i++){
        // cerr<<cnt[i]<< '\n';
        all+=cnt[i];
        if(cnt[i]!=3){
            cout<<"No\n";
            return;
        }
    }
    // cerr<<all<<'\n';
    // if(all==n*m){
    //     cout<<"Yes\n";
    // }else 
    if(all==n*m-1&&s[0][m-1]=='.')
        cout<<"Yes\n";
    else
        cout<<"No\n";
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