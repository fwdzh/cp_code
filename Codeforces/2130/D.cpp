#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    reverse(b.begin() + 1, b.end());
    if(is_sorted(b.begin() + 1, b.end())){
        cout << "0\n";
        return;
    }
    int cnt = 0, res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            cnt++;
            if(a[i] > a[j]){
                res++;
            }
        }
    }
    int ans = res;
    for(int i = 1; i <= n; i++){
        int nres = res;
        for(int j = 1; j <= n; j++){
            if(j == i) continue;
            if(j < i && a[j] > a[i]) nres--;
            if(j < i && a[j] < a[i]) nres++;
            if(j > i && a[j] > a[i]) nres++;
            if(j > i && a[j] < a[i]) nres--;
        }
        ans = min(res, nres);
    }
    cout << ans << '\n';
}
int main()
{
    // freopen("1.in", "r", stdin), freopen("1.out", "w", stdout), freopen("1.err", "w", stderr);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}