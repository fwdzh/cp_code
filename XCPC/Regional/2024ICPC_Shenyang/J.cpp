#include<bits/stdc++.h>
using namespace std;
// created: 2025-09-19 16:34:06
struct node{
    string s;
    int x;
};
void solve(){
    vector<node> a(8);
    for(int i = 0; i < 8; i++)
        cin >> a[i].s >> a[i].x;
    while(a.size() > 2){
        vector<node> b;
        for(int i = 0; i < a.size(); i += 2){
            if(a[i].x > a[i + 1].x) b.push_back(a[i]);
            else b.push_back(a[i + 1]);
        }
        a = b;
    }
    if(a[0].x < a[1].x) swap(a[0], a[1]);
    cout << a[0].s << " beats " << a[1].s << "\n";
}
int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin >> t; while(t--)
    {solve();} return 0;
}