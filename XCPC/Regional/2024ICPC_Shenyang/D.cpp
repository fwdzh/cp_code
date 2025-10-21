#include <bits/stdc++.h>
using namespace std;

constexpr int N = 500050;
int bit[N];
int lowbit(int x) {return (x) & (-x);}
void add(int i, int x)
{
    while(i < N){
        bit[i] += x;
        i += lowbit(i);
    }
}
int query(int i)
{
    int res = 0;
    while(i){
        res += bit[i];
        i -= lowbit(i);
    }
    return res;
}
void solve()
{
    int n; cin >> n;
    vector<pair<int, int>> vec(n + 1);
    for(int i = 1; i <= n; i++) cin >> vec[i].first;
    for(int i = 1; i <= n; i++) cin >> vec[i].second;
    sort(vec.begin() + 1, vec.end());
    int ans = 0;
    for(int i = n; i >= 1; i--){
        ans = (ans + query(vec[i].second)) % 2;
        add(vec[i].second, 1);
    }
    cout << (ans ? 'A' : 'B');
    for(int i = 1; i < n; i++){
        char op;
        int l, r, d;
        cin >> op >> l >> r >> d;
        if((r - l) % 2 && d % 2)
            ans ^= 1;
        cout << (ans ? 'A' : 'B');
        add(vec[i].second, -1);
    }
    add(vec[n].second, -1);
    cout << "\n";
}
int main()
{
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}