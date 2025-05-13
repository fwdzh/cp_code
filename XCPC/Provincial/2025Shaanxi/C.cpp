/*
gcd(a, b) = g
gcd(a / g, b / g) = 1

16 18

32 48
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll a, b;
    cin >> a >> b;
    if(b == 1)
        cout << "-1\n";
    else if(a == 1)
        cout << b << '\n'; 
    else{
        ll c = b;
        for(;c != 1;){
            ll g = gcd(a, c);
            if(g == 1) break;
            c /= g;
        }
        if(c == 1) c = -1;
        cout << c << '\n';
    }
    
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