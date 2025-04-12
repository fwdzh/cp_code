#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-04-12
{                      // Time: 16:52:51 
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    for(int i=1;i<=k;i++){
        int A=(b+c)/2,B=(a+c)/2,C=(a+b)/2;
        if(A==a&&B==b&&C==c) break;
        a=A,b=B,c=C;
    }
    cout<<a<<" "<<b<<" "<<c<<'\n';
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