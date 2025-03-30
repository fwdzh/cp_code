#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    int cnt = 0;
    long long sum = 0;
    for (int KK = 1; KK <= k; KK++)
    {
        bool ok = true;
        for (int i = 1; i + 1 <= n; i++)
        {
            int x = b[i] + KK, y = b[i + 1] + KK;
            if (__gcd(x, y) == min(x, y))
            {
            }
            else{
                ok = false;break;
            }
        }
        if (ok)
            cnt++, sum += KK;
    }
    cout << cnt << " " << sum << '\n';
}

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