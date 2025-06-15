#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = int(1e5) + 10;
constexpr int mod = int(1e9) + 7;

int zeros[N], ones[N], ans[N];

void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // 0 1
    zeros[1] = 1, ones[2] = 1;
    for(int i = 3; i < N; i++){
        zeros[i] = (zeros[i - 1] + zeros[i - 2]) % mod;
        ones[i] = (ones[i - 1] + ones[i - 2]) % mod;
        ans[i] = (ans[i - 1] + ans[i - 2]) % mod;
        ans[i] = (ans[i] + 1LL * ones[i - 2] * zeros[i - 1] % mod) % mod;
    }
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}