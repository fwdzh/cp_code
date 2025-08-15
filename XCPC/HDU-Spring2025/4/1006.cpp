// Date: 2025-03-28
// Time: 18:54:40
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick
{
    vector<ll> b;
    Fenwick(int n)
    {
        b = vector<ll>(n + 1);
    }
    int lowbit(int x) { return (x) & (-x); }
    void add(int i, int x)
    {
        while (i && i < b.size())
        {
            b[i] += x;
            i += lowbit(i);
        }
    }
    ll query(int i)
    {
        ll res = 0;
        while (i)
        {
            res += b[i];
            i -= lowbit(i);
        }
        return res;
    }
};
void ChatGptDeepSeek()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    Fenwick C(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        C.add(i, a[i]);
    }
    int tot = 1;
    ll ans = 0;
    while (q--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            C.add(x, y - a[x]);
            a[x] = y;
        }
        else
        {
            ll res = C.query(y) / 100 - C.query(x - 1) / 100;
            ans = ans ^ (res * tot);
            tot++;
        }
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