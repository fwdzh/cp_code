#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<LL> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int g = 0;
    for(int i = 1; i <= n; i++)
        g = gcd(g, abs(a[i] - a[1]));
    if(!g){
        for(int i = 1; i < n; i++)
            cout << a[i] * i << " ";
    }else{
        for(int i = 1; i < n; i++)
            cout << g << " ";
    }
    cout << accumulate(a.begin() + 1, a.end(), 0LL) << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}