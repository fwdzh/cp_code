#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-04-15
{                      // Time: 15:05:45
    int n;
    cin >> n;
    vector<char> s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    if (s[n] == '0' && s[n - 1] == '0')
    {
        cout << "Yes\n";
        return;
    }
    if (n == 3)
    {
        cout << "No\n";
        return;
    }
    for (int _ = 0; _ < 50; _++)
        for (int i = 1; i + 4 <= n; i++)
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0')
                swap(s[i + 1], s[i + 2]);

    /*
    11101111
    11011111

     */
    // if(s[n-3]=='0'&&s[n-2]=='1'&&n>4&&s[n-4]=='1')
    //     swap(s[n-3],s[n-2]);
    if (s[n - 2] == '1' && s[n - 3] == '1')
        cout << "Yes\n";
    else if (s[n - 3] == '1' && s[n - 2] == '0')
    {
        if (s[n - 1] == '0' && s[n] == '1')
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    else if (s[n - 3] == '0' && s[n - 2] == '0')
        cout << "No\n";
    else if (n > 4 && s[n - 4] == '1')
        cout << "Yes\n";
    else
        cout << "No\n";
    // 1110 ->1010->1100
    // 1101 ->1110->1110->1010->1100
    // 1111 ->1011->1101->1110->1110->1010->1100
    // 1010 ->1100
    // 1011 ->1101->1110->1110->1010->1100
    // 1001 x
    // 10101
    // 10110
    // 10101
    // 10110
    // 11010
    //
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