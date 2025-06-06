// Date: 2025-03-31
// Time: 21:10:30
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
    ll ask(int i)
    {
        ll res = 0;
        while (i > 0)
        {
            res += b[i];
            i -= lowbit(i);
        }
        return res;
    }
};
void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    Fenwick C(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            C.add(x, k);
            C.add(y + 1, -k);
        }
        else
        {
            int x;
            cin >> x;
            cout << C.ask(x) + a[x] << '\n';
        }
    }
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