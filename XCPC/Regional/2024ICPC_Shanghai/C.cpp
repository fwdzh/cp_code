#include <bits/stdc++.h>
using namespace std;

void ChatGptDeepSeek() // Date: 2025-04-13
{                      // Time: 15:04:24
    // 2 3 4 5 6
    //
    int l, r;
    cin >> l >> r;
    if (l & 1)
    {
        if (r & 1)
            cout << "Alice\n";
        else
        {
            if (2 * l <= r)
                cout << "Alice\n";
            else
                cout << "Bob\n";
        }
    }
    else
    {
        if (r & 1)
        {
            cout << "Bob\n";
        }
        else
        {
            if ((l + 1) * 2 <= r)
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
    }
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