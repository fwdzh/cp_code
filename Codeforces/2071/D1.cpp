// Date: 2025-03-02
// Time: 01:44:01

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    //我们现在可以知道什么呢？
    //新加的数字里面，第偶数个后面一个肯定是和前一个是一样的，
    //因为若 m&1, m/2=(m+1)/2
    //也就是说后面的数字，必然两个两个的出现，
    //偶数个1抑或一起相当于没有抑或
    //所以这些段的值必然都为0
    //
    //然而这个作用不大啊
    //0 1 0 1
    //1 , 1 1,0 0,1 1,0 0,1 1,1 1,

    //0 会让它们继续复制前面的东西
    //所以好像其实也没太多规律

    //应该还是挺难的，这会才想了十分钟，明天再想一会。
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