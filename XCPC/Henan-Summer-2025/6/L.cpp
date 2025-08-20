#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    LL A, B, X; cin >> A >> B >> X;
    auto check = [&](LL lmt) -> bool {
        return A * lmt + B * to_string(lmt).size() <= X;
    };
    LL lo = 0, hi = int(1e9) + 1;
    while(lo < hi - 1){
        LL mid = (lo + hi) >> 1;
        if(check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}