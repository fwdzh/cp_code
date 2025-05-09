#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s[0] != s[n - 1]){
        cout << "empty\n";
        return;
    }
    if(n == 1){
        cout << s << '\n';
        return;
    }

    if(s[0] == '0'){
        // 010010010
        int ans = n, cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                ans = min(ans, cnt);

                cnt = 0;
            }else cnt++;
        }
        ans = min(ans, cnt);
        if(ans == 0){
            cout << "empty\n";
            return;
        }
        cout << string(ans, '0') << '\n';
    }else{
        // 111101110111
        int ans = n, cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                ans = min(ans, cnt);

                cnt = 0;
            }else cnt++;
        }
        ans = min(ans, cnt);
        if(ans == 0){
            cout << "empty\n";
            return;
        }
        cout << string(ans, '1') << '\n';
    }//0010001110100
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