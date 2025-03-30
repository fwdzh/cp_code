#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937_64 rng(time(NULL));
ll rand_integer(ll l, ll r)
{
    uniform_int_distribution<ll> dis(l, r);
    return dis(rng);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << "1\n";
    int n = rand_integer(10, 100);
    int k = rand_integer(1, 1000);
    cout << n << " " << k << '\n';
    for (int i = 1; i <= n; i++)
        cout << rand_integer(1, 100000) << " \n"[i == n];
    return 0;
}