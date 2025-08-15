#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL op, id, x;
void solve()
{
    int n, q; cin >> n >> q;
    vector<LL> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    LL mn = *min_element(a.begin() + 1, a.end());
    LL lmt = *max_element(a.begin() + 1, a.end());
    LL add = 0;
    while(q--){
        cin >> op;
        if(op == 1){
            cin >> id >> x;
            a[id] = min(a[id], lmt + add) - x;
            mn = min(a[id] - add, mn);
        }else if(op == 2){
            cin >> id;
            cout << min(a[id] - add, lmt) << '\n';
        }else if(op == 3){
            cin >> x;
            lmt -= x;
            mn -= x;
            add += x;
        }else if(op == 4){
            cin >> x;
            lmt = min(lmt, x);
            mn = min(mn, x);
        }else{
            cout << mn << "\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while(T--)
    {solve();} return 0;
}