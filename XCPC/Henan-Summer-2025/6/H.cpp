#include<bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 100020;
int ch[N][26], v[N], tot;
void insert(string s)
{
    int u = 0;
    for(auto c : s){
        int x = c - 'a';
        if(!ch[u][x]) ch[u][x] = ++tot;
        u = ch[u][x];
    }
    v[u] = 1;
}
void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        insert(s);
    }
    vector<int> ans;
    int now = 0;
    string t; cin >> t;
    while(now < t.size()){
        int u = 0, lst = -1;
        for(int i = now; i < t.size(); i++){
            int x = t[i] - 'a';
            if(!ch[u][x]){
                break;
            }
            u = ch[u][x];
            if(v[u]) lst = i;
        }
        if(lst == -1){
            cout << t[now] << " ";
            now++;
        }else{
            for(int i = now; i <= lst; i++)
                cout << t[i];
            cout << " ";
            now = lst + 1;
        }
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}