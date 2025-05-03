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

string charset1 = "qwertyuiopasdfghjklzxcvbnm";
string charset2 = "QWERTYUIOPASDFGHJKLZXCVBNM";
string charset3 = "1234567890";

mt19937_64 rng(time(NULL));

ll rand_integer(ll l, ll r)
{
    uniform_int_distribution<ll>dis(l, r);
    return dis(rng);
}

vl rand_array(int n, ll l, ll r)
{
    vl a(n);
    for(int i = 0; i < n; i++){
        a[i] = rand_integer(l, r);
    }
    return a;
}

string rand_string(int n, string s = charset1)
{
    string res(n, '.');
    for(int i = 0; i < n; i++)
        res[i] = s[rand_integer(0, sz(s) - 1)];
    return  res;
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#endif
    
    return 0;
}