// Date: 2025-03-02
// Time: 15:05:00

#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int ans = 0;
    array<int, 6> a;
    for (int i = 1; i <= 5; i++)
        cin >> a[i];
    // 0 0 3 0 3
    ans += a[3] / 2, a[3] %= 2;
    // 如果4需要3，那么2肯定没了。
    {
        int mn = min(a[2], a[4]);
        ans += mn, a[2] -= mn, a[4] -= mn;
    }
    // 3 给自己用肯定是最优的，剩下的先不要急着变成1吧。说不定能 1 2 3加一起
    {
        int mn = min(a[1], a[5]);
        ans += mn, a[1] -= mn, a[5] -= mn;

        mn = min(a[3], a[5]);
        ans += mn, a[3] -= mn, a[5] -= mn;

        mn = min(a[2], a[5]);
        ans += mn, a[2] -= mn, a[5] -= mn;

        mn = min(a[4], a[5]);
        ans += mn, a[4] -= mn, a[5] -= mn;

        // 5 肯定一个都没有了 或者其他的一个都没有了

        // 好吧 ，5可能还有
        ans += a[5] / 2, a[1] += a[5] % 2, a[5] = 0;
    }
    // 3 2 1 一起 ，还是给4？

    // 1 2 3组一起的话一定是需要1的，最好先别把1用完

    {
        // 如果还有4，那么肯定没有2了，只剩下1
        int mn = min(a[1] / 2, a[4]);
        ans += mn, a[1] -= 2 * mn, a[4] -= mn;
        // 如果a[4]还有，那么肯定最多1个1

        ans += a[4] / 3, a[4] %= 3;
        if (a[4] == 2) {
            if (a[1]) {
                a[1]--, a[4] = 0, ans++;
            } else if (a[3]) {
                a[3]--, a[4] = 0, ans++;
            } else {
                a[1] += a[4], a[4] = 0;
            }
        } else if (a[4] == 1) {
            assert(a[1] <= 1);
            if (a[3] && a[1]) {
                a[3]--, a[1]--, a[4]--, ans++;
            } else {
                a[1] += a[4], a[4] = 0;
            }
        }
    }

    if (a[3]) {
        // 2 现在只能给 3 用了
        if (a[2] && a[1]) {
            ans++, a[2]--, a[1]--, a[3] = 0;
        } else if (a[1] >= 3) {
            a[1] -= 3, ans++, a[3] = 0;
        } else if (a[2] >= 2) {
            a[2] -= 2, a[3] = 0, ans++;
        } else {
            a[1] += a[3], a[3] = 0;
        }
        // 如果这里不能消耗3，那么转换成1
    }
    {
        // 可能还有2
        ans += a[2] / 3, a[2] %= 3;
    }
    {
        // 可能还会剩1和2
        if (a[2] == 1) {
            if (a[1] >= 4) {
                ans++, a[2] = 0, a[1] -= 4;
            }
        } else if (a[2] == 2) {
            if (a[1] >= 2) {
                ans++, a[2] = 0, a[1] -= 2;
            }
        }
        // 只剩1了应该
        ans += a[1] / 6, a[1] %= 6;
    }
    // for (int i = 1; i <= 5; i++)
    //     cerr << a[i] << " \n"[i == 5];
    cout << ans << '\n';
}
/*
1 2 3 4 5
0 2 3 4 4, 1
0 2 1 4 4, 2
0 2 0 4 3, 3
0 0 0 4 1, 5
0 0 0 3 0, 6
*/
// int main()
signed main()
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