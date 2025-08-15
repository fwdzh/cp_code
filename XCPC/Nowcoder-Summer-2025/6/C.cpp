#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(5e5) + 1;
constexpr int mod = 998244353;
int ans[N];

void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << '\n';
}
int main()
{

    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    // freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    
    /*
    (x + 1) ^ 3 = (x * x + 2x + 1) * (x + 1)
    = (x * x * x + 2 x * x + x + x * x + 2 x + 1)
    = (x * x * x + 3 * x * x + 3 * x + 1)

    2 : [1, 2] , [2, 1]
    3 :
    size = 1, [3, 2, 1] [2, 3, 1] 
    size = 2, [3, 1, 2] [3, 2, 1] [2, 1, 3]
    size = 3, [1, 2, 3]

    f(a) 的 size = x 的数量，等于 f(a - 1) 的 size = x - 1 的数量 + size = x 的的数量乘以(i - 1)
    
    sum [cnt[i] * (i ^ 3)]
    how sum [cnt[i] * ((i + 1) ^ 3)]
    (i + 1) ^ 3 = i ^ 3 + 3 * (i ^ 2) + 3 i + 1
    相当于

    cnt[i][x] = cnt[i - 1][x] * (i - 1) + cnt[i - 1][x - 1]
    cnt[i + 1][x] = cnt[i][x] * i + cnt[i][x - 1]
                  = cnt[i - 1][x] * (i - 1) * i + cnt[i - 1][x - 1] * i
    
    [0, 1]
    [0, 1, 1]
    [0, 2, 3, 1]
    [0, ]
    cnt[1][1] = 1

    cnt[2][1] = cnt[1][0] * 1 + cnt[1][1]
    cnt[2][2] = cnt[1][1] * 1 + cnt[1][2]

    cnt[3][1] = cnt[2][1] * 2 + cnt[2][0]
              = cnt[1][1] * f[2]
    cnt[3][2] = cnt[2][2] * 2 + cnt[2][1]
              = (cnt[1][1] + cnt[1][2]) * 2 + cnt[1][0] + cnt[1][1]
    不好推阿 而且就算推出了cnt的关系
    也没办法快速知道答案

    896*5
    */
    // for(int i = 1; i <= 10; i++){
    //     vector<int> a(i), cnt(i + 1);
    //     iota(a.begin(), a.end(), 1);
    //     do{
    //         vector<int> stk;
    //         for(auto x : a){
    //             while(stk.size() && stk.back() > x)
    //                 stk.pop_back();
    //             stk.push_back(x);
    //         }
    //         cnt[stk.size()]++;
    //     }while(next_permutation(a.begin(), a.end()));
    //     ll ans = 0;
    //     for(int x = 1; x <= i; x++)
    //         ans = (ans + cnt[x] * (1LL * x * x * x  % mod)) % mod;
    //     cerr << ans << '\n';
    // }
    ll sum[4]{1, 1, 1, 1};
    ans[1] = 1;
    // ll A = 1;
    // sum1 是 sum [i * a[i]] sum2 是 sum[i * i * a[i]]
    for(int i = 2; i <= N; i++){
        sum[3] = (sum[3] * i % mod + 3 * sum[2] + 3 * sum[1] + sum[0]) % mod;

        sum[2] = (sum[2] * i % mod + 2 * sum[1] + sum[0]) % mod;
        sum[1] = (sum[1] * i % mod + sum[0]) % mod;
        sum[0] = sum[0] * i % mod;
        
        ans[i] = sum[3];

        // ans[i] = (ans[i - 1] * (i - 1) + sum[3]);
        // if(i <= 10){
        //     cerr << format("sum:[{}, {}, {}, {}], ans : {}\n", sum[0], sum[1], sum[2], sum[3], ans[i]);
        // }
    }
    int t; cin >> t; while(t--)
    {solve();} return 0;
}