#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int ask(ull x)
{
    cout << "? " << x << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve()
{
    ull ans = 0;
    vector<int> cnt(64);
    for(int i = 63; i >= 1; i--){
        cnt[i] = ask(1ull << i);
    }
    int mx = *max_element(cnt.begin() + 1, cnt.end());
    int mn = *min_element(cnt.begin() + 1, cnt.end());
    
    if(mx == mn){
        if(mx == 1) ans = 0;
        else if(mx == 2) ans = 1; 
        else ans = ULLONG_MAX; //... 糖丸了 幸好拿py写了一遍
    }else{
        int tnc = 0;
        for(int i = 63; i >= 1; i--){
            if(cnt[i] == mn){
                tnc++;
                ans |= 1ull << i;
            }
        }
        if(tnc != mn + 1) ans |= 1, tnc++;
        assert(tnc == mx - 1);
    }
    cout << "! " << ans << endl;
    cout.flush();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}