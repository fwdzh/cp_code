/*
gcd(a, b) = g
gcd(a / g, b / g) = 1

16 18

32 48
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> c(n + 1), w(n + 1);
    vector<vector<int>> g(n + 1, vector<int>());
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        g[c[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++){
        // i = 2;
        g[i].push_back(n + 1);
        int res = 0, lst = -1, idx = 0;
        for(int j = 0; j < g[i].size(); j++){
            if(idx != g[i][j] - 1){
                if(lst == -1){
                    res += w[i] + (g[i][j] - idx - 1);
                }else{
                    res += min(w[i] + g[i][j] - idx - 1, g[i][j] - lst - 1);
                }
                lst = g[i][j] - 1;
            }
            idx = g[i][j];
            // cerr << idx <<" " << lst << " " << res << '\n';
        }
        cout << res << " \n" [i == n];
        // break;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}