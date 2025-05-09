#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define cln cerr << "LINE: " << __LINE__ << " "
constexpr int N = int(5e6);
// bitset<N+1>is;
int minp[N + 1];
// vector<int>primes;
struct node{
    int fir_len, fir_col, sec_len, sec_col;
    node(int val = 0){fir_len = fir_col = sec_len = sec_col = val;}
};
node info[N + 1];
// vector<vector<int>>f(N + 1);

void solve()
{
    int n;
    cin >> n;
    vector<int>w(n + 1), c(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    int ans = 0;
    auto work = [&](int x,int idx){
        /*
        需要记录的是，相同的质因子，最长的长度和次长的长度对应的颜色
        这两个一定颜色不同，颜色相同肯定是一样的长度
        */
        int cur = 0;
        vector<int> p;
        while(x != 1){
            int prime = minp[x];
            while(x % prime == 0)
                x /= prime;
            // 咋搞来着，记最长的颜色和长度，次长的颜色和长度
            if(c[idx] == info[prime].fir_col) cur = max(cur, info[prime].sec_len);
            else cur = max(cur, info[prime].fir_len);
            p.push_back(prime);
        }
        ans = max(ans, ++cur);
        for(auto prime : p){
            if(info[prime].fir_col == c[idx])
                info[prime].fir_len = max(info[prime].fir_len, cur);
            else if(cur > info[prime].sec_len){
                info[prime].sec_col = c[idx];
                info[prime].sec_len = cur;
            }
            if(info[prime].fir_len < info[prime].sec_len){
                swap(info[prime].fir_col, info[prime].sec_col);
                swap(info[prime].fir_len, info[prime].sec_len);
            }
        }
    };
    for(int i = 1; i <= n; i++)
        work(w[i], i);
    cout << ans << '\n';
}
int main()
{
    // freopen("2.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    for(int i = 2; i <= N; i++){
        if(minp[i]) continue;
        minp[i] = i;
        if((ll)i * i > N) continue;
        for(int j = i * i; j <= N; j += i)
            minp[j] = i;
    }
    // for(int i = 1;i <=35;i++)
    //     cln << minp[i] << '\n';
    // cerr << primes.back() << '\n';
    // cerr << primes.size() << '\n';
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}