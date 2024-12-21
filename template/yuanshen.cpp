// Author: Zhangwuji
// Date: 2024-12-18
// Time: 00:05:39

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

// constexpr int N = 2e5;
// struct Fenwick{
//     int b[N+5]={};
//     int lowbit(int x){return (x)&(-x);}
//     void add(int i,int x){
//         while(i<=N){
//             b[i]+=x;
//             i+=lowbit(i);
//         }
//     }
//     int get(int i){
//         int res=0;
//         while(i){
//             res+=b[i];
//             i-=lowbit(i);
//         }
//         return res;
//     }
//     int query(int l,int r){
//         return get(r)-get(l-1);
//     }
// };

int main()
{
    
    return 0;
}