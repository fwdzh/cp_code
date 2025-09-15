#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-12 17:53:21
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    set<int> ans(a.begin() + 1, a.end());
    for(int i = 1; i + 1 <= n; i++){
        set<int> st;
        st.insert(a[i]);
        st.insert(a[i + 1]);
        st.insert(a[i] ^ a[i + 1]);
        st.insert(a[i] & a[i + 1]);
        st.insert(a[i] | a[i + 1]);
        while(1){
            set<int> q;
            int sz = st.size();
            for(auto x : st){
                for(auto y : st){
                    q.insert(x ^ y);
                    q.insert(x | y);
                    q.insert(x & y);
                }
            }
            for(auto x : q)
                st.insert(x);
            // cerr << st.size() << '\n';
            if(st.size() == sz) break;
        }
        for(auto x : st) ans.insert(x);
    }
    cout << ans.size() << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}