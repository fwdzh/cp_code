#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    int s = 0;
    for(int i = 1; i <= n; i++){
        if(s >= a[i]) s++; else s--;
    }
    reverse(a.begin() + 1, a.end());
    cout << s << " ";
    s = 0;
    for(int i = 1; i <= n; i++){
        if(s >= a[i]) s++; else s--;
    }
    cout << s << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}