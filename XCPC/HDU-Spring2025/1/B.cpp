#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 998244353;

ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll inv(ll x) { return ksm(x, mod - 2); }

void ChatGptDeepSeek()
{
    int n, k, win;
    cin >> n >> k >> win;
    --win;
    vector<int> p(k), f(k, 1);
    for (int i = 0; i < k; i++)
        cin >> p[i], --p[i];
    sort(p.begin(),p.end());
    ll ans = 1;
    ll iv2 = inv(2);
    while (!p.empty()) {
        win >>= 1;
        vector<int> b, g;
        for (int i = 0; i < p.size(); i++) {
            if ((p[i] >> 1) == win) {
                ans = (ans * (1 - f[i])) % mod;
                ans = (ans + mod) % mod;
            } else {
                b.push_back(p[i] >> 1);
                if (i + 1 < p.size() && (p[i] >> 1) == (p[i + 1] >> 1)) {
                    g.push_back(1LL * (f[i] + f[i + 1]) * iv2 % mod);
                    i++;
                } else if ((p[i] ^ 1) < n) {
                    g.push_back(1LL * f[i] * iv2 % mod);
                } else {
                    g.push_back(f[i]);
                }
            }
        }
        p = b, f = g;
        n = (n + 1) / 2;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}