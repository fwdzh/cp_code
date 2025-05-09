#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<bool>vis(n + 1);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        vis[x] = true;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cout << i << '\n';
            return;
        }
    }
    cout << "-1\n";
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