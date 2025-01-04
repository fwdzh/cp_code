// Author: Zhangwuji
// Date: 2025-01-04
// Time: 22:52:30

// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif
template <typename T1, typename T2>
void cmin(T1& x, const T2& y)
{
    x = x < y ? x : y;
}
template <typename T1, typename T2>
void cmax(T1& x, const T2& y)
{
    x = x > y ? x : y;
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

void solve()
{
    int l,r;
    cin>>l>>r;
    if(r-l==2){
        cout<<l<<" "<<l+1<<" "<<r<<'\n';
        return;
    }
    int m=0,x=(1<<30)-1;
    int c=0;
    for(int i=30;i>=0;i--){
        int cur=1<<i;
        if((r>>i&1)==(l>>i&1)){
            if(r>>i&1){
                if((m|(cur-1))>=l){
                    continue;
                }
                m|=cur;
            }else{
                if((m|cur)<=r){
                    m|=cur;
                }
            }
        }
    }
    ll ans=(l^m)+(l^r)+(m^r);
    if(l==m){
        auto calc=[&](int x){
            if(x>=r||x<=l) return 0;
            return (x^l)+(x^r)+(l^r);
        };
        for(int i=0;i<30;i++){
            if(calc(l^(1<<i))){
                cout<<l<<" "<<(l^(1<<i))<<" "<<r<<'\n';
                    return;
                }
        }
    }
    cout<<l<<" "<<m<<" "<<r<<'\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
// cerr<<(6^9)+(6^22)+(9^22)<<'\n';
//     // 7 16 11
//     cerr<<(7^11)+(7^16)+(16^11)<<'\n';
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}