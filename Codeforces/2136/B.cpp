#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve()
{
    int n, k; cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> a(n + 1);
    int j = n;
    for(int i = 1; i <= n; i++){
        if(s[i] == '0'){
            a[i] = j--;
        }
    }
    for(int i = 1; i <= n; i++){
        if(!a[i]) a[i] = j--;
    }
    vector<int> stk, L(n + 1, 0), R(n + 1, n + 1);
    for(int i = 1; i <= n; i++){
        while(stk.size() && a[i] > a[stk.back()])
            stk.pop_back();
        if(stk.size())
            L[i] = stk.back();
        stk.push_back(i);
    }
    stk.clear();
    for(int i = n; i >= 1; i--){
        while(stk.size() && a[i] > a[stk.back()])
            stk.pop_back();
        if(stk.size())
            R[i] = stk.back();
        stk.push_back(i);
        if(s[i] == '1' && R[i] - L[i] > k){
            cout << "NO\n";
            return;
            // break;
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t--)
    {solve();} return 0;
}
/*
5 2

*/