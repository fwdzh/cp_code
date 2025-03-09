// Date: 2025-03-09
// Time: 15:53:06

#include <bits/stdc++.h>
#include <random>
using namespace std;
using ll = long long;
mt19937_64 rng(time(NULL));

ll rnd(ll l, ll r)
{
    uniform_int_distribution<ll> dis(l, r);
    return dis(rng);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // int n=rnd(1,100);
    // cout<<n<<'\n';
    // for(int i=1;i<=n;i++){
    //     cout<<rnd(1,2*n)<<" \n"[i==n];
    // }
    // cout<<rnd(1,1e18)<<'\n';
    int t = rnd(1, 10);
    cout << t << '\n';
    while (t--)
        cout << rnd(1e5, 1e18) << '\n';
    // cerr<<(1LL<<30)+1<<'\n';

    return 0;
}