#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    LL n, m; cin >> n >> m;
    if(gcd(n, m) != 1){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for(int i = 1; i <= n; i++)
        cout << (i * m + 1) % (n * m) << " \n" [i == n];
    for(int i = 1; i <= m; i++)
        cout << (i * n + 1) % (n * m) << " \n" [i == m];
    
}
int main()
{

    int t; cin >> t; while(t--)
    {solve();} return 0;
}