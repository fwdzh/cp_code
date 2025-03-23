// 再也不敢用auto了
/*
ABCDCBA
ABCDDCBA
ACCDCCA
*/
// Date: 2025-03-22
// Time: 20:51:05
#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek()
{
    string s;
    cin >> s;
    int len = s.size(), lst = -1;
    string T(2 * s.size(), '@');
    for (int i = 0; i < len; i++)
        T[i] = s[i];
    for (int i = 0; i <= len - i - 1 && len - i - 1 < s.size() && i < s.size(); i++)
    {
        assert(len - i - 1 < s.size() && i < s.size());
        if (T[i] != T[len - i - 1]&&T[len-i-1]!='@')
        {
            // cerr << i << " " << len - i - 1 << '\n';
            len += i - lst;
            lst = i;
        }
    }
    if (lst == -1)
    {
        cout << s << '\n';
        return;
    }
    // ABCDECX
    // ABCDECXX
    // ABCDECXX
    // ABCDECXXXX
    //
    auto TLE = []()
    {
        for (int i = 0; i < 1e9; i++)
            i--;
    };
    // TLE();
    if (len > s.size() * 2)
        TLE();
    string t(len, '@');
    for (int i = 0; i < s.size(); i++)
        t[i] = s[i];
    for (int i = 0; i < len - i - 1; i++)
    {
        if (t[i] != t[len - i - 1])
        {
            if (len - i - 1 < s.size())
                TLE();
            t[len - i - 1] = t[i];
        }
    }
    if (count(t.begin(), t.end(), '@'))
        TLE();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i])
            TLE();
    }
    for (int i = 0; i < len - i - 1; i++)
    {
        if (t[i] != t[len - i - 1])
        {
            TLE();
        }
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