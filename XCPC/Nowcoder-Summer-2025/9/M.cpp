#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    if(n < 10) cout << "1\n";
    else cout << "-1\n";
    // auto s = [&](int a){
    //     int res = 0;
    //     for(auto x : to_string(a))
    //         res += x - '0';
    //     return res;
    // };
    // for(int n = 10; n <= 169; n++)
    // for(int a = 1; a <= 10000; a++){
    //     if(s(n * a) == n * s(a)){
    //         cout << "NO\n";
    //         return;
    //     }
    // }
}
int main()
{
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}
/*
3 33

*/