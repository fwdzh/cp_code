// Date: 2025-03-24
// Time: 00:59:38
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    string s;
    cin >> s;
    int len = s.size(), lst = -1;
    for (int i = 0; i < len - i - 1 && i < s.size() && len - i - 1 < s.size(); i++)
    {
        if (s[i] != s[len - i - 1])
        {
            len += i - lst;
            lst = i;
        }
    }
    string t = s;
    while (t.size() < len)
        t += "a";
    for (int i = 0; i < len - i - 1; i++)
    {
        if (t[i] != t[len - i - 1])
            t[len - i - 1] = t[i];
    }
    cout << t << '\n';
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