// #define YUANSHEN
#if defined(YUANSHEN)
#include "/home/skadi/cp_code/template/debug.hpp"
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

void ChatGptDeepSeek() // Date: 2025-04-18
{                      // Time: 20:36:52 
    int n;
    cin>>n;
    vector<vector<array<int,3>>>g(n+1,vector<array<int,3>>());
    map<pii,int>mp;
    for(int i=1;i<n;i++){
        int u,v,p,q;
        cin>>u>>v>>p>>q;
        g[u].push_back({v,p,q});
        g[v].push_back({u,q,p});
        mp[{u,v}]=p;
        mp[{v,u}]=q;
    }
    vl dis(n+1),sid(n+1);
    int s,t; cin>>s>>t;
    vl dp(n+1);
    vi fa(n+1);
    auto dfs=[&](auto &&self,int u,int pre)->void{
        for(auto [v,w1,w2]:g[u]){
            if(v==pre) continue;
            dis[v]=dis[u]+w1;
            sid[v]=sid[u]+w2;
            fa[v]=u;
            self(self,v,u);
            cmax(dp[u],dp[u]+dp[v]+w1+w2);
        }
    };
    dfs(dfs,s,0);
    cerr<<dp[s]<<'\n';
    cerr<<dis[t]<<" "<<sid[t]<<" "<<dp[t]<<'\n';
    dp[s]+=dis[t];
    int x=t;
    while(fa[x]!=s){
        if(dp[x]>0) dp[fa[x]]-=dp[x];
        cerr<<x<<" "<<dp[x]<<'\n';
        if(dp[x]>0)
        dp[s]-=dp[x];
        x=fa[x];
    }
    // if(dp[x]+sid[x]+dis[x]>0) dp[s]-=dp[x]+sid[x]+dis[x];
    cout<<dp[s]<<'\n';
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
        ChatGptDeepSeek();
    return 0;
}