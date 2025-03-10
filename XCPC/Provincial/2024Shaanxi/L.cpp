// Date: 2025-03-10
// Time: 16:19:10

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    long long x;
    cin>>x;
    for(int i=2;;i++){
        if(x%i){
            cout<<i<<'\n';
            return;
        }
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
        ChatGptDeepSeek();
    return 0;
}