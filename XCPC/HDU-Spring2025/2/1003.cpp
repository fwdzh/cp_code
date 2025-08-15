// Date: 2025-03-14
// Time: 19:26:45

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e6 + 114;

bool vis[N + 1];
int cnt[N + 1], lsst[N + 1];
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int suf = 0, lst = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]) {
            cnt[a[i]]++;
            if (cnt[a[i]] == 1)
                suf++;
        }
    }
    // 只要记一下第一个x的位置 和最近的0的位置就可以
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[i])
            lst = i;
        else {
            cnt[a[i]]--;
            if (!cnt[a[i]])
                suf--;
            if (!vis[a[i]]) {

                // cerr << lsst[a[i]] << " " << suf << '\n';
                if (lsst[a[i]] && lsst[a[i]] < lst) {
                    vis[a[i]] = true;
                    ans += suf;
                }
            }
            lsst[a[i]] = i;
        }
    }
    for (int i = 0; i <= N; i++) {
        vis[i] = false;
        cnt[i] = lsst[i] = 0;
    }
    cout << ans << '\n';
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