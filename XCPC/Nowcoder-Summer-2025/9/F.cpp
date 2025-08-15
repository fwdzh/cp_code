#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    LL sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2;
    cin >> sx1 >> sy1 >> sx2 >> sy2 >> tx1 >> ty1 >> tx2 >> ty2;
    LL x1 = sx1 + sx2, y1 = sy1 + sy2;
    LL x2 = tx1 + tx2, y2 = ty1 + ty2;
    LL dx = abs(x1 - x2), dy = abs(y1 - y2);
    if(dx < dy) swap(dx, dy);
    if((dx - dy) & 1) cout << "-1\n";
    // cout << format("p1 : ({}, {}), p2 : ({}, {})\n", x1, y1, x2, y2);
    cout << dy + (dx - dy) << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}
/*
只看线段的中点
可以 [+0.5, -0.5] [-0.5, +0.5] [+0.5, +0.5] [-0.5, -0.5]

[+1, -1] [+1, +1] [-1, -1] [-1, +1]

*/