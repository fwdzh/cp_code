#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int power[]{1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144};

void solve()
{
    ll l, r;
    cin >> l >> r;
    auto get = [](string s){
        int len = s.size();
        ll res = 0;
        for(int i = 0; i < len; i++){
            // 这一位不取s[i] 的答案
            if(s[i] != '0')
                res += (s[i] - '0') * power[len - i - 1] - 1;
        }//01
        return res;
    };
    cout << get(to_string(l)) << '\n';
    cout << get(to_string(r));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    // for(int i = 1; i <= 18; i++)
    //     cerr << (1LL<<i) << ",";
    while(T--)
        solve();
    return 0;
}