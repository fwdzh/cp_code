// Date: 2025-03-01
// Time: 15:38:18

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> a(6);
    for (int i = 1; i <= 5; i++)
        cin >> a[i];
    int ans = 0;
    auto calc = [&](vector<int> b) {
        ans += b[3] / 2, b[3] %= 2;
        if (b[5]) {
            int mn = min(b[1], b[5]);
            b[1] -= mn, b[5] -= mn;
            ans += mn;
            mn = min(b[2], b[5]);
            b[2] -= mn, b[5] -= mn;
            ans += mn;
            mn = min(b[4], b[5]);
            b[4] -= mn, b[5] -= mn;
            ans += mn;
            ans += b[5] / 2, b[5] %= 1;
            mn = min(b[3], b[5]);
            b[3] -= mn, b[5] -= mn;
            ans += mn;
        }
        ans += b[5] / 2, b[5] %= 2;
        b[1] += b[5], b[5] = 0;
        b[1] += b[3], b[3] = 0;
        if (b[4]) {
            int mn = min(b[2], b[4]);
            b[2] -= mn, b[4] -= mn;
            ans += mn;
            mn = min(b[1] / 2, b[4]);
            b[1] -= mn * 2, b[4] -= mn;
            if (b[1] && b[4]) {
                assert(b[1] <= 1);

                if (b[4] >= 2) {
                    b[4] -= 2;
                    b[1] = 0;
                    ans++;
                }
            }
            ans += b[4] / 3, b[4] %= 3;
            b[1] += b[4], b[4] = 0;
        }
        ans += b[2] / 3, b[2] %= 3;
        // 2 ,8
        if (b[2] == 2) {
            if (b[1] >= 8) {
                b[1] -= 8, b[2] -= 2;
                ans += 2;
            } else if (b[1] >= 2) {
                b[1] -= 2, ans++;
            }
            b[2] = 0;
        } else if (b[2] == 1) {
            if (b[1] >= 4) {
                ans++, b[1] -= 4;
                b[2] = 0;
            }
        }
        b[1] += b[2], b[2] = 0;
        ans += b[1] / 6, b[1] %= 6;
    };
    calc(a);
    cout << ans << '\n';
}
/*
2 3 4 5 1
1 3 4 5 0 ,1
1 3 0 5 0, 3
1 0 0 2 0, 6

1 2 3 4 5
0 2 1 4 4 , 2
0 0 1 2 4, 4

*/

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