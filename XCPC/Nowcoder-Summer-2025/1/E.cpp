/*
2
3 1
2 5

1 2 : 3
1 3 : 8

2 3 : 5
2 4 : 12

3 4 : 7

4 5 : 9

5 6 : 11

*/
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    // vector<int> vec;
    // for(int a = 1; a <= 100; a++){
    //     for(int b = a + 1; b <= 100; b++){
    //         vec.push_back(b * b - a * a);
    //         if(vec.back() == 15)
    //             cerr << a << " " << b << '\n';
    //     }
    // }
    // ranges::sort(vec);
    // ranges::unique(vec);
    // for(auto x : vec)
    //     cout << x << " ";
    long long a, b, num, ans;
    cin >> a >> b;
    if(a < b) swap(a, b);
    num = a * a - b * b;
    ans = (num - 3) / 2 + 1;
    if(num >= 8){
        ans += (num - 8) / 4 + 1;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    {solve();} return 0;
}