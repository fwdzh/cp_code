#include <bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int N = 200050;
int lazy[N << 2];
#define ls p << 1
#define rs p << 1 | 1
#define mi ((l + r) >> 1)
void build(int p, int l, int r)
{
    lazy[p] = 0;
    if(l == r) return;
    build(ls, l, mi);
    build(rs, mi + 1, r);
}
void push_down(int p)
{
    if(lazy[p]){
        lazy[ls] = max(lazy[ls], lazy[p]);
        lazy[rs] = max(lazy[rs], lazy[p]);
        lazy[p] = 0;
    }
}
void add(int p, int l, int r, int lx, int rx, int val)
{
    if(l >= lx && r <= rx){
        lazy[p] = max(lazy[p], val);
        return;
    }
    push_down(p);
    if(lx <= mi) add(ls, l, mi, lx, rx, val);
    if(rx > mi) add(rs, mi + 1, r, lx, rx, val);
}
int ask(int p, int l, int r, int i)
{
    if(l == r) return lazy[p];
    push_down(p);
    if(i <= mi) return ask(ls, l, mi, i);
    return ask(rs, mi + 1, r, i);
}
void solve()
{
    int n; cin >> n;
    vector<LL> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    build(1, 1, n);
    vector<LL> pre(n + 1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    for(int i = 3; i <= n; i++){
        int L = lower_bound(pre.begin(), pre.begin() + i, pre[i] - 2 * a[i]) - pre.begin();
        // cerr << L << "  \n";
        if(L == i) continue;
        // L = max(0, L - 1);
        int len = i - L + 1;
        // cerr << len << " " << i << "\n";
        add(1, 1, n, len, i, i);
    }
    vector<LL> ans(n + 1);
    for(int i = 3; i <= n; i++){
        int idx = ask(1, 1, n, i);
        if(!idx) continue;
        // cerr << "idx : " << idx << '\n';
        ans[i] = pre[idx] - pre[idx - i];
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " \n" [i == n];
}
int main()
{
#ifdef LOCAL
    // freopen("1.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}