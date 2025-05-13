/*
gcd(a, b) = g
gcd(a / g, b / g) = 1

16 18

32 48
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(n == 1){
        cout << "1\n";
        return;
    }
    int mx = *max_element(a.begin() + 1, a.end());
    int mn = *min_element(a.begin() + 1, a.end());
    if(a[1] < a[n]) swap(a[1], a[n]);
    if(a[1] == mx && a[n] == mn) cout << "2\n";
    else if(a[1] == mx || a[n] == mn) cout << "3\n";
    else cout << "4\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}