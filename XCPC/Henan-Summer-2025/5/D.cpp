#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int N = 100010;
int n;
bool zero;
ll a[N];
void Gauss()
{
    int i, k = 1;
    ll j = (ll)1 << 62;
    for(;j;j>>=1){
        for(i=k;i<=n;i++){
            if(a[i]&j) break;
        }
        if(i > n) continue;
        swap(a[i], a[k]);
        for(i = 1; i <= n; i++){
            if((i!=k)&&(a[i]&j)) a[i]^=a[k];
        }
        k++;
    }
    k--;
    if(k!=n) zero = true;
    else zero = false;
    n = k;
}
ll Query(ll k){
    ll ans = 0;
    if(zero) k--;
    if(!k) return 0;
    for(int i=n;i;i--){
        if(k&1) ans^=a[i];
        k>>=1;
    }
    if(k) return -1;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    Gauss();
    // cerr << n << '\n';
    // 值有 2 ^ n - 1个，是 
    int k = 1 << n - 1;
    if(zero)
        cout << Query(k + 1) << '\n';
    else
        cout << Query(k) << '\n';
    return 0;
}