#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b) cout << "Win\n";
    else if(c > b) cout << "WIN\n";
    else cout << "nowin\n";
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