// Date: 2025-03-23
// Time: 14:02:38
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 1e5;
set<int> pri,wa;
vector<bool> is(N + 1);

void ChatGptDeepSeek()
{
    pri=wa;
    int n;
    cin >> n;
    ll sum = 0;
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    vector<int> ans;
    int cnt = 0;
    for (cnt = 0; cnt < n / 3 - 1;)
    {
        if (pri.empty() || st.empty())
        {
            // cerr << "empty()!!!" << " " << cnt << '\n';
            break;
        }
        // if (rand() % 30 == 1)
        // {
        //     ans.push_back(*st.begin());
        //     sum+=*st.begin
        //     st.erase(st.begin());
        // }
        ll nxt = *pri.begin();
        // cerr<<"Nxt : "<<nxt<<' ';
        ll sz = ans.size() + 1;
        bool find = true;
        {
            /* sum+x<=sz*nxt
               sum+x>sz*(nxt-1)
            */
            auto i1 = st.upper_bound(sz * nxt - sum);
            auto i2 = st.upper_bound(sz * (nxt - 1) - sum);
            if (i1 == st.begin() || i2 == st.end())
            {
                find = false;
            }
            else
            {
                i1 = prev(i1);
                if (*i2 <= *i1)
                {
                    ans.push_back(*i2);
                    // cnt++;
                    sum += *i2;
                    // cerr << *i2 << '\n';
                    st.erase(i2);
                    cnt++;
                }
                else
                    find = false;
            }
            if (!find)
            {
                // sum += *st.begin();
                // st.erase(st.begin());

                pri.erase(pri.begin());
            }
        }
    }
    for(auto x:st)
        ans.push_back(x);
    for(auto x:ans)
        cout<<x<<" ";
        cout<<'\n';
    // cerr << cnt << '\n';
}
/*
2 1 3 4, 10/4 3
2 1 3 4 5, 15/5 3
2 1 3 4 5 6, 21/6 4
2 1 3 4 5 6 7, 28/7 4
2 1 3 4 5 8 7 6, 36/8 5
2 1 3 4 5 8 7 6 9, 45/9 5
2 1 3 4 5 8 7 6 9 10 , 55/10 6
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 2; i <= N; i++)
    {
        if (is[i])
            continue;
        // pri.push_back(i);
        pri.insert(i);
        if (1LL * i * i > N)
            continue;
        for (long long j = i * i; j <= N; j += i)
        {
            is[j] = true;
        }
    }
    wa=pri;
    // cerr << pri.size() << '\n';
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}