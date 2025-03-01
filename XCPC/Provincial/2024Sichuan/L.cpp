// Date: 2025-03-01
// Time: 13:59:42

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v1, v2;
    for (int i = 1; i <= n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (c == d) {
            if (a < b) {
                v1.push_back({ a, i });
            } else {
                v2.push_back({ b, i });
            }
        } else if (c)
            v1.push_back({ a, i });
        else
            v2.push_back({ b, i });
    }
    sort(v1.begin(),v1.end(),[](pair<int,int>x,pair<int,int>y){
        return x.first<y.first;
    });
    sort(v2.begin(),v2.end(),[](pair<int,int>x,pair<int,int>y){
        return x.first<y.first;
    });
    cout<<v1.size()<<' ';
    for(auto [_,i]:v1)
        cout<<i<<" ";
    cout<<'\n';
    cout<<v2.size()<<' ';
    for(auto [_,i]:v2)
        cout<<i<<" ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}