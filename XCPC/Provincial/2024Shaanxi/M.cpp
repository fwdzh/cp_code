// Date: 2025-03-09
// Time: 14:05:29

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<pair<int, int>> st;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        st.insert({ x, y });
    }
    double ans = st.size() * 2;
    while (!st.empty()) {
        auto [x, y] = *st.begin();
        st.erase(st.begin());
        if (st.contains({ x - 1, y }))
            ans -= 0.5;
        if (st.contains({ x + 1, y }))
            ans -= 0.5;
        if (st.contains({ x, y - 1 }))
            ans -= 0.5;
        if (st.contains({ x, y + 1 }))
            ans -= 0.5;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}