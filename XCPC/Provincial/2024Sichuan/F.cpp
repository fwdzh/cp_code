// Date: 2025-03-02
// Time: 16:14:11

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y, r, vx, vy;
    cin >> x >> y >> r >> vx >> vy;
    // 可以直接算出圆心放在哪个矩形可以使得满足条件。
    // 然后判断圆心的运动轨迹是否会经过这个区域。
    // 可以将顶点都带入直线方程，看是否都在直线同侧。
    // 运动路径可以表示为 vx * (Y-y) = vy * (X-x)

    // 圆心需要在
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    // 圆心必须在 (lx+r,ly+r) 和 (rx-r,ry-r) 之间
    if (rx - lx < 2 * r || ry - ly < 2 * r) {
        cout << "No\n";
        return;
    }
    // 由于是有方向的 我们直接来简单判断一下会不会经过
    if (x > rx - r || y > ry - r) {
        if (vx >= 0 && vy >= 0) {
            cout << "No\n";
            return;
        }
    }
    if (y > ry - r || x < lx + r) {
        if (vx <= 0 && vy >= 0) {
            cout << "No\n";
            return;
        }
    }
    if (y < ly + r || x < lx + r) {
        if (vx <= 0 && vy <= 0) {
            cout << "No\n";
            return;
        }
    }
    if (y < ly + r || x > rx - r) {
        if (vx >= 0 && vy <= 0) {
            cout << "No\n";
            return;
        }
    }
    auto calc = [&](int X, int Y) {
        return 1LL * vx * (Y - y) - 1LL * vy * (X - x);
    };
    set<long long> st;
    st.insert(calc(lx + r, ly + r));
    st.insert(calc(lx + r, ry - r));
    st.insert(calc(rx - r, ry - r));
    st.insert(calc(rx - r, ly + r));
    if (((*st.begin() < 0) && (*st.rbegin() > 0)) || st.contains(0))
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}