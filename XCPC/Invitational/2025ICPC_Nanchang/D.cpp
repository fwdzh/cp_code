#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<vector<int>> vec1(3, vector<int>(n)), vec2(3, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> vec1[j][i];
        for (int j = 0; j < 3; j++)
            cin >> vec2[j][i];
    }
    int ans = 0;
    auto work = [&](vector<int> a, vector<int> b) {
        /* 离散化一下
         * 对于一个 x，我们需要找 a <= x && b >= x 的 pair 的数量
         * 差分确实很对啊。。。赛时写得是树状数组调好久 还好队友帮我造了很多数据
         */
        {
            vector<pii> tmp(2 * n);
            for (int i = 0; i < n; i++) {
                tmp[i].first = b[i];
                tmp[i].second = i;
            }
            for (int i = 0; i < n; i++) {
                tmp[i + n].first = a[i];
                tmp[i + n].second = i + n;
            }
            ranges::sort(tmp);
            int tot = 1, lst = tmp[0].first;
            tmp[0].first = 1;
            for (int i = 1; i < 2 * n; i++) {
                if (tmp[i].first != lst) {
                    ++tot;
                    lst = tmp[i].first;
                }
                tmp[i].first = tot;
            }
            ranges::sort(tmp, [](pii x, pii y) {
                return x.second < y.second;
            });
            for (int i = 0; i < n; i++) {
                b[i] = tmp[i].first;
                // cerr << b[i] << ' ';
            }
            for (int i = 0; i < n; i++)
                a[i] = tmp[i + n].first;

        }
        vector<int> d(2 * n + 10);
        for (int i = 0; i < n; i++) {
            // cerr << a[i] << ' ' << b[i] << " \n";
            if (a[i] > b[i]) swap(a[i], b[i]);
            d[a[i]] += 1, d[b[i] + 1] -= 1;
        }
        int now = 0;
        for (int i = 1; i <= 2 * n; i++) {
            now += d[i];
            ans = max(ans, now);
        }
    };
    work(vec1[0], vec2[0]);
    work(vec1[1], vec2[1]);
    work(vec1[2], vec2[2]);
    cout << ans << '\n';
}
int main() {
    cout << fixed << setprecision(12);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}