// Date: 2025-09-26 20:16:07
// Author: wuyi
// 
// Problem: H. University ranking
// Contest: Codeforces - ICPC Central Russia Regional Contest, 2024
// URL: https://codeforces.com/gym/106035/problem/H
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
struct node{
	int problems, place;
};
int bonus[11]{0, 80, 68, 62, 57, 53, 50, 48, 46, 44, 42};
int solve(){
    int n; cin >> n;
    vector<node> vec(n);
    for(int i = 0; i < n; i++){
    	string s; cin >> s;
    	cin >> vec[i].problems >> vec[i].place;
    }
    sort(vec.begin(), vec.end(), [](const node &x, const node &y){
    	return x.problems == y.problems ? x.place < y.place : x.problems > y.problems;
    });
    auto get = [&](int p){
    	if(p > 50) return 0;
    	return p <= 10 ? bonus[p] : (50 - p + 1);
    };
    int r = 0;
    r = 10 * vec[0].problems + 2 * get(vec[0].place);
    for(int i = 1; i < min(int(vec.size()), 3); i++)
    	r += get(vec[i].place);
    // cerr << r << '\n';
    return r;
}
void solvv(){
	cout << 4 * solve() + 3 * solve() + 2 * solve() << '\n';
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solvv();} return 0;
}