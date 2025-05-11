#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if(n == 2){
        cout << "-1\n";
        return;
    }
    if(n == 4){
        cout << "3 4 1 2\n";
        return;
    }
    if(n & 1){
        for(int i = n; i > n / 2 + 1; i--){
            cout << i << " ";
        }
        cout << 1 << ' ';
        for(int i = 2; i <= n / 2 + 1; i++)
            cout << i <<  " ";
        cout << '\n';
    }else{
        cout << n << " " << n / 2 << ' ';
        for(int i = 1; i < n / 2; i++)
            cout << i << " ";
        for(int i = n - 1; i > n / 2; i--)
            cout << i << " ";
        cout << "\n";
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