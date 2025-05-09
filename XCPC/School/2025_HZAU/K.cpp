#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    for(int i = 0; i + 1 < s.size(); i++){
        if(s[i] < s[i + 1]){
            swap(s[i], s[i + 1]);
            break;
        }
    }
    cout << s << '\n';
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