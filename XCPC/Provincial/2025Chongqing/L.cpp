#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(2e5);
constexpr int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> stk;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        // cout << "size: " << stk.size() << '\n';
        string op;
        cin >> op;
        if(op == "Push"){
            int x;
            cin >> x;
            ans = (ans + x) % mod;
            stk.push_back(x);
        }else if(op == "Pop"){
            ans = (ans - stk.back()) % mod;
            stk.pop_back();
            ans = (ans + mod) % mod;
        }else{
            ans = ans * 2 % mod;
            if(stk.size() && stk.size() < n){
                int siz = stk.size();
                for(int j = 0; j < siz; j++)
                    stk.push_back(stk[j]);
            }
        }
        cout << ans << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}