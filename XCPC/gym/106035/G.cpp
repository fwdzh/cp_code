// Date: 2025-09-26 18:06:03
// Author: wuyi
// 
// Problem: G. Tree problem
// Contest: Codeforces - ICPC Central Russia Regional Contest, 2024
// URL: https://codeforces.com/gym/106035/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 200005;
int c[N], tmp[N], root[N], rt, ans[N], deg[N];
vector<vector<int>> g;
struct node{
	int l, r, cnt, ans;
	node(){l = r = cnt = ans = 0;}
};
#define lson seg[p].l
#define rson seg[p].r
#define mi ((l + r) >> 1)
node seg[N * 50];

void push_up(int p){
	if(seg[lson].cnt >= seg[rson].cnt)
		seg[p].ans = seg[lson].ans;
	else
		seg[p].ans = seg[rson].ans;
	seg[p].cnt = max(seg[lson].cnt, seg[rson].cnt);
}
int merge(int a, int b, int l, int r){
	if(!a || !b) return a | b;
	if(l == r){
		seg[a].cnt += seg[b].cnt;
		if(seg[a].cnt)
			seg[a].ans = l;
		return a;
	}
	seg[a].l = merge(seg[a].l, seg[b].l, l, mi);
	seg[a].r = merge(seg[a].r, seg[b].r, mi + 1, r);
	push_up(a);
	return a;
}

void update(int &p, int l, int r, int pos, int x){
	if(!p) p = ++rt;
	if(l == r){
		seg[p].cnt += x;
		seg[p].ans = l;
		return;
	}
	if(pos <= mi) update(lson, l, mi, pos, x);
	else update(rson, mi + 1, r, pos, x);
	push_up(p);
}
void dfs(int u){

	// cerr << u << " " << seg[root[u]].ans << "\n";
	for(auto v : g[u]){
		dfs(v);
		root[u] = merge(root[u], root[v], 1, 200000);
	}
	// cerr << u << " " << seg[root[u]].ans << "\n";
	// update(root[u], 1, 200000, c[u], 1);
	ans[u] = seg[root[u]].ans;
}
void solve(){
    int n; cin >> n;
    g.assign(n + 1, {});
    
    for(int i = 1; i <= n; i++){
    	cin >> c[i];
    	tmp[i] = c[i];
    }
    // rt = n;
    sort(tmp + 1, tmp + n + 1);
    for(int i = 1; i <= n; i++){
    	c[i] = lower_bound(tmp + 1, tmp + n + 1, c[i]) - tmp;
    	update(root[i], 1, 200000, c[i], 1);
	}
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	deg[v] = 1;
    	g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
    	if(!deg[i]){
    		dfs(i);
    		break;
    	}
    }
    for(int i = 1; i <= n; i++)
    	cout << tmp[ans[i]] << " \n" [i == n];
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}