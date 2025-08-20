#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    string n; cin >> n;
    if(n.size() == 1){
        cout << n << '\n';
        return;
    }
    string ans(n.size() - 1, '9');
    cout << max(ans, n) << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}