#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-17 15:24:04
using LL = long long;
void solve(){
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<> ());
    // cout << (n - m) << " " << (v[m] + v[m - 1]) << "\n";
    LL P = (1LL * (n - m) * (v[m] + v[m - 1])) / (2 * n);
    LL Q = (1LL * m * (v[m] + v[m - 1]) + 2 * n - 1) / (2 * n);
    LL R = abs(m * P - (n - m) * Q);
    cout << P << "  " << Q << "  " << R << "\n";
}
/*
Q: m * (v_m + v_{m + 1}) / 2 / n
P:    (nv - mv) / n
    => (n * (v[m] + v[m - 1]) - m * (v[m] + v[m - 1])) / (2n)
*/
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}