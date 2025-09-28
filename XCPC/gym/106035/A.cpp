// Date: 2025-09-26 16:32:36
// Author: wuyi
// 
// Problem: A. Pyramidal paths
// Contest: Codeforces - ICPC Central Russia Regional Contest, 2024
// URL: https://codeforces.com/gym/106035/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    // 先递减后递增，或者先递增后递减
    vector<bool> pre(n + 1), suf(n + 1);
    bool ok = true;
    for(int i = 2; i <= n; i++){
    	if(a[i] > a[i - 1]) ok = false;
    	pre[i] = ok;
    }
    ok = true;
    for(int i = n - 1; i >= 1; i--){
    	if(a[i] > a[i + 1]) ok = false;
    	suf[i] = ok;
    }
    for(int i = 1; i <= n; i++){
    	if(pre[i] && suf[i]){
    		cout << "YES\n";
    		return;
    	}
    }
    pre = suf = vector<bool> (n + 1);
    ok = true;
    for(int i = 2; i <= n; i++){
    	if(a[i] < a[i - 1]) ok = false;
    	pre[i] = ok;
    }
    ok = true;
    for(int i = n - 1; i >= 1; i--){
    	if(a[i] < a[i + 1]) ok = false;
    	suf[i] = ok;
    }
    for(int i = 1; i <= n; i++){
    	if(pre[i] && suf[i]){
    		cout << "YES\n";
    		return;
    	}
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}