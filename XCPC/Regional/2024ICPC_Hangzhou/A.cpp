// Date: 2025-03-29
// Time: 14:56:29
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if (s1.size() != s2.size())
    {
        cout << "NO\n";
        return;
    }
    if (s3.size() != s1.size())
    {
        cout << "YES\n";
        return;
    }
    vector<int> f(27);
    iota(f.begin(), f.end(), 0);
    auto find = [&](auto &&self, int x) -> int
    {
        return f[x] == x ? x : f[x] = self(self, f[x]);
    };
    for (int i = 0; i < s1.size(); i++)
    {
        int x = s1[i] - 'a' + 1;
        int y = s2[i] - 'a' + 1;
        f[find(find, x)] = find(find, y);
    }
    for (int i = 0; i < s3.size(); i++)
    {
        int x = s1[i] - 'a' + 1;
        int y = s3[i] - 'a' + 1;
        if (find(find, x) != find(find, y))
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
/*
ad
cc
ca
*/

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