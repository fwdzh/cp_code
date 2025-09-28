// Date: 2025-09-26 17:18:04
// Author: wuyi
// 
// Problem: L. Pills
// Contest: Codeforces - ICPC Central Russia Regional Contest, 2024
// URL: https://codeforces.com/gym/106035/problem/L
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    LL n; cin >> n;
    cout << n << endl;
    LL sum = 0;
    for(int i = 1; i <= n; i++){
    	cout << i << " " << i << endl;
    	sum += 500 * i;
    }
    LL weight;
    cin >> weight;
    cout << "! " << weight - sum << endl;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}