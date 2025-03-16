// Date: 2025-03-14
// Time: 18:41:42

#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    // 当k大于26之后就没有意义了
    // 然后就是小于某个的长度最长是多少
    string s, t;
    cin >> s >> t;
    int k = 0;
    for (int i = 0; i < min(t.size(), size_t(3)); i++) {
        k = k * 10 + t[i] - '0';
    }
    // cerr<<k<<"\n";
    k = min(26, k);
    t = s;
    for (int i = 1; i < k; i++) {
        s += t;
    }
    // cerr<<s<<" "<<'\n';
    vector<int> len(26);
    for (auto x : s) {
        len[x - 'a'] = max(1, len[x - 'a']);
        for (int i = 0; i < x - 'a'; i++) {
            len[x - 'a'] = max(len[x - 'a'], len[i] + 1);
        }
        // cerr<<len[x-'a']<<' ';
    }
    cout << *max_element(len.begin(), len.end()) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}