// #define YUANSHEN
#if defined(YUANSHEN)
#include "C:/codes/cp_code/template/debug.hpp"
#else
#include <bits/stdc++.h>
using namespace std;
#define dbg(...) 42
#endif

#define rep(N) for(int i = 1; i <= N; i++)

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
template <class T>
using vc = vector<T>;

#define fixset(x) fixed << setprecision(x)
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin() + 1, (x).end()
constexpr int INF = 1000000000;
constexpr ll LNF = 1000000000000000000LL;

// Date: 2025-05-13
// Time: 14:42:04
struct ST{
    vector<vector<int>> MIN;
    vector<vector<int>> MAX;
    ST(vector<int> &a){
        int n = a.size();
        MIN = MAX = vector<vector<int>> (n, vector<int> (__lg(n) + 1));
        n--;
        for(int i = 1; i <= n; i++)
            MIN[i][0] = MAX[i][0] = a[i];
        for(int k = 1; k <= __lg(n); k++){
            for(int s = 1; s + (1 << k) <= n + 1; s++){
                MIN[s][k] = min(MIN[s][k - 1], MIN[s + (1 << k) - 1][k - 1]);
            }
        }
    }
};

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<ll> pre(n + 1);
    /*
    不对不对。。。 how nlog n
    意思就是说 要满足找的值是区间max 还不要影响后面的操作。。。
    但是必须要往左边或者右边找 但是我们能控制修改的顺序

    向左:
        x 必须之前是 a[1, i - 1] 的区间 max
        也要小于等于 b[1, i - 1] 的区间 min

    向右:
        好像是和上面一样的吧（）
    
    不管了 先试试
    */
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}