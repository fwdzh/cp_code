#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> c[i];

    bool ok = true;

    while(m--){
        int u, v;
        cin >> u >> v;
        if((u != v) && (c[u] == c[v])) ok = false;
    }
    if(k == 1){
        cout << "YES\n";
        return;
    }
    if(ok) cout << "YES\n";
    else{
        cout << "NO\n";
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