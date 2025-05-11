#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define fi first
#define se second

void solve()
{
    // 只用枚举主对角线的两个点
    int n;
    cin >> n;
    vector<pii> p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    map<pii, int>mp;
    for(int i = 0; i < n; i++){
        mp[p[i]] = i;
    }
    int ans = 0;
    vector<int> cnt(n);
    for(int i = 0; i < n; i++){
        auto [x1, y1] = p[i];
        for(int j = i + 1; j < n; j++){
            auto [x2, y2] = p[j];
            int x3 = (x1 + x2) - (y1 - y2);
            int y3 = (y1 + y2) + (x1 - x2);
            int x4 = (x1 + x2) + (y1 - y2);
            int y4 = (y1 + y2) - (x1 - x2);
            if((x3 & 1) || (y3 & 1) || (x4 & 1) || (y4 & 1)) continue;
            x3 /= 2, y3 /= 2, x4 /= 2, y4 /= 2;
            if(mp.contains({x3, y3}) && mp.contains({x4, y4})){
                // cerr << format("{}, {}, {}, {}", x1, y1, x2, y2) << '\n';
                cnt[i]++, cnt[j]++;
                cnt[mp[{x3, y3}]]++, cnt[mp[{x4, y4}]]++;
                ans++;
            }
        }
    }
    // cerr << ans << '\n';
    // for(int i = 0; i < n; i++)
    //     cerr << format("{}", cnt[i]) << " \n"[i + 1 == n];
    cout << (ans - *min_element(cnt.begin(), cnt.end())) / 2 << '\n';
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}