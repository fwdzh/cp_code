#include <bits/stdc++.h>
using namespace std;

void solve()
{
    /*
    1 + 1 2
    4 + 2 6
    9 + 3 12
    16 + 4 20
    25 + 5 30
    36 + 6 42
    49 + 7 54
    64 + 8 72
    81 + 9 90
    100 + 10 110
    121 + 11 132
    144 + 12 156

    */
    // vector<int> a(1001);
    // set<int> st;
    // map<int, int> mp;
    // for (int i = 1; i <= 1000; i++)
    //     a[i] = i * i + 1, mp[a[i]] = i;
    // st = set<int>(a.begin() + 1, a.end());
    // for(int i = 1; i <= 1000; i++){
    //     for(int j = i + 1; j <= 1000; j++){
    //         if(st.contains(a[i] * a[j])){
    //             cout << format("i : {}, j : {}, n : {}\n", i, j, mp[a[i] * a[j]]);
    //         }
    //     }
    // }
    int s, l, r;
    cin >> s >> l >> r;
    cout << r - l + 1 << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    solve();
    return 0;
}