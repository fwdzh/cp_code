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
#define int long long
using namespace std;

void ChatGptDeepSeek()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 1 || (*max_element(a.begin() + 1, a.end()) == *min_element(a.begin() + 1, a.end())))
    {
        cout << k << " " << 1LL * (1 + k) * k / 2 << '\n';
        return;
    }

    set<int> st;
    {
        for (int i = 2; i <= n; i++)
        {
            int x = a[i], y = a[i - 1];
            if (x == y)
                continue;
            if (x < y)
                swap(x, y);
            int z = x - y;
            // cerr<<"x y : "<<x<<" "<<y<<'\n';
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
            break;
        }
    }
    int g = 0;
    for (int i = 2; i <= n; i++)
    {
        int x = a[i - 1], y = a[i];

        if (x == y)
            continue;
        if (x < y)
            swap(x, y);
        g = __gcd(g, x - y);
        int z = x - y;
        if (z <= y)
        {
            cout << "0 0\n";
            return;
        }
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
        // for (auto it : st1)
        //     cerr << it << ' ';
        // cerr << '\n';
        st = st1;
    }
    // cout << st.size() << ' ';
    int cnt = 0;
    long long sum = 0;
    for (auto x : st)
    {
        // cerr << x << " ";
        if (x % g)
        {
            continue;
        }
        cnt++;
        sum += x;
    }
    // cerr << '\n';
    cerr << g << '\n';
    // assert(cnt == st.size());
    cout << cnt << '\n';
    cout << sum << '\n';
}
/*
11 11 1 1 1 13 11 13
10 5 2
12 6 2
*/
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