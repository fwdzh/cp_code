// Date: 2025-03-11
// Time: 00:34:21

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> s1(n + 1), s2(n + 1);
    vector<char> c1(n + 1), c2(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c1[i] >> s1[i] >> c2[i] >> s2[i];
    // 关于新增的人放哪边
    //+ 操作与当前的人数无关的
    // 所以看哪个后面乘的多就去哪边
    vector<ull> p1(n + 2), p2(n + 2);
    p1[n+1]=p2[n+1]=1;
    for(int i=n;i>=1;i--){
        p1[i]=p1[i+1],p2[i]=p2[i+1];
        if(c1[i]=='x') p1[i]*=s1[i];
        if(c2[i]=='x') p2[i]*=s2[i];
    }
    ull L = 1, R = 1;
    for (int i = 1; i <= n; i++) {
        ull x = 0;
        if (c1[i] == 'x') {
            x += (s1[i] - 1) * L;
        } else {
            x += s1[i];
        }
        if (c2[i] == 'x') {
            x += (s2[i] - 1) * R;
        } else {
            x += s2[i];
        }
        // cerr<<p1[i]<<" "<<p2[i]<<'\n';
        if(p1[i+1]>=p2[i+1])
            L+=x;
        else R+=x;
    }
    cout<<L+R<<'\n';
}
/*
5
x 3 x 3 ，3 1
x 2 x 2 ，7 1
+ 21 + 2，30 1
x 2 x 3 ，62 1
+ 41 x 3   
*/
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