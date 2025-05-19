#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<double> r(n + 1), c(n + 1);
    cin >> r[0] >> c[0];
    double p, L, R;
    cin >> p >> L >> R;
    for (int i = 1; i <= n; i++)
        r[i] = L;
    for (int i = 1; i <= k; i++) {
        int id;
        double v;
        cin >> id >> v;
        r[id] = v;
    }
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        c[i] = p * c[i - 1] + (1 - p) * r[i - 1];
        ans += c[i] - r[i];
    }
    cout << ans << '\n';
}
int main() {
    cout << fixed << setprecision(12);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}