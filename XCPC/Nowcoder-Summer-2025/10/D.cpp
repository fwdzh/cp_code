#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    /*
    x = x ^ y
    y ^ (x ^ y) = x
    x ^ y ^ x = y
    三次 可以交换x y的值
    只有当x或y = 0 时 可以执行

    3个固定的 
    1010101
    y = y ^ x
    x = x ^ y ^ x = y
    */
    LL n; cin >> n;
    if(n <= 3)  cout << "0\n";
    else if(n % 3 == 1 && ((n / 3) & 1)) cout << "2\n";
    else cout << "0\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    {solve();} return 0;
}