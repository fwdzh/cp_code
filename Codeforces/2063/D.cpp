// Date: 2025-03-12
// Time: 09:59:43

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    // 主要是看上面取多少个 下面取多少个
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    int U = 0, D = 0;
    for (int i = 1; i <= n; i++) {
        
    }
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