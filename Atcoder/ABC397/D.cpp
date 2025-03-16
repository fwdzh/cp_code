// Date: 2025-03-15
// Time: 20:22:09

#include <bits/stdc++.h>
using namespace std;
// using ll = unsigned long long;
using ll = __int128;

constexpr ll inf = 1e20;

void ChatGptDeepSeek()
{
    set<ll> st;
    long long n;
    cin >> n;
    auto work = [&](ll x) {
        for (int i = 1;; i++) {
            if ((ll)i * i * i == x)
                return i;
        }
    };
    for (int i = 1; i <= 5e6; i++) {
        ll x = (ll)i * i * i;
        // if (x > inf)
        //     cerr << i << '\n';
        if (!st.empty() && x - *st.rbegin() > n) {
            // cerr << i << '\n';
            break;
        }
        st.insert(x);
        if (st.contains(x - n)) {
            cout << i << " " << work(x - n) << '\n';
            return;
        }
    }
    cout << "-1\n";
} // 100 100 100

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