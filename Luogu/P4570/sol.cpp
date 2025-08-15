#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    int n; cin >> n;
    vector<pair<LL, LL>> v(64, {0, 0});
    LL ans = 0;
    auto Insert = [&](LL x, int idx){
        pair<LL, LL> mn{LLONG_MAX, LLONG_MAX};
        for(int i = 63; i >= 0; i--){
            if(x >> i & 1){
                if(v[i].first){
                    x ^= first;
                    mn = min(mn, v[i]);
                }else{
                    v[i] = {x, idx};
                    return true;
                }
            }
        }
        if(mn < )
    };
    for(int i = 1; i <= n; i++){
        LL number, magic;
        cin >> number >> magic;

    }
    return 0;
}