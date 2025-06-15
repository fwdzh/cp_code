#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    vector<ll> f(18);
    f[0] = 1;
    for(int i = 1; i <= 17; i++)
        f[i] = f[i - 1] * 5;
    vector<ll> cnt(18);
    cnt[2] = 45;
    for(int i = 3; i <= 17; i++)
        cnt[i] = cnt[i - 1] * 5;
    
    auto get = [&](ll x){
        ll res = 0;
        string tmp = to_string(x);
        int len = tmp.size();
        vector<int> a(18);
        for(int i = 0; i < len; i++)
            a[i] = tmp[i] - '0';
        for(int i = 1; i < len; i++)
            res += cnt[i];
        res += (a[0] - 1) * f[len - 1];
        bool ok = true;
        for(int i = 1, p = (a[0] & 1) ^ 1; i < len; i++, p ^= 1){
            if((a[i] & 1) != p){
                int cnt = 0;
                for(int j = p; j < a[i]; j += 2)
                    cnt++;
                res += cnt * f[len - i -1];
                ok = false;
                break;
            }else{
                int cnt = 0;
                for(int j = p; j < a[i]; j += 2)
                    cnt++;
                res += cnt * f[len - i -1];
            }
        }
        if(ok) res++;
        return res;
    };
    ll n;
    cin >> n;
    ll lo = 9, hi = ll(1e17);
    while(lo < hi - 1){
        ll mid = (lo + hi) >> 1;
        if(get(mid) >= n) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
    return 0;
}