#include<bits/stdc++.h>
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
    int n = rand_integer(10, 20);
    cout << n << '\n';
    for(int i = 1; i <= n; i++)
        cout << rand_integer(1, 500000) << " \n"[i == n];
    for(int i = 1; i <= n; i++)
        cout << rand_integer(1, 3) << " \n"[i == n];
    return 0;
}