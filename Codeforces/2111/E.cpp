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

// Date: 2025-06-03
// Time: 23:16:16
void ChatGptDeepSeek()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vi cnt(3), cnt1(3);
    // vc<vc<deque<int>>> que(3, vc<deque<int>>(3));
    vc<vc<set<int>>> que(3, vc<set<int>>(3));
    for(int i = 1; i <= q; i++) {
        char x, y;
        cin >> x >> y;
        que[x - 'a'][y - 'a'].insert(i);
    }
    vi stk;
    for(int i = 0; i < n; i++)
        if(s[i] == 'a') stk.push_back(i);
    for(int i = 0; i < n; i++){
        if(s[i] == 'a'){
            cout << s[i];
            continue;
        }
        int x = s[i] - 'a'; 
        if(que[x][0].size()){
            s[i] = 'a';
            que[x][0].erase(que[x][0].begin());
        }else{
            if(que[x][3 - x].size() && que[3 - x][0].size()){
                int small = *que[x][3 - x].begin();
                auto it = que[3 - x][0].upper_bound(small);
                if(it != que[3 - x][0].end()){
                    que[x][3 - x].erase(que[x][3 - x].begin());
                    que[3 - x][0].erase(it);
                    s[i] = 'a';
                    cout << s[i];
                    continue;
                }
            }
            if(3 - x < x){
                if(que[x][3 - x].size()){
                    que[x][3 - x].erase(prev(que[x][3 - x].end()));
                    s[i] = 'b';
                }
            }
        }
        cout << s[i];
    }
    cout << '\n';
}

int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
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