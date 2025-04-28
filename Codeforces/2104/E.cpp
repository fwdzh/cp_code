#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    
    vector<char> s(n + 1);
    vector<vector<int>> pre(n + 1, vector<int> (k));
    vector<vector<int>> idx(n + 1, vector<int> (k, n + 1));
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1];
        cin >> s[i];
        pre[i][s[i] - 'a']++;
    }
    for(int i = n; i >= 1; i--){
        if(i < n) idx[i] = idx[i + 1];
        idx[i][s[i] - 'a'] = i;
    }
    
    vector<int> ans(n + 2, n + 1);
    ans[n + 1] = 0;
    for(int i = n; i >= 1; i--){
        for(int j = 0; j < k; j++)
            ans[i] = min(ans[i], pre[n][j] - pre[i - 1][j]);
        // cerr << ans[i] << " \n"[i==1];
    }
    int q; cin >> q;
    while (q--)
    {
        string t;
        cin >> t;
        if(t.size() > n){
            cout << "0\n";
            continue;
        }
        int j = 1;
        bool ok = false;
        for(int i = 0; i < t.size(); i++){
            if(j > n){
                ok = true;
                break;
            }
            // cerr << j << '\n';
            j = idx[j][t[i] - 'a'] + 1;
            if(j > n + 1){
                ok = true;
                break;
            }
        }
        
        if(ok) cout << "0\n";
        else cout << ans[j] + 1 <<'\n';
    }
    
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr),cout.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while(t--)
        solve();
    return 0;
}