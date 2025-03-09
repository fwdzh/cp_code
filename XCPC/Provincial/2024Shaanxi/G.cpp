// Date: 2025-03-09
// Time: 14:14:45

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ksm(ll a, int b)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve()
{
    ll n;
    int x;
    cin >> n >> x;
    // string s = to_string(n);
    // // 99
    // // 1
    // ll now = n;
    // auto get = [&](int l) {
    //     ll res = 0;
    //     // assert(t.size() == l-1);
    //     for (int i = 0; i < l ; i++)
    //         res = res * 10 + s[i] - '0';
    //     return res;
    // };
    // for (int i = 0; i < s.size(); i++) {
    //     // s = to_string(now);
    //     ll del = get(i);
    //     if (s[i] - '0' >= x)
    //         del++;
    //     now -= del * ksm(10, s.size() - i - 1);
    //     s = to_string(now);
    //     cerr << del << " " << now << '\n';
    // }
    // cout << now + 1 << '\n';
    auto work = [&](auto&& self, ll now, int i) {
        // cerr << now << " " << i << '\n';
        // 删除第i位的 x
        string s = to_string(now);
        if (i==-1) {
            // cout<<s<<"\n";
            cout << now + 1 << '\n';
            return;
        }
        while (s.size() < i)
            s = "0" + s;
        ll del = 0;
        for (int j = 0; j < s.size() - i - 1; j++)
            del = del * 10 + s[j] - '0';
        // cerr << del << " " << i << '\n';
        if (s[s.size() - i - 1] - '0' >= x)
            del++;
        self(self, now - del * ksm(10, i), i - 1);
    };
    work(work, n, to_string(n).size() - 1);
}
/*
12345678 9
12345678 9, -
11345678,-110*
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cerr << 6725583 - 6053445 << '\n';
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}