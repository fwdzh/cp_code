#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    LL n; cin >> n;
    auto get = [&](LL lmt){
        vector<int> a;
        LL x = lmt;
        while(x){
            a.push_back(x % 10);
            x /= 10;
        }
        vector<LL>  dp(14);
        dp[0] = 1;
        dp[1] = 9;
        for(int i = 2; i <= 13; i++)
            dp[i] = dp[i - 1] * 9;
        LL ans = 0;
        for(int i = 1; i <= a.size() - 1; i++)
            ans += dp[i];
        cerr << ans << '\n';
        reverse(a.begin(), a.end());
        int m = a.size();
        cerr << m << '\n';
        bool ok = false;
        for(int i = 0; i < m; i++){
            if(i == 0){
                if(a[i] > 7) ans += (a[i] - 2) * dp[m - i - 1];
                else if(a[i] == 7){
                    ans += 6 * dp[m - i - 1];
                    ok = true;
                    break;
                }
                else ans += (a[i] - 1) * dp[m - i - 1];
                cerr << dp[m - i - 1] << " " << m - i - 1 << '\n';
            }else{
                if(a[i] > 7) ans += (a[i]) * dp[m - i - 1];
                else if(a[i] == 7){
                    ans += 7 * dp[m - i - 1];
                    ok = true;
                    break;
                }
                else ans += (a[i]) * dp[m - i - 1];
            }
        }
        if(!ok) ans++;
        if(a.size() == 1) ans++;
        return ans - 1;
    };
    // cerr << get(12) << '\n';
    LL lo = 0, hi = 2 * n;
    while(lo < hi - 1){
        LL mid = (lo + hi) >> 1;
        if(get(mid) >= n) hi = mid;
        else lo = mid;
    } 
    cout << hi << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}