#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    /*
    tangwanle
    现在才发现 无私的牛希望所有牛的草的总和最多
    本以为是他希望自己的同类得到的总和更多

    唉唉，太无私了
    但是这样是不是简单点来着

    如果自私牛全去 B, 那最好
    无私的牛最多派一个人去 A

    否则他可能得逼着大家去 B
    当然这些会和人数有关

    无私的牛肯定希望去 A 的牛会尽量少
    */
    //首先就看如果无私的都不去 A, 那么答案就是
    ll ans = 0;
    if(x > y){
        if(m)
            ans = max(ans, x + y * n);
        else if(n)
            ans = max(ans , x + (n - 1) * y);
        // 自私的全去 A, 无私的试试能不能让他们都不去 A
        
        // x / (1 + cnt) <= y
        // x <= y * cnt
        // cnt >= (x + y -1) / y, 它们才不会去
        if(y){
            int cnt = (x + y - 1) / y - 1;
            cnt = max(cnt, 1);
            if(n >= cnt)
                ans = max(ans, x + (m + n - cnt) * y);
        }
    }
    else{
        if(n)
            ans = max(ans, x + (m + n - 1) * y);
        ans = max(ans, (m + n) * y);
    }
    cout << ans << '\n';
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}