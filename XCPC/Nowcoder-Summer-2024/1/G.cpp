#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 0; i < q; i++){
        string t; int a;
        cin >> t >> a;
        a--;
        long long ans = 0;
        for(int j = 0, cnt = 0; j < t.size() && a + j < s.size(); j++){
            if(t[j] == s[j + a]){
                cnt++;
                ans += cnt;
            }else cnt = 0;
        }
        cout << ans << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int T; cin >> T; while(T--)
    {solve();} return 0;
}