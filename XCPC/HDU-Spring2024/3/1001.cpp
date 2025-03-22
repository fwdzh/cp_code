// Date: 2025-03-21
// Time: 19:56:44

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin>>n;
    vector<int>a(n+1),L(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>L[i];
    /*
    只有奇数*奇数才会等于奇数
    (3,0) 1,(3,1) 3 , 
    (4,0) 1,(4,1) 4 , (4,2) 6
    (5,0) 1,(5,1) 5 , (5,2) 10
    (6,0) 1,(6,1) 6 , (6,2) 15 , (6,3) 20
    (7,0) 1,(7,1) 7 , (7,2) 21 , (7,3) 35
    (8,0) 1,(8,1) 8 ,       28 ,       56,    70
          1,      9 ,       36 ,       84,    126
          1,      10,       45 ,       120,   210    252
          
    */
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