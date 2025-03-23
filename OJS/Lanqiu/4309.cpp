// Date: 2025-03-23
// Time: 23:13:52
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    priority_queue<int, vector<int>, greater<>> pq;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            cnt++;
        else if(a[i]%2==0)
            pq.push(a[i]);
    }
    constexpr int mod = 998244353;
    long long ans = 1;
    while (cnt && !pq.empty())
    {
        ans = ans * (pq.top() + 1) % mod;
        // cerr<<ans<<'\n';
        pq.pop();
        cnt--;
    }
    while (!pq.empty())
    {
        ans = ans * pq.top() % mod;
        pq.pop();
    }
    for (int i = 0; i < n; i++)
        if (a[i] & 1)
            ans = ans * a[i] % mod;
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
        ChatGptDeepSeek();
    return 0;
}