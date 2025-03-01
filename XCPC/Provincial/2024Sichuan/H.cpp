//1 G ,1
//2 G ,2
//3 Y ,1
//4 G ,2
//5 G ,3 , 3 Y , 1 G
//6 Y ,2
//7 G ,3
//8 G ,4 
//9 Y ,3 , 7 Y , 3
//10 G
//11 G
// Date: 2025-03-01
// Time: 13:43:56

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin>>n;
    long long ans=(n-1)/3+1;
    if(n%3==0){
        cout<<"1 ";
        cout<<ans<<'\n';
    }else{
        cout<<"0 ";
        if(n%3==2) cout<<ans+1<<'\n';
        else cout<<ans<<'\n';
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
        solve();
    return 0;
}