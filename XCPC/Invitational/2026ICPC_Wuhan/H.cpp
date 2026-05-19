#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    multiset<int> a, b;
    a.insert(n), b.insert(m);
    set<int> aa, bb;
    aa.insert(0), aa.insert(n);
    bb.insert(0), bb.insert(m);
    while (q--)
    {
        int op, k;
        cin >> op >> k;
        if (op == 1)
        {
            auto it = aa.upper_bound(k);
            a.erase(a.find(*it - *prev(it)));
            a.insert(*it - k);
            a.insert(k - *prev(it));
            aa.insert(k);
        }
        else
        {
            auto it = bb.upper_bound(k);
            b.erase(b.find(*it - *prev(it)));
            b.insert(*it - k);
            b.insert(k - *prev(it));
            bb.insert(k);
        }
        cout << 1LL * *a.rbegin() * *b.rbegin() << "\n";
    }
}