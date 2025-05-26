#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    a.push_back('.');
    b.push_back('.');
    for(int i = 0, A =0, B = 0; i < min(a.size(), b.size()); i++){
        if(a[i] == '.' && b[i] == '.'){
            if(A == B) continue;
            else if(A > B) cout << "A\n";
            else cout << "B\n";
            return;
        }
        if(a[i] == '.'){
            cout << "B\n";
            return;
        }
        if(b[i] == '.'){
            cout << "A\n";
            return;
        }
        A = A * 10 + a[i] - '0';
        B = B * 10 + b[i] - '0';
    }
    cout << "Equal\n";
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