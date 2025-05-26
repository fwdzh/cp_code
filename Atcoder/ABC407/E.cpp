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

// Date: 2025-05-24
// Time: 20:50:14
constexpr int N = int(4e5) + 10;
int b[N + 10];
int lowbit(int x) {return (x) & (-x);}
void add(int i, int x)
{
    while(i <= N){
        b[i] += x;
        i += lowbit(i);
    }
}
int query(int i)
{
    int res = 0;
    while(i){
        res += b[i];
        i -= lowbit(i);
    }
    return res;
}

void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    vi a(2 * n + 1);
    for(int i = 1; i <= 2 * n; i++)
        cin >> a[i];
    /*
    选取 n 个数，使得和最大
    对于[1, i] 选的数字必须大于等于没选的数字

    选的数字必须 >=  (i + 1) / 2
    [1, 1] [1, 2] [2, 3] [2, 3] [3, 3] [3, 3]
    400    500    200    100    300    600
    dp1 = 400
    dp2 = 900
    dp3 = 1100
    dp3 = 1100
    dp3 = 1200
    
    5
    []
    */
    priority_queue<pii, vc<pii>, greater<>> pq;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += a[i];
        pq.push({a[i], i});
        add(i, 1);
    }
    for(int i = n + 1; i <= 2 * n; i++){
        while(!pq.empty() && pq.top().fi < a[i]){
            auto [val, j] = pq.top();
            pq.pop();
            if(query(j) == (j + 1) / 2)
                continue;
            ans -= a[j];
            ans += a[i];
            // cerr << "del: " << a[j] << " add: " << a[i] << '\n'; 
            add(j, -1);
            add(i, 1);
            pq.push({a[i], i});
        }
    }
    cout << ans << '\n';
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    // int n;
    // cin >> n;
    // for(int i = 1; i <= 2 * n; i++){
    //     cout << (i + 1) / 2 << " " << min(i, n) << '\n';
    // }
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}