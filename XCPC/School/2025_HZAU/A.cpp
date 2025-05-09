#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(m + 1), r(m + 1), x(n + 1), y(n + 1);
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    for(int i = 1; i <= m; i++)
        cin >> r[i];
    vector<vector<int>> p(m + 1, vector<int>(n + 1));
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> p[i][j];
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= n; i++) cin >> y[i];
    vector<int>mx(m + 1);
    for(int i = 1; i <= m; i++)
        mx[i] = *max_element(p[i].begin() + 1, p[i].end());
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int get = min(100, x[i] / 60 + y[i]);
        vector<int> tmp;
        for(int j = 1; j <= m; j++){
            if(p[j][i] == -1)
                tmp.push_back(0);
            else if(p[j][i] == 0)
                tmp.push_back(b[j]);
            else
                tmp.push_back(b[j] + r[j] * p[j][i] / mx[j]);
        }
        sort(tmp.begin(), tmp.end(), greater<int>());
        int practice = 0;
        for(int j = 0; j < k; j++)
            practice += tmp[j];
        if(practice >= 50 * k && get >= 50 && (get >= 60 || practice >= k * 60))
            ans++;
        // cerr << practice << " " << get << '\n';
    }   
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}