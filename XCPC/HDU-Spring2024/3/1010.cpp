// Date: 2025-03-21
// Time: 19:00:01

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void ChatGptDeepSeek()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n);
    vector<int> a(4);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    /*
    在 [x,y] <= (a,b) 里
    找到最小的 (x+y)

    在 [x,y] >= (a,b) 里
    找最大的 (x+y) 
    
    要同时两个坐标都在某个范围内
    似乎很不好搞啊
    */
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