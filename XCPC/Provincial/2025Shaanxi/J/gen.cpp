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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int k = rand_integer(1, 100);
    cout << k << '\n';
    int len = rand_integer(1, 200);
    string charset = "lose";
    for(int i = 0; i < len; i++)
        putchar(charset[rand_integer(0, charset.size() - 1)]);
    return 0;
}