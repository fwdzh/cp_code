#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((j & 1) == (i & 1)) cout << i << " ";
            else cout << j << " ";
        }
        cout << '\n';
    }
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