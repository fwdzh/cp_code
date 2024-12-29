#include <bits/stdc++.h>
using namespace std;

inline void __print(int x) { cerr << x; }
inline void __print(long x) { cerr << x; }
inline void __print(long long x) { cerr << x; }
inline void __print(unsigned x) { cerr << x; }
inline void __print(unsigned long x) { cerr << x; }
inline void __print(unsigned long long x) { cerr << x; }
inline void __print(float x) { cerr << x; }
inline void __print(double x) { cerr << x; }
inline void __print(long double x) { cerr << x; }
inline void __print(char x) { cerr << '\'' << x << '\''; }
inline void __print(const char* x) { cerr << '\"' << x << '\"'; }
inline void __print(const string& x) { cerr << '\"' << x << '\"'; }
inline void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
inline void __print(const pair<T, V>& x) { cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}'; }

template <typename T>
inline void __print(const T& x) { int f = 0; cerr << '{'; for (auto& i : x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}"; }

inline void _print() { cerr << "]\n"; }

template <typename T, typename... V>
inline void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }

#define dbg(x...) cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;