//13 10
//
// Author: Zhangwuji
// Date: 2025-01-23
// Time: 15:44:19

// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/cp_code/template/debug.hpp"
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
    int n,m;
    cin>>n>>m;
    //abcdefghijk... z
    //abz ....z 另外一边也得大于等于这个数字
    //也就是说 你需要值小1 右边有一个
    //4 2？
    // bzbz
    //len-1 z len z
    if(n-m>26||n==m){
        cout<<"NO\n";
        return;
    }
    int len=n-m;
    //abcdefg ... z abcd

    //az abz
    string s;
    for(int i=0;i<len-1;i++)
        s+=char('a'+0);
    s+='z';
    string ans=s;
    while(sz(ans+s)<n){
        ans+='z';
    }
    cout<<ans+s<<'\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}