#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 998244353;

ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
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
    int n, k;
    cin >> n >> k;
    vector<int> p(k + 1);
    vector<bool> t(n + 1);
    for (int i = 0; i <= k; i++)
        cin >> p[i], t[p[i]] = true;
    
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