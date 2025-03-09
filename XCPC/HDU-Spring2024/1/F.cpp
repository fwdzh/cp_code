// Date: 2025-03-07
// Time: 18:38:35

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a(n, array<int, 3>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }
    // 123 132
    // 213 231
    // 312 321
    map<int, int> mp;
    auto work = [&](array<int, 3> x, int num) {
        vector<int> p { 0, 1, 2 };
        // map<int, int> nmp = mp;
        do {
            // ux+v=w
            // x=(w-v)/u
            int u = x[p[0]], v = x[p[1]], w = x[p[2]];
            if (((w - v) % u != 0) || (w - v) / u < 0)
                continue;
            int X = (w - v) / u;
            if (num && mp.contains(X)) {
                if (mp[X] == num + 1)
                    continue;
                if (mp[X] == num)
                    mp[X]++;
            } else {
                // nmp[X]=1;
                if (mp.contains(X))
                    continue;
                mp[X] = 1;
            }
            // cerr<<X<<" "<<nmp[X]<<'\n';
        } while (next_permutation(p.begin(), p.end()));
        // for (auto it = nmp.begin(); it != nmp.end(); it++) {
        //     // cerr<<it->first<<" "<<it->second<<"\n";
        //     if (it->second != num + 1) {
        //         nmp.erase(it);
        //     }
        // }
        // mp = nmp;
        // assert(mp.size()>0);
        map<int,int>nmp;
        for(auto [x,y]:mp){
            if(y!=num+1) continue;
            nmp[x]=y;
        }
        mp=nmp;
    };
    for (int i = 0; i < n; i++) {
        work(a[i], i);
        if (mp.size() == 1) {
            for (auto [x, y] : mp)
                cout << x << '\n';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}