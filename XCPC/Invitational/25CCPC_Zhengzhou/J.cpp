#include<bits/stdc++.h>
using namespace std;

int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < 26; i++){
        int res = 0;
        for(auto x : s){
            res += holes_cnt[((x - 'A') + i) % 26];
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    solve(); return 0;
}