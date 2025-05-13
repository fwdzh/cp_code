/*
gcd(a, b) = g
gcd(a / g, b / g) = 1

16 18

32 48
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int k;
    cin >> k;

    string s;
    cin >> s;
    int n = s.size();

    vector<bool> vis(n);
    int cnt[5] {0, 0, 0, 0, 0 };

    for (int i = 0; i + 3 < n; i++) {
        if (vis[i] || vis[i + 1] || vis[i + 2] || vis[i + 3])
            continue;

        if (s.substr(i, 4) == "lose") {
            cnt[4]++;

            vis[i] =
            vis[i + 1] = 
            vis[i + 2] = 
            vis[i + 3] = true;
        }
    }

    // lose
    for (int i = 0; i + 2 < n; i++) {

        if (vis[i] || vis[i + 1] || vis[i + 2])
            continue;

        string t = s.substr(i, 3);

        if (t == "los" || t == "ose" || t == "lse" || t == "loe") {
            cnt[3]++;

            vis[i] = 
            vis[i + 1] = 
            vis[i + 2] = true;
        }
    }

    // lose
    for (int i = 0; i + 1 < n; i++) {

        if (vis[i] || vis[i + 1])
            continue;

        string t = s.substr(i, 2);

        if (t == "lo" || t == "ls" || t == "le" || t == "os" || t == "oe" || t == "se") {
            cnt[2]++;

            vis[i] = 
            vis[i + 1] = true;
        }
    }

    for (int i = 0; i < n; i++) {

        if (vis[i])
            continue;

        if (s[i] == 'l' || s[i] == 'o' || s[i] == 's' || s[i] == 'e') {
            cnt[1]++;

            vis[i] = true;
        }
    }

    // cout << cnt[4] <<" " << cnt[3] <<" " <<cnt[2] <<" " << cnt[1] << '\n';
    int ans = cnt[4];

    for (int i = 3; i >= 1; i--) {
        if (k >= cnt[i] * (4 - i)) {
            k -= cnt[i] * (4 - i);
            ans += cnt[i];
        } else {
            ans += k / (4 - i);
            k %= (4 - i);
            // break;
        }
    }
    ans += k / 4;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
//68
//0 + 7 + 30