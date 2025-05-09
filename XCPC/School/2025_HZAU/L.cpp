#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int k, x;
    ll y;
    cin >> k >> x >> y;
    /*
    刚开始只能把
    (x+y)/2 放进去
    然后现在是 k-2 个 x 和 2个(x+y)/2
    
    这一次只能把
    ((x+y)/2 + x)/2 放进去

    其实主要还是看当前的奇数和偶数的数量吧，
    因为奇数和偶数加一起，会使得总和减少1
    
    ru

    */
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}