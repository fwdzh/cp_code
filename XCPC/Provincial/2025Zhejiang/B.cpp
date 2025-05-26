#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> vis(n + 1);
    // vector<int> cnt(n + 1);
    while(m--){
        int d;
        cin >> d;
        int cnt = 0;
        if(!vis[d]){
            for(int i = d; i <= n; i += d){
                if(!vis[i]){
                    vis[i] = true;
                    cnt++;
                }
            }
        }
        if(cnt) cout << cnt << "\n";
        else cout << "the lights are already on!\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}