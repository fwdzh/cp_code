#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1), p(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        p[b[i]] = i;
    }
    for(int i = 1; i <= n; i++) cin >> c[i];
    vector<pii> info;
    for(int i = 1; i <= n; i++)
        if(c[i]) info.push_back({i, p[a[i]]});
    int R = 0;
    for(auto [l, r] : info){
        if(r < R){
            cout << "No\n";
            return;
        }
        R = max(R, r);
    }
    cout << "Yes\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    
    while(T--)
        solve();
    return 0;
}