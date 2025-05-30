// Author: Zhangwuji
// Date: 2025-01-17
// Time: 19:13:16

// #define YUANSHEN
#if defined(YUANSHEN)
#include "D:/cp/template/debug.hpp"
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
    int n,q;
    cin>>n>>q;
    vi a(n+1);
    set<int>st;
    for(int i=1;i<=n;i++){
        st.insert(i);
    }
    int tot=0;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int l,r;
            cin>>l>>r;
            if(st.empty()) continue;
            auto it=st.lower_bound(l);
            set<int>del;
            while(it!=st.end()&&*it<=r){
                a[*it]=++tot;
                del.insert(*it);
                it=next(it);
            }
            for(auto x:del)
                st.erase(x);
        }else{
            int x;
            cin>>x;
            cout<<a[x]<<'\n';
        }
    }
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}