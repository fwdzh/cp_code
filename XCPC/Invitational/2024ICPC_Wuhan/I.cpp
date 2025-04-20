/*
01010101

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin>>s;
    int cnt=0;
    if(s[0]=='1') cnt++;
    for(int i=1;i<s.size();i++){
        if(s[i]=='1'&&s[i-1]=='0')  cnt++;
    }
    if(cnt==0) cout<<cnt<<'\n';
    else if(s.back()=='1') cout<<cnt-1<<'\n';
    else cout<<cnt<<'\n';
    return 0;
}