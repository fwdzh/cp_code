#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    string s;
    cin >> s;
    assert(s[0] >= '0' && s[0] <= '9');
    assert(s[2] >= '0' && s[2] <= '9');
    assert(s[1] == '+' || s[1] == '-' || s[1] == '*');
    assert(s[3] == '=');
    /*
    5-3=3-5

    5-=3=-5
    =5-3-5=
      0=5-5=0
    */
    int x = s[0] - '0', y = s[2] - '0';
    if(s[0] == s[2]){
        cout << "No\n";
    }else if(s[1] == '-'){
        if(x == 0) cout << "Yes\n";
        else cout << "No\n";
    }else if(s[1] == '+'){
        if(x + y == y + x) cout << "Yes\n";
        else cout << "No\n";
    }else if(s[1] == '*'){
        if(x * y == y * x) cout << "Yes\n";
        else cout << "No\n";
    }else
        cout << "No\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    {solve();} return 0;
}