#include <bits/stdc++.h>
using namespace std;

int a[12], dp[10];
int dfs(int cur, bool is_six, bool limit)
{
    if(!cur) return 1;
    if(!is_six && !limit && dp[cur] != -1) return dp[cur];
    int ans = 0, up = limit ? a[cur] : 9;
    for(int i = 0; i <= up; i++){
        if(i == 4) continue;
        if(is_six && i == 2) continue;
        ans += dfs(cur - 1, i == 6, limit && i == a[cur]);
    }
    if(!limit && !is_six && dp[cur] == -1) dp[cur] = ans;
    return ans;
}
int get(int lmt)
{
    lmt = max(0, lmt);
    int len = 0;
    while(lmt){
        a[++len] = lmt % 10;
        lmt /= 10;
    }
    return dfs(len, 0, 1);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for(int i = 0; i < 10; i++) dp[i] = -1;
    int l, r;
    while(1){
        cin >> l >> r;
        if(!(l + r)) break;
        // cerr << l << " " << r << "\n";
        cout << get(r) - get(l - 1) << "\n";
        // cerr << "ok\n";
    }
}