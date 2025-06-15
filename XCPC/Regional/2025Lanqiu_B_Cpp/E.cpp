#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    if (c >= a + b || c >= min(a, b) + 2 || c > max(a, b) + 1) {
        cout << "-1\n";
        return 0;
    }
    if (a >= c - 1) {
        string m;
        int ed = c + (c % 2 == 0);
        for (int i = 1; i <= ed; i += 2) {
            if (i == ed && (c % 2 == 0)) {
                m += "QL";
            } else
                m += "LQ";
        }
        cout << string(a - (ed + 1) / 2, 'L') + m + string(b - (ed + 1) / 2, 'Q') << '\n';
    }else{
        string res;
        for(int i = 1; i <= c - 1; i++)
            res += "QL";
        res += string(b - c + 1, 'Q');
        cout << res << '\n';
    }
    return 0;
}