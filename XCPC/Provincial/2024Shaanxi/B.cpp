// Date: 2025-03-10
// Time: 16:38:48

#include <bits/stdc++.h>
// #include "C:/usr/codes/cp/template/debug.hpp"
using namespace std;

void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n, string(m, '1'));

    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < m - 1; j++) {
            if (s[i - 1][j] == '1' && s[i + 1][j] == '1' && s[i][j - 1] == '1' && s[i][j + 1] == '1')
                s[i][j] = '*';
        }
    vector<int> r(n), c(m);
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m; j++) {
            if (s[i][j] == s[i][j - 1])
                r[i]++;
        }
    }
    for (int j = 1; j < m - 1; j++) {
        for (int i = 1; i < n; i++) {
            if (s[i][j] == s[i - 1][j])
                c[j]++;
        }
    }
    for (int i = 2, j = 2; i < n; i += 2) {
        if (s[i][j] == '*' && (r[i] == 2 || c[j] == 2)) {
            r[i] = 0, c[j] = 0;
            // cerr<<i<<" "<<j<<'\n';
            s[i][j] = '+';
            if (j + 2 < m - 1) {
                j += 2;
            }

            // dbg(r);
            // dbg(c);
        }
    }
    for (int j = 2, i = 2; j < m; j += 2) {
        // if(c[j]) cerr<<j<<'\n';
        // dbg(r);
        // dbg(c);
        if (s[i][j] == '*' && (r[i] == 2 || c[j] == 2)) {
            // cerr << i << " " << j << '\n';
            s[i][j] = '+';
            if (i + 2 < n - 1)
                i += 2;
            r[i] = 0, c[j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
        cout << s[i] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}