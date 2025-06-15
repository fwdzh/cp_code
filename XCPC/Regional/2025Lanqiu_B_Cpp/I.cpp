#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> nxt(n + 1, n + 1), idx(26, n + 1);
    for(int i = n; i >= 1; i--){
        idx[s[i] - 'a'] = i;
        for(int j = 0; j < 26; j++){
            if(j == s[i] - 'a') continue;
            nxt[i] = min(nxt[i], idx[j]);
        }
    }
    vector<bool> vis(26);
    auto get = [&](int l, int r){
        vis.assign(26, false);
        string res;
        res.push_back(s[l]);
        vis[s[l] - 'a'] = true;
        while(nxt[l] <= r){
            l = nxt[l];
            if(!vis[s[l] - 'a']){
                res.push_back(s[l]);
                vis[s[l] - 'a'] = true;
            }
            // cerr << l << '\n';
        }
        
        return res;
    };
    int q;
    cin >> q;
    while(q--){
        int la, ra, lb, rb;
        cin >> la >> ra >> lb >> rb;
        string s1 = get(la, ra), s2 = get(lb, rb);
        if(s1.size() > s2.size()) swap(s1, s2);
        int ans = s2.size() - s1.size();
        for(int i = 0; i < s1.size(); i++)
            if(s1[i] != s2[i]) ans++;
        cout << ans << '\n';
    }
    return 0;
}