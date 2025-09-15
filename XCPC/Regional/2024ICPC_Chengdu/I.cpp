#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-15 08:50:12
constexpr int N = 200005;
int val[N << 2];
array<int, N> divs;
void change(int p, int l, int r, int i, int x){
    if(l == r){
        val[p] = x;
        // cerr << l << " " << r << " " << x << '\n';
        return;
    }
    int mid = (l + r) >> 1;
    if(i <= mid) change(p << 1, l, mid, i, x);
    else change(p << 1 | 1, mid + 1, r, i, x);
    val[p] = gcd(val[p << 1], val[p << 1 | 1]);
}
void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    set<int> st{0};
    for(int i = 1; i + 1 <= n; i++){
        if(a[i] > a[i + 1]){
            change(1, 1, n, i, i - *st.rbegin());
            st.insert(i);
        }
    }
    cout << (val[1] ? divs[val[1]] : n) << "\n";
    st.insert(n);
    while(q--){
        int p, v; cin >> p >> v;
        if(v > a[p]){
            if(p < n && v > a[p + 1]){
                if(!st.contains(p)){
                    auto it = st.upper_bound(p);
                    if(*it != n)
                        change(1, 1, n, *it, *it - p);
                    change(1, 1, n, p, p - *prev(it));
                    st.insert(p);
                }
            }
            if(p > 1 && v >= a[p - 1] && st.contains(p - 1)){
                st.erase(p - 1);
                change(1, 1, n, p - 1, 0);
                auto it = st.lower_bound(p);
                if(*it != n)
                    change(1, 1, n, *it, *it - *prev(it));
            }
        }else if(v < a[p]){
            if(p < n && v <= a[p + 1]){
                if(st.contains(p)){
                    change(1, 1, n, p, 0);
                    st.erase(p);
                    auto it = st.upper_bound(p);
                    if(*it != n)
                        change(1, 1, n, *it, *it - *prev(it));
                }
            }
            if(p > 1 && v < a[p - 1] && !st.contains(p - 1)){
                auto it = st.upper_bound(p - 1);
                change(1, 1, n, p - 1, p - 1 - *prev(it));
                if(*it != n)
                    change(1, 1, n, *it, *it - (p - 1));
                st.insert(p - 1);
            }
        }
        a[p] = v;
        cout << (val[1] ? divs[val[1]] : n) << "\n";
        // return;
    }
    for(auto x : st)
        change(1, 1, n, x, 0);
}
int main(){
    // freopen("1.in", "r", stdin);
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i)
            divs[j]++;
    }
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}