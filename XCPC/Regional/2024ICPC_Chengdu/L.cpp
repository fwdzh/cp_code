// Date: 2025-09-12 16:37:39
// Author: wuyi
// 
// Problem: L. Recover Statistics
// Contest: Codeforces - 2024 ICPC Asia Chengdu Regional Contest (The 3rd Universal Cup. Stage 15: Chengdu)
// URL: https://codeforces.com/gym/105486/problem/L
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
void solve(){
    int a, b, c; cin >> a >> b >> c;
    cout << "100\n";
    for(int i = 1; i <= 50; i++) cout << a << " ";
    for(int i = 1; i <= 45; i++) cout << b << " ";
    for(int i = 1; i <= 4; i++) cout << c << " ";
    cout << c + 1 << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}