#include<bits/stdc++.h>
using namespace std;

#define ls p << 1
#define rs p << 1 | 1
#define mi ((l + r) >> 1)

constexpr int N = int(1e6) + 10;
int a[N], n, ST[N][25];
void init()
{
    int p = log2(n);
    for(int i = 1; i <= n; i++)
        ST[i][0] = a[i];
    for(int k = 1; k <= p; k++){
        for(int s = 1; s + (1 << k) <= n + 1; s++){
            ST[s][k] = max(ST[s][k - 1], ST[s + (1 << (k - 1))][k - 1]);
        }
    } 
}
int query(int L, int R)
{
    int k = __lg(R - L + 1);
    return max(ST[L][k], ST[R - (1 << k) + 1][k]);
}
// tr[N << 2];
// void build(int p, int l, int r)
// {
//     if(l == r){
//         tr[p] = a[l];
//         return;
//     }
//     build(ls, l, mi);
//     build(rs, mi + 1, r);
//     tr[p] = max(tr[ls], tr[rs]);
// }
// int query(int p, int l, int r, int lx, int rx)
// {
//     if(l >= lx && r <= rx)
//         return tr[p];
//     int res = 0;
//     if(lx <= mi) res = max(res, query(ls, l, mi, lx, rx));
//     if(rx > mi) res = max(res, query(rs, mi + 1, r, lx, rx));
//     return res;
// }


void solve()
{
    // int n;
    cin >> n;
    vector<int> idx(n + 1);
    for(int i = 1; i <= n; i++)
        a[i] = i;
    // shuffle(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        idx[a[i]] = i;
    }
    // build(1, 1, n);
    init();
    if(n == 1){
        cout << "0\n";
        return;
    }
    int lo = 0, hi = n + 1;
    auto check = [&](int d){
        vector<bool> ok(n + 1);
        for(int i = idx[n]; i >= idx[n] - d && i >= 1; i--)
            ok[a[i]] = true;
        for(int i = idx[n]; i <= idx[n] + d && i <= n; i++)
            ok[a[i]] = true;
        for(int i = idx[n] - d - 1; i >= 1; i--){
            // int num = query(1, 1, n, max(i - d, 1), min(n, i + d));
            int num = query(max(i - d, 1), min(n, i + d));
            if(!ok[num]) return false;
            ok[a[i]] = true;
        }
        for(int i = idx[n] + d + 1; i <= n; i++){
            // int num = query(1, 1, n, max(i - d, 1), min(n, i + d));
            int num = query(max(i - d, 1), min(n, i + d));
            if(!ok[num]) return false;
            ok[a[i]] = true;
        }
        return true;
    };
    // check(1);
    while(lo < hi - 1){
        int mid = (lo + hi) >> 1;
        if(check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
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