#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    LL sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int ans = 0;
    while(tx >= sx && ty >= sy){
        if(tx >= ty * 2){
            //毫无疑问 上次的 m = tx / 2
            if(tx & 1){
                cout << "-1\n";
                return 0;
            }
            tx >>= 1;
        }else if(ty >= tx * 2){
            if(ty & 1){
                cout << "-1\n";
                return 0;
            }
            ty >>= 1;
        }else if(tx >= ty){
            // 上次加的是 ty
            tx -= ty;
        }else{
            ty -= tx;
        }
        ans++;
    }
    cout << "-1\n";
    return 0;
}