/*
5 10
7 79 1 7 1

1 7 79

x y
gcd(x+k,y+k)=y+k
gcd(x-y,y+k)=y+k

*/
// Date: 2025-03-29
// Time: 17:04:03
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n + 1), a(1);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    // sort(a.begin() + 1, a.end());
    {
        set<int> st;
        for (int i = 1; i <= n; i++)
        {
            if (st.count(b[i]))
                continue;
            st.insert(b[i]);
            a.push_back(b[i]);
        }
        n = a.size() - 1;
        if (st.size() == 1)
        {
            cout << k << " " << 1LL * (1 + k) * k / 2 << '\n';
            return;
        }
    }
    set<int> st;
    {
        int x = a[1], y = a[2];
        if (x < y)
            swap(x, y);
        int z = x - y;
        for (int j = 1; j * j <= z; j++)
        {
            if (z % j == 0)
            {
                int KK = j - y;
                if (KK > 0 && KK <= k)
                    st.insert(KK);
                int l = z / j;
                KK = l - y;
                if (KK > 0 && KK <= k)
                    st.insert(KK);
            }
        }
    }
    for (int i = 3; i <= n; i++)
    {
        int x = a[i - 1], y = a[i];
        if (x < y)
            swap(x, y);
        int z = x - y;
        set<int> st1;
        for (int j = 1; j * j <= z; j++)
        {
            if (z % j == 0)
            {
                int KK = j - y;
                if (KK > 0 && KK <= k && st.count(KK))
                    st1.insert(KK);
                int l = z / j;
                KK = l - y;
                if (KK > 0 && KK <= k && st.count(KK))
                    st1.insert(KK);
            }
        }
        st = st1;
    }
    cout << st.size() << ' ';
    long long sum = 0;
    for (auto x : st)
    {
        // cerr << x << " ";
        sum += x;
    }
    // cerr << '\n';
    cout << sum << '\n';
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