#include<bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int N = 400500;
vector<int> primes;
int minp[N + 1], cnt1[N + 1];
vector<vector<int>> res;
vector<int> get(int k){
    if(!res[k].empty() || k == 1){
        return res[k];
    }
    int n = k;
    while(k != 1){
        // cerr << k << "\n";
        int p = minp[k];
        res[n].push_back(p);
        while(k % p == 0)
            k /= p;
    }
    // for(auto p : res)
    //     cerr << p << " ";
    // cerr << '\n';
    return res[n];
}
void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] % 2 == 0) cnt++;
    if(cnt >= 2) cout << "0\n";
    else{
        // {
        //     vector<int> c(a);
        //     sort(c.begin() + 1, c.end());
        //     for(int i = 1; i + 1 <= n; i++){
        //         if(c[i] > 1 && c[i] == c[i + 1]){
        //             cout << "0\n";
        //             return;
        //         }
        //     }
        // }
        vector<int> ord(n + 1);
        iota(ord.begin() + 1, ord.end(), 1);
        sort(ord.begin() + 1, ord.end(), [&](int x, int y){
            return b[x] < b[y];
        });
        LL ans = b[ord[1]] + b[ord[2]];
        if(cnt){
            if(a[ord[1]] & 1) ans = min(ans, 0LL + b[ord[1]]);
            if(a[ord[2]] & 1) ans = min(ans, 0LL + b[ord[2]]);
        }
        for(int i = 1; i <= n; i++){
            for(auto p : get(a[i])){
                if(cnt1[p]) ans = 0;
                cnt1[p]++;
            }
        }
        for(int i = 1; i <= n; i++){
            for(auto p : get(a[i]))
                cnt1[p]--;
            for(LL j = 1; j * b[i] < ans && a[i] + j <= N; j++){
                LL x = a[i] + j;
                for(auto p : get(x)){
                    if(cnt1[p]){
                        ans = min(ans, j * b[i]);
                        break;
                    }
                }
            }
            for(auto p : get(a[i]))
                cnt1[p]++;
        }
        for(int i = 1; i <= n; i++)
            for(auto x : get(a[i]))
                cnt1[x] = 0;
        cout << ans << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for(int i = 2; i <= N; i++){
        if(!minp[i]){
            minp[i] = i;
            primes.push_back(i);
        }
        for(auto p : primes){
            if(i * p > N) break;
            minp[i * p] = p;
        }
    }
    res.assign(N + 1, {});
    // get(144);
    // return 0;
    // cerr << primes.size() << " " << primes.back() << '\n';
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}