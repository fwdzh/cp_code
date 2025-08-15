// Date: 2025-03-28
// Time: 18:32:24
#include <bits/stdc++.h>
#define int long long
// #include <C:/usr/codes/cp/template/debug.hpp>

using namespace std;

void ChatGptDeepSeek()
{
    long long n, u, k, hq;
    cin >> n >> u >> k >> hq;
    vector<int> cnt(n + 1);
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    vector<int> time(n + 1), lst(n + 1, 2 * u);
    multiset<int> st;
    for (int i = 1; i <= n; i++)
    {
        int a, h;
        cin >> a >> h; // 攻击 血量
        //  血量 攻击 下标
        pq.push({h, a, i});
        st.insert(a);
    }
    int ans = 0;
    while (!pq.empty())
    {
        auto [h, a, i] = pq.top();
        // assert(h >= 0 && time[i] <= k);
        pq.pop();
        // assert(i <= n);

        if (time[i] == 0)
        {
            h -= u;
            lst[i] = u;
        }
        else
        {

            h -= u / 2;
        }
        if (h <= 0)
        {
            ans++;
            st.erase(st.lower_bound(a));
        }
        if (st.empty())
            break;
        int hurt = *st.rbegin();

        time[i]++;

        hq -= hurt;
        if (hq <= 0)
        {
            break;
        }
        if (time[i] < k && h > 0)
        {
            pq.push({h, a, i});
        }
    }
    cout << n - st.size() << '\n';
}

signed main()
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