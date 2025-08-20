#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n; cin >> n;
    vector<int> x(n + 2), y(n + 2);
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    x[n] = x[0], y[n] = y[0];
    x[n + 1] = x[1], y[n + 1] = y[1];
    int k = (x[0] - x[1] > 0) ^ (y[0] - y[1] >= 0);
    for(int i = 1; i <= n; i++){
        if(x[i] == x[i + 1]) continue;
        int nk = (x[i] - x[i + 1] > 0) ^ (y[i] - y[i + 1] >= 0);
        if(nk == k){
            cout << "No\n";
            return;
        }
        nk ^= 1;
    }
    cout << "Yes\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}