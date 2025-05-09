#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> a(k + 1), t(n + 1), c(n + 1);
    for(int i = 1; i <= k; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> t[i] >> c[i];
    // for(int i = 1; i <= n; i++) cin >> c[i];

    auto check = [&](int T){
        vector<ll> need(a);
        for(int i = 1; i <= T; i++){
            need[t[i]] -= c[i];
        }
        vector<ll> stk1, stk2;
        for(int i = 1; i <= k; i++){
            if(need[i] < 0) stk1.push_back(-need[i]);
            else if(need[i] > 0) stk2.push_back(need[i]);
        }
        while(stk1.size() && stk2.size()){
            auto x = stk1.back(), y = stk2.back();
            // cerr << x << " " << y << '\n';
            stk1.pop_back(), stk2.pop_back();
            if(3 * x > y){
                stk1.push_back(x - y / 3);
            }else{
                y -= 3 * x;
                if(y >= 3) stk2.push_back(y);
            }
        }
        return stk1.empty();
    };
    int lo = 0, hi = n + 1;
    while(lo < hi - 1){
        int mid = (lo + hi) >> 1;
        if(check(mid)) lo = mid;
        else hi = mid;
    }
    // cerr << check(5) << '\n';
    cout << lo << '\n';
    return 0;
}