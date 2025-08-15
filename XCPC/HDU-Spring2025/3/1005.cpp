// Date: 2025-03-21
// Time: 18:35:45

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e5 + 10;
int f[N + 1];

int find(int x)
{
    // cerr << x << " " << f[x] << '\n';
    return f[x] == x ? x : f[x] = find(f[x]);
}

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // cerr << i << "\n";
        if (i - a[i] >= 1) {
            // cerr << i - a[i] << " " << find(i - a[i]) << '\n';

            f[find(i)] = find(i - a[i]);
            // f[i] = f[find(f[i - a[i]])];
        }
        if (i + a[i] <= n) {
            // cerr << i + a[i] << " " << find(i + a[i]) << '\n';
            f[find(i + a[i])] = find(f[i]);
            // f[i] = f[find(f[i + a[i]])];
        }

        // for (int j = 1; j <= n; j++)
        //     cerr << f[j] << " \n"[j == n];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (find(f[i]) == i)
            ans++;
        // cerr << f[i] << '\n';
    }
    cout << ans - 1 << '\n';
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