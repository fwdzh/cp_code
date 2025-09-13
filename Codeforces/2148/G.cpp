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

// Date: 2025-09-13
// Time: 23:10:07
// constexpr int N = int(8e5) + 5;
// int tr[N], mx[N], my[N];
// #define ls p << 1
// #define rs p << 1 | 1
// #define mi ((l + r) >> 1)
// void change(int p, int l, int r, int i, int x){
//     if(l == r){
//         mx[p] = x;
//         return;
//     }
//     if(i <= mi) change(ls, l, mi, i, x);
//     else change(rs, mi + 1, r, i, x);
//     mx[p] = max(mx[ls], mx[rs]);
//     if(mx[ls] == mx[rs]) my[p] = max(my[ls], my[rs]);
//     else my[p] = min(mx[ls], mx[rs]);
// }
// int query(int p, int l, int r, int lx, int rx){
//     // cerr << p << " " << l << " " << r << '\n';
//     if(l == r) return r;
//     if(mx[rs]) return query(rs, mi + 1, r);
//     return query(ls, l, mi);
// }
void ChatGptDeepSeek()
{
    int n; cin >> n;
    vi a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vi cnt(n + 1);
    // vis(n + 1);
    // vis[0] = n;
    // change(1, 0, n, 0);
    // cerr << query(1, 0, n) << '\n';
    // return;
    // vi pre(n + 1);
    // set<int> st;
    // multiset<int> xt;
    map<int, int> xt;
    // xt.insert(0);
    xt[0] = 0;
    // int mx = 0, sec = 0;
    for(int i = 1; i <= n; i++){
        int x = a[i];
        // cmax(pre[i], pre[i - 1]);
        // set<int> tmp;
        for(int j = 1; j * j <= x; j++){
            if(x % j == 0){
                // vis[cnt[j]]--;
                // if(!vis[cnt[j]]) change(1, 0, n, cnt[j]);
                // if(j != 1){
                    if(cnt[j]){
                        // xt.erase(xt.find(-cnt[j]));
                        if(--xt[-cnt[j]] == 0)
                            xt.erase(-cnt[j]);
                    }
                    cnt[j]++;
                    xt[-cnt[j]]++;
                    // xt.insert(-cnt[j]);
                    // if(cnt[j] > mx){
                    //     sec = mx;
                    //     mx = cnt[j];
                        
                    // }else if(cnt[j] > sec && cnt[j] < mx){
                    //     sec = cnt[j];
                    // }
                    // if(cnt[j] == i) tmp.insert(j);
                // }
                // cerr << "mx & sec : " << mx << " " << sec << '\n'; 
                // change(1, 1, n, j, cnt[j]);
                // vis[cnt[j]]++;
                // if(vis[cnt[j]] == 1) change(1, 0, n, cnt[j]);
                if(j * j != x){
                    // vis[cnt[x / j]]--;
                    // if(!vis[cnt[x / j]]) change(1, 0, n, cnt[x / j]);
                    if(cnt[x / j]){
                        // xt.erase(xt.find(-cnt[x / j]));
                        if(--xt[-cnt[x / j]] == 0)
                            xt.erase(-cnt[x / j]);
                    }
                    cnt[x / j]++;
                    // xt.insert(-cnt[x / j]);
                    xt[-cnt[x / j]]++;
                    // if(cnt[x / j] == i)
                    //     tmp.insert(x / j);
                    // if(cnt[x / j] > mx){
                    //     sec = mx;
                    //     mx = cnt[x / j];
                        
                    // }else if(cnt[x / j] > sec && cnt[x / j] < mx){
                    //     sec = cnt[x / j];
                    // }
                    // cerr << "mx & sec : " << mx << " " << sec << '\n'; 
                    // change(1, 1, n, x / j, cnt[x / j]);
                    // vis[cnt[x / j]]++;
                    // if(vis[cnt[x / j]] == 1) change(1, 0, n, cnt[x / j]);
                }
            }
            
        }
        // if(sz(tmp) != sz(st)) pre[i] = i - 1, st = tmp;
        // if(mx != i) cmax(pre[i], mx);
        // if(sec != i) cmax(pre[i], sec);
        // cerr << "mx & sec : " << mx << " " << sec << '\n'; 
        // cerr << mx[1] << " \n";
        // cout << pre[i] << " \n" [i == n];
        cout << -xt.upper_bound(-i) -> fi << " \n" [i == n];
        // return;
    }
    // cnt是单个因子出现的次数，我们需要找出现次数最多的那个因子
    // 并且不能等于 i，我们只需要值
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