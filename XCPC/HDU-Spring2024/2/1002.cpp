// Date: 2025-03-14
// Time: 18:33:00

#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
void ChatGptDeepSeek()
{
    string s;
    cin >> s;
    cout << mp[s] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<string> s1 { "jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui" };
    vector<string> s2 { "zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai" };
    int x = 0, y = 0;
    for (int i = 1984; i <= 2043; i++) {
        mp[s1[x] + s2[y]] = i;
        x = (x + 1) % 10, y = (y + 1) % 12;
    }
    // cout << s1[x] << " " << s2[y] << '\n';
    int T = 1;
    cin >> T;
    while (T--)
        ChatGptDeepSeek();
    return 0;
}