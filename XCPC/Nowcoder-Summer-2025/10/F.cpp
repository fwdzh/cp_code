#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 1000000 + 10;
pair<int, int> ans;
mt19937_64 rng(time(NULL));
int rnd(int l, int r)
{
    uniform_int_distribution<int> dis(l, r);
    return dis(rng);
}
int cnt[N], pre[N], mid[N];
void solve()
{
    int n; cin >> n;
    vector<int> a(n + 10), pos(n + 10);
    int siz = sqrt(n);
    for(int i = 1; i <= n; i++)
        cin >> a[i], cnt[a[i]]++, pos[i] = i / siz;
    vector<pair<int, int>> vec;
    for(int i = 1; i <= 5 * n; i++){
        int L = rnd(2, n - 1);
        int R = rnd(L + 1, n);
        vec.push_back({L, R});
    }
    // cerr << vec.size() << '\n';

    ranges::sort(vec);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    ranges::sort(vec, [&](pair<int, int> x, pair<int, int> y){
        return pos[x.first] == pos[y.first] ? x.second < y.second : pos[x.first] < pos[y.first];
    });
    // cerr << vec.size() << '\n';
    // for(auto [l, r] : vec)
        // cerr << l << " " << r << '\n';

    auto check1 = [&]() {
        int LL = 1, RR = 0, num = 0, res = 0;
        for(int i = 1; i <= n; i++){
            if(cnt[a[i]] > 2) pre[a[i]] = mid[a[i]] = 0;
        }
        auto check = [&](int x){
            return mid[x] && mid[x] < pre[x] && pre[x] < cnt[x];
        };
        for(auto [l, r] : vec){
            while(l > LL){
                assert(LL <= n);
                assert(LL > 0);
                if(cnt[a[LL]] > 2){
                    if(check(a[LL]))
                        num--;
                    mid[a[LL]]--;
                    if(check(a[LL]))
                        num++;
                }
                ++LL;
            }
            while(l < LL){
                // add(--LL);
                --LL;
                assert(LL <= n);
                assert(LL > 0);
                if(cnt[a[LL]] > 2){
                    if(check(a[LL]))
                        num--;
                    mid[a[LL]]++;
                    if(check(a[LL]))
                        num++;
                }
            }
            while(r > RR){
                // add(++RR);
                ++RR;
                assert(RR <= n);
                assert(RR > 0);
                if(cnt[a[RR]] > 2){
                    if(check(a[RR]))
                        num--;
                    mid[a[RR]]++, pre[a[RR]]++;
                    if(check(a[RR]))
                        num++;
                }
            }
            while(r < RR){
                // del(RR--);
                assert(RR <= n);
                assert(RR > 0);
                if(cnt[a[RR]] > 2){
                    if(check(a[RR]))
                        num--;
                    pre[a[RR]]--, mid[a[RR]]--;
                    if(check(a[RR]))
                        num++;
                }
                --RR;
            }
            if(num > res){
                ans = {l, r + 1};
                res = num;
            }
        }
        return res;
    };
    ans = {2, 3};

    cout << check1() << '\n';
    cout << ans.first << " " << ans.second << '\n';
    for(int i = 1; i <= n; i++)
        cnt[a[i]] = 0;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    {solve();} return 0;
}