#include <bits/stdc++.h>
// #include "/home/skadi/codes/cp_code/template/debug.hpp"

using namespace std;
using ll = long long;

constexpr int N = int(1e7);
int minp[N + 1];
vector<int> primes;
void ChatGptDeepSeek() // Date: 2025-06-28
{                      // Time: 21:30:07
    ll L, R;
    cin >> L >> R;
    // map<int, int> mp;
    int ans = 0;
    set<int> st;
    for (auto p : primes)
    {
        if (p > R)
            break;
        int cnt = 1;
        ll now = p;
        while (now * p <= L)
        {
            now *= p;
        }
        if (now >= L)
            st.insert(now);
        while (now * p <= R)
        {
            now *= p;
            st.insert(now);
        }
        cerr << p << '\n';
    }
    // dbg(st);
    cout << st.size() << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 2; i <= N; i++)
    {
        if (minp[i])
            continue;
        minp[i] = i;
        primes.push_back(i);
        if (ll(i) * i > N)
            continue;
        for (ll j = i * i; j <= N; j += i)
            minp[j] = i;
    }
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}