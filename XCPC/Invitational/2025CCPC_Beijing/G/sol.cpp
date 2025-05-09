#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(6e6);
bitset<N+1>is;
vector<int>primes;
int len[N + 1],nel[N + 1];
vector<vector<int>>f(N + 1);

void solve()
{
    int n;
    cin >> n;
    vector<int>w(n + 1), c(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    auto work = [&](int x,int idx){
        vector<int> p;
        int max_len = 0;
        for(int i = 0;i < (int)primes.size(); i++){
            if(primes[i] > x) break;
            if(x == 1) break;
            assert(x >= primes[i]);
            if(x % primes[i]) continue;
            while(x % primes[i] == 0){
                x /= primes[i];
            }
            p.push_back(primes[i]);
            int current = 1;
            for(auto y : f[primes[i]])
                if(y != c[idx]) current = max(current, len[primes[i]] + 1);
                else current = max(current, len[primes[i]]);
            max_len = max(max_len, current);
        }
        for(auto y : p){
            if(len[y] < max_len){
                len[y] = max_len;
                f[y].clear();
                f[y].push_back(c[idx]);
            }else{
                assert(len[y] == max_len);
                if(f[y].size() < 2){
                    if(f[y].empty() || (f[y][0] != c[idx]))
                        f[y].push_back(c[idx]);
                }
            }
        }
    };
    for(int i = 1; i <= n; i++)
        work(w[i], i);
    cout << *max_element(len, len + N + 1) << '\n';
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    for(int i = 2; i <= N; i++){
        if(is[i]) continue;
        primes.push_back(i);
        if((ll)i * i > N) continue;
        for(int j = i * i; j <= N; j += i)
            is[j] = 1;
    }
    // cerr << primes.back() << '\n';
    // cerr << primes.size() << '\n';
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}