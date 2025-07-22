#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    auto check = [](int x){
        int y = sqrt(x);
        while(y * y > x)
            y--;
        while(y * y < x)
            y++;
        return y * y == x;
    };
    int m = 0;
    for(auto x : to_string(n)){
        m += x - '0';
    }
    if(check(n) && check(m)) cout << "Yes\n";
    else cout << "No\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    solve(); return 0;
}