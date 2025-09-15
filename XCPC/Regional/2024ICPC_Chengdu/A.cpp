#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-15 10:23:52
void solve(){
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    if(s[1] != '>' || s[n] != '>' || s[n - 1] != '>' || s[n - 2] != '>'){
        cout << "No\n";
        return;
    }
    int r = -1;
    for(int i = n; i >= 1; i--){
        if(s[i] == '-'){
            r = i + 1;
            break;
        }
    }
    if(r == -1){cout << "No\n"; return;}
    vector<pair<int, int>> ans;
    for(int i = n; i >= r + 2; i--)
        ans.emplace_back(1, i);
    for(int i = 2; i < r; i++)
        if(s[i] == '>') ans.emplace_back(i, r + 2);
    cout << "Yes " << ans.size() << "\n";
    for(auto [x, y] : ans)
        cout << x << " " << y - x + 1 << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}