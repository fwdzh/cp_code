#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> T(n + 1), lst(m + 1);
    set<int> st;
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> T[i];
        if(lst[T[i]]) st.erase(lst[T[i]]);
        st.insert(i), lst[T[i]] = i;
        if(st.size() == m){
            ans += *st.begin();
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}