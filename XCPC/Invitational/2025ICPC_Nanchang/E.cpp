#include<bits/stdc++.h>
// #include "C:/codes/cp_code/template/debug.hpp"
using namespace std;
#define int long long
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

struct node {
    int l, r, idx;
};

constexpr int mod = 1000000009;
constexpr int MOD = 998244353;
mt19937_64 rng(time(NULL));
ll rand_integer(ll l, ll r) {
    uniform_int_distribution<ll> dis(l, r);
    return dis(rng);
}

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    string s;
    cin >> s;
    vector<int> pos(n + 1);
    
    vector<ull> val(26), pre(n + 1);
    for(int i = 0; i < 26; i++)
        val[i] = rng();
    vector<int> cnt(26);

    for(int i = 1; i <= n; i++){
        int x = s[i - 1] - 'a';
        cnt[x] = (cnt[x] + 1) % k;
        for(int j = 0; j < 26; j++)
            pre[i] += val[j] * cnt[j];
    }
    {
        vector<pair<ull, ull>> tmp(n + 1);
        for(int i = 0; i <= n; i++)
            tmp[i] = {pre[i], i};
        ranges::sort(tmp);
        int tot = 1;
        ull lst = tmp[0].first;
        tmp[0].first = 1;
        for(int i = 1; i <= n; i++){
            if(tmp[i].first != lst){
                ++tot;
                lst = tmp[i].first;
            }
            tmp[i].first = tot;
        }
        ranges::sort(tmp, [](pii x, pii y){return x.second < y.second;});
        for(int i = 0; i <= n; i++) pre[i] = tmp[i].first;
    }
    // dbg(pre);
    int siz = sqrt(n);
    for (int i = 1; i <= n; i++) {
        pos[i] = i / siz;
    }

    vector<node> ask(q);
    for (int i = 0; i < q; i++) {
        cin >> ask[i].l >> ask[i].r;
        ask[i].l--;
        ask[i].idx = i;
    }

    ranges::sort(ask, [&](node x, node y) {
        return (pos[x.l] == pos[y.l]) ? (x.r < y.r) : (pos[x.l] < pos[y.l]);
    });

    vector<int> res(q), mp(n + 10);
    ll ans = 0;
    int L = 0, R = -1;

    auto add = [&](int i) {
        ans += mp[pre[i]]++;
    };

    auto del = [&](int i) {
        ans -= --mp[pre[i]];
    };

    for (auto [l, r, idx] : ask) {
        while (L < l) del(L++);
        while (L > l) add(--L);
        while (R < r) add(++R);
        while (R > r) del(R--);
        res[idx] = ans;
    }

    for (int i = 0; i < q; i++) {
        cout << res[i] << '\n';
    }
}

int32_t main() {
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while(T--)
        solve();
    return 0;
}