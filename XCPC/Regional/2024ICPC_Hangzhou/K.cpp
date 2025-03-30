/*
   3 5 2
 1 4 13 6 8 11 14 2 7 10 3 15 9 5 12

   1  2  3  4  5
   6  7  8  9  10
   11 12 13 14 15
*/
// Date: 2025-03-29
// Time: 15:23:28
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n * m + 1);
    for (int i = 1; i <= n * m; i++)
        cin >> p[i];
    if (k >= m)
    {
        cout << m << '\n';
        return;
    }
    vector<vector<int>> r(n + 1, vector<int>());
    for (int i = 1; i <= n * m; i++)
    {
        r[(p[i] + m - 1) / m].push_back(i);
    }
    int ans = n * m;
    for (int i = 1; i <= n; i++)
    {
        /* k m-k */
        int idx = r[i][m - k - 1];
        int rest = idx - (m - k);
        int res = (k > rest ? idx + (k - rest) : idx);
        ans = min(ans, res);
    }
    cout << ans << '\n';
}
/*
3 3 2
1 6 4 7 9 5 2 3 8
x+1
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}