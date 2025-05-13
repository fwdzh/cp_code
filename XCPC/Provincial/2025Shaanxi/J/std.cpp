#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    string s;
    cin >> k >> s;
    int n = s.size();

    string lose = "lose";
    vector<set<string>> st(4);
    for (int mask = 1; mask < (1 << 4) - 1; mask++) {
        string t;
        for (int i = 0; i < 4; i++) {
            if (mask >> i & 1) {
                t += lose[i];
            }
        }
        st[__builtin_popcount(mask)].insert(t);
    }

    int ans = 0;
    for (int i = 0; i + 4 <= n; i++) {
        if (s[i] != '$' && s.substr(i, 4) == lose) {
            for (int j = i; j < i + 4; j++) {
                s[j] = '$';
            }
            ans++;
        }
    }

    for (int l = 3; l > 0 && k > 0; l--) {
        for (int i = 0; i + l <= n && k > 0; i++) {
            if (s[i] != '$' && st[l].count(s.substr(i, l)) && k >= 4 - l) {
                for (int j = i; j < i + l; j++) {
                    s[j] = '$';
                }
                ans++, k -= 4 - l;
            }
        }
    }
    cout << ans + k / 4 << '\n';

    return 0;
}