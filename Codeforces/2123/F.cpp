// 你醒来，发现自己回到了大一……
// 这一次，你下定决心：要成为 Candidate Master。
#include<bits/stdc++.h>
using namespace std;
// created: 2025-07-05 18:42:45
using ll = long long;
void solve(){
    int n;
    cin >> n;
    vector<int> ans(n + 1);
    iota(ans.begin() + 1, ans.end(), 1);
    
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " \n" [i == n];
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    solve(); return 0;
}