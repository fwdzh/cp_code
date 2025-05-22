#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr int mod = 998244353;

constexpr int N = int(2e5);
ll fac[N + 1], inv[N + 1];

ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod, b >>= 1;
    }
    return res;
}
ll C(ll n, ll m) { return fac[n] * inv[m] % mod * inv[n - m] % mod; }

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(count(s.begin(), s.end(), '1') < k){
        cout << "0\n";
        return;
    }
    s = " " + s;
    vector<int> pos(n + 1, 1), pre(n + 1);
    queue<int> q;
    int cnt = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (s[i] == '1');
        if (s[i] == '1')
            cnt++;
        while (cnt > k)
            if (s[j++] == '1')
                cnt--;
        if (cnt < k)
            pos[i] = 1;
        else
            pos[i] = j;
    }
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        // cerr << pos[i] << " \n"[i == n];
        dp[i] = dp[i - 1];
        // if (pos[i] == 0)
        //     continue;
        if (s[i] == '1') {
            if (i - pos[i] + 1 == pre[i] - pre[pos[i] - 1])
                continue;
            // 反正都是看中间的 0 的个数，要放两个 1
            dp[i] = (dp[i] + C(i - pos[i], pre[i] - pre[pos[i] - 1])) % mod;
        } else {
            // 中间要放多少个0
            if(pre[i] - pre[pos[i] - 1])
                dp[i] = (dp[i] + C(i - pos[i], pre[i] - pre[pos[i] - 1] - 1)) % mod;
        }
    }
    dp[n] = (dp[n] + mod) % mod;
    cout << dp[n] << '\n';
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = (ll)fac[i - 1] * i % mod;
    inv[N] = ksm(fac[N], mod - 2);
    for (int i = N - 1; i >= 0; i--)
        inv[i] = (ll)inv[i + 1] * (i + 1) % mod;

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}