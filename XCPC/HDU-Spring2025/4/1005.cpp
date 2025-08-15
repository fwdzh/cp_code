// Date: 2025-03-28
// Time: 19:09:04
#include <bits/stdc++.h>
// #include <C:/usr/codes/cp/template/debug.hpp>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void ChatGptDeepSeek()
{
    int P, n, k;
    cin >> P >> n >> k;
    vector<double> p1(1, 1);
    vector<int> p2(1, 0);
    // priority_queue<int, vector<int>, greater<>> p1;
    // priority_queue<int> p2;
    for (int i = 1; i <= n; i++)
    {
        int t, p;
        cin >> t >> p;
        if (!t)
            p1.push_back(p / 10.0);
        else
            p2.push_back(p);
    }
    sort(p1.begin() + 1, p1.end());
    sort(p2.begin() + 1, p2.end(), greater<>());
    for (int i = 1; i < p1.size(); i++)
        p1[i] = p1[i - 1] * p1[i];
    //  cerr << p1[i] << " \n"[i + 1 == p1.size()];
    for (int i = 1; i < p2.size(); i++)
        p2[i] = p2[i - 1] + p2[i];
    //  cerr << p2[i] << " \n"[i + 1 == p2.size()];

    double ans = P;

    int s1 = p1.size() - 1, s2 = p2.size() - 1;
    for (int i = max(0, k - s2); i <= min(k, s1); i++)
    {
        if (k - i > s2)
            ans = min(ans, P * p1[i]);
        else
            ans = min(ans, P * p1[i] - p2[k - i]);
        // cerr << "P*p1 :" << P * p1[i] << " p2[k-i]: " << p2[k - i] << '\n';
        // cerr << i << " " << k - i << " " << ans << '\n';
    }
    ans = max(ans, 0.0);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}