#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    if(s.front()==s.back()){
        cout<<"0\n";
        return;
    }
    for(int i=0;i+1<s.size();i++){
        if(s[i]==s[i+1]){
            cout<<i+1<<'\n';
            return;
        }
    }
    cout<<"-1\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}