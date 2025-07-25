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

// Date: 2025-06-07
// Time: 20:43:39
void ChatGptDeepSeek()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i + 1 < sz(s); i++){
        if(s[i] > s[i + 1]){
            char x = s[i];
            s.erase(s.begin() + i);
            for(int j = i + 1; j < sz(s); j++){
                if(s[j] > x){
                    s.insert(s.begin() + j, x);
                    break;
                }
            }
            if(sz(s) < n) s.push_back(x);
            break;
        }
    }
    cout << s << '\n';
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