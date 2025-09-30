// Date: 2025-09-27 20:32:06
// 
// Problem: E - Count Sequences 2
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Autumn (AtCoder Beginner Contest 425)
// URL: https://atcoder.jp/contests/abc425/tasks/abc425_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int mod, fact[5005], inv[5005];
int ksm(LL a, LL b){
	LL res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
int euler(int n){
	int ans = n;
	for(int p = 2; p * p <= n; ++p){
		if(n % p == 0){
			ans = ans / p * (p - 1);
			while(n % p == 0) n /= p;
		}
	}
	if(n != 1) ans = ans / n * (n - 1);
	return ans;
}
int e;
void solve(){
    int n; cin >> n;
    vector<int> c(n + 1);
    int sum = 0, p = 1;
    for(int i = 1; i <= n; i++){
    	cin >> c[i];
    	sum += c[i];
    	p = 1LL * fact[c[i]] * p % mod;
    }
    LL ans = fact[sum];
    ans = ans * ksm(p, e) % mod;
    cout << ans << '\n';
}
/*
1 1 2 3
1 2 3 1

*/
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t >> mod;
    fact[0] = 1;
    for(int i = 1; i <= 5000; i++)
    	fact[i] = 1LL * fact[i - 1] * i % mod;
    cerr << fact[5000] << '\n';
    // inv[5000] = ksm(fact[5000], euler(mod) - 1);
    // cerr << inv[5000] << '\n';
    e = euler(mod) - 1;
    for(int i = 0; i <= 5000; i++)
    	inv[i] = ksm(fact[i], e);
    while(t--)
    {solve();} return 0;
}
