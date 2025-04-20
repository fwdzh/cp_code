/*
01010101

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(1e6);
int s[N+1];

void solve()
{
    int n;
    cin>>n;
    // cerr<<s[n]<<" ";
    if(s[n]==0) cout<<"Pinkie Pie\n";
    else if(s[n]==1||s[n]==n) cout<<"Fluttershy\n";
    else if(s[n]==n+1) cout<<"Pinkie Pie\n";
}
/*
1 2 3 4 5 ,1


*/
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    for(int i=1;i<=N;i++){
        
        s[i]=i^s[i-1];
        // cerr<<i<<" "<<s[i]<< '\n';
    }
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}