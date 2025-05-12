#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll l, r;
    cin >> l >> r;
    ll siz = 1;
    while(l / siz != r / siz)
        siz *= 2;
    cout << l % siz << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}