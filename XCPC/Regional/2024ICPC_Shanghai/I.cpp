#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void ChatGptDeepSeek() // Date: 2025-04-13
{                      // Time: 14:47:32
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll res = 1;
    sort(a.begin() + 1, a.end(), greater<int>());
    for (int i = 1; i <= k; i++)
    {
        res = res * a[i] % 998244353;
    }
    if (a[k] == 0)
    {
        cout << a[1] % 998244353 << '\n';
        return;
    }
    for (int i = k + 1; i + k - 2 <= n; i += k - 1)
    {
        ll now = 1;
        for (int j = i; j <= i + k - 2; j++)
        {
            now *= a[j];
            now %= 998244353;
        }
        if (a[i + k - 2] == 0)
            break;
        res = res * now % 998244353;
    }
    cout << res << '\n';
} // 2 2 2 2
// 4 4 ,
//

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