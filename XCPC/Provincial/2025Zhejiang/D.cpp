#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    for(int i = 0; i <= n; i++)
        cin >> a[i];
    string ans;
    while(a[0] != 1){
        a[0]--;
        a[1]--;
        ans += "RL";
    }
    for(int i = 1; i < n; i++){
        ans += "R";
        if(a[i] < 2){
            cout << "Impossible\n";
            return;
        }
        while(a[i] != 2){
            a[i]--;
            a[i + 1]--;
            ans += "RL";
        }
    }
    ans += "R";
    if(a[n] != 1){
        cout << "Impossible\n";
        return;
    }
    ans += string(n, 'L');
    cout << ans << '\n';
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