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

constexpr int N = int(1e5)+5;
int siz[N],dep[N],fa[N],son[N],dfn[N],top[N];

#define ls p<<1
#define rs p<<1|1
#define mi ((l+r)>>1)
int tr[N<<2];

void change(int p,int l,int r,int i,int x){
    if(l==r){
        tr[p]=x;
        return;
    }
    if(i<=mi) change(ls,l,mi,i,x);
    else change(rs,mi+1,r,i,x);
    tr[p]=max(tr[ls],tr[rs]);
}
int query(int p,int l,int r,int lx,int rx)
{
    if(lx>rx) return 0;
    if(l>=lx&&r<=rx) return tr[p];
    int res=0;
    if(lx<=mi) cmax(res,query(ls,l,mi,lx,rx));
    if(rx>mi) cmax(res,query(rs,mi+1,r,lx,rx));
    return res;
}
void ChatGptDeepSeek() // Date: 2025-04-20
{                      // Time: 10:50:44 
    int n;
    cin>>n;
    vector<array<int,3>>edge(n);
    vector<vector<pii>>g(n+1,vector<pii>());
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[i]={u,v,w};
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    auto dfs1=[&](auto &&self,int u,int pre)->void{
        siz[u]=1,dep[u]=dep[pre]+1,fa[u]=pre;
        for(auto [v,w]:g[u]){
            if(v==pre) continue;
            self(self,v,u);
            siz[u]+=siz[v];
            if(son[u]==0||siz[v]>siz[son[u]])
                son[u]=v;
        }
    };
    dfs1(dfs1,1,0);
    int cntd=0;
    auto dfs2=[&](auto &&self,int u,int pre)->void{
        dfn[u]=++cntd;
        if(son[pre]==u) top[u]=top[pre];
        else top[u]=u;
        if(son[u]) self(self,son[u],u);
        for(auto [v,w]:g[u]){
            if(v==pre||v==son[u]) continue;
            self(self,v,u);
        }
    };
    dfs2(dfs2,1,0);
    for(int i=1;i<n;i++){
        auto &[u,v,w]=edge[i];
        if(dep[u]>dep[v]) swap(u,v);
        change(1,1,n,dfn[v],w);
    }
    string op;
    while(cin>>op&&op!="DONE"){
        if(op=="CHANGE"){
            int i,t;
            cin>>i>>t;
            auto [u,v,w]=edge[i];
            change(1,1,n,dfn[v],t);
        }else{
            int x,y;
            cin>>x>>y;
            int res=0;
            while(top[x]!=top[y]){
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                cmax(res,query(1,1,n,dfn[top[x]],dfn[x]));
                x=fa[top[x]];
            }
            if(dep[x]>dep[y]) swap(x,y);
            cmax(res,query(1,1,n,dfn[x]+1,dfn[y]));
            cout<<res<<'\n';
        }
    }
}

int main()
{
#ifndef YUANSHEN
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}