#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    LL x1, y1, z, x2, y2;
    cin >> x1 >> y1 >> z >> x2 >> y2;
    LL lo = 0, hi = 1e7;
    auto check = [&](LL cnt){
        LL num = (x1 + y2 - 1) / y2;
        LL t = 0, hp = x2;
        for(int r = 0; ;r++){
            cnt -= 3 / num;
            for(int j = 1; j <= 3 % num; j++){
                t++;
                if(t == num) cnt--;
                t %= num;
            }
            if(cnt < 0) return false;
            hp -= cnt * (y1 + r * z);
            if(hp <= 0) return true;
        }

    };
    while(lo < hi - 1){
        LL mid = (lo + hi) >> 1;
        if(check(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
    return 0;
}