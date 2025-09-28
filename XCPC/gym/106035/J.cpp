// Date: 2025-09-26 20:41:58
// Author: wuyi
// 
// Problem: J. Battleship
// Contest: Codeforces - ICPC Central Russia Regional Contest, 2024
// URL: https://codeforces.com/gym/106035/problem/J
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int n, k, c; cin >> n >> k >> c;
    vector<pair<int, int>> vec(c);
    for(int i = 0; i < c; i++) cin >> vec[i].first >> vec[i].second;
    for(int L = 1; L + k - 1 <= n; L++){
    	bool ok = true;
    	for(auto [t, r] : vec){
    		int hit = 0;
    		for(int i = t; i <= n; i += t){
    			if(i >= L && i < L + k) hit++;
    		}
    		if(hit != r){
    			ok = false;
    			break;
    		}
    	}
    	if(ok){
    		cout << L << '\n';
    		return;
    	}
    }
    cout << "-1\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}