#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

constexpr int N = int(5e5) + 5;
vector<set<pii>>st(N);

int minp[N + 1];

void solve()
{
    int n;
    cin >> n;
    auto Ins = [&](int x, int y){
        auto it = st[x].lower_bound({y, -1});
        if(it == st[x].end() || (*it).first != y)
            st[x].insert({y, 1});
        else{
            auto [u, v] = *it;
            st[x].erase(it);
            st[x].insert({y, v + 1});
        }
    };
    auto Del = [&](int x, int y){
        auto it = st[x].lower_bound({y, -1});
        auto [u, v] = *it;
        st[x].erase(it);
        if(v - 1)
            st[x].insert({y, v - 1});
    };
    while(n--){
        char op;
        cin >> op;
        if(op == '+'){
            int x, y;
            cin >> x >> y;
            while(x != 1){
                int p = minp[x];
                while(x % p == 0)
                    x /= p;
                Ins(p, y);
            }
        }else if(op == '-'){
            int x, y;
            cin >> x >> y;
            while(x != 1){
                int p = minp[x];
                while(x % p == 0)
                    x /= p;
                Del(p, y);
            }
        }else{
            int k;
            cin >> k;
            int ans = 0;
            while(k != 1){
                int p = minp[k];
                while(k % p == 0)
                    k /= p;
                if(st[p].size())
                    ans = max(ans, (*st[p].rbegin()).first);
            }
            cout << ans << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    for(int i = 2; i <= N; i++){
        if(minp[i]) continue;
        minp[i] = i;
        if((ll)i * i > N) continue;
        for(int j = i * i; j <= N; j += i)
            minp[j] = i;
    }
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}